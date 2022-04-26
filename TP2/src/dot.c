#include "mnblas.h"
#include "complexe2.h"


float mncblas_sdot(const int N, const float *X, const int incX,
                   const float *Y, const int incY) {
  unsigned int max = (N / incX);

  register float dot = 0;
#pragma omp parallel for reduction(+:dot)
  for (unsigned int k = 0; k < max; k++) {
    dot += X[k * incX] * Y[k * incY];
  }

  return dot;
}

double mncblas_ddot(const int N, const double *X, const int incX,
                    const double *Y, const int incY) {
  unsigned int max = (N / incX);

  register double dot = 0.0;
#pragma omp parallel for reduction(+:dot)
  for (unsigned int k = 0; k < max; k++) {
    dot += X[k * incX] * Y[k * incY];
  }

  return dot;
}

void mncblas_cdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu) {
  unsigned int max = (N / incX);

  complexe_float_t *PX = (complexe_float_t *) X;
  complexe_float_t *PY = (complexe_float_t *) Y;

  register complexe_float_t dot = { .real = 0, .imaginary = 0 };
#pragma omp parallel for
  for (unsigned int k = 0; k < max; k++) {
    unsigned int i = k * incX, j = k * incY;
    complexe_float_t t = mult_complexe_float(PX[i], PY[j]);
#pragma omp atomic
    dot.real += t.real;
#pragma omp atomic
    dot.imaginary += t.imaginary;
  }
  *(complexe_float_t *) dotu = dot;
}

void mncblas_cdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc) {
  unsigned int max = (N / incX);

  complexe_float_t *PX = (complexe_float_t *) X;
  complexe_float_t *PY = (complexe_float_t *) Y;

  register complexe_float_t dot = { .real = 0, .imaginary = 0 };
#pragma omp parallel for reduction(+:dot)
  for (unsigned int k = 0; k < max; k++) {
    unsigned int i = k * incX, j = k * incY;
    PX[i].imaginary *= -1;
    complexe_float_t t = mult_complexe_float(PX[i], PY[j]);
#pragma omp atomic
    dot.real += t.real;
#pragma omp atomic
    dot.imaginary += t.imaginary;
  }
  *(complexe_float_t *) dotc = dot;
}

void mncblas_zdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu) {
  unsigned int max = (N / incX);

  complexe_double_t *PX = (complexe_double_t *) X;
  complexe_double_t *PY = (complexe_double_t *) Y;

  register complexe_double_t dot = { .real = 0, .imaginary = 0 };
#pragma omp parallel for
  for (unsigned int k = 0; k < max; k++) {
    unsigned int i = k * incX, j = k * incY;
    complexe_double_t t = mult_complexe_double(PX[i], PY[j]);
#pragma omp atomic
    dot.real += t.real;
#pragma omp atomic
    dot.imaginary += t.imaginary;
  }
  *(complexe_double_t *) dotu = dot;
}

void mncblas_zdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc) {
  unsigned int max = (N / incX);

  complexe_double_t *PX = (complexe_double_t *) X;
  complexe_double_t *PY = (complexe_double_t *) Y;

  register complexe_double_t dot = { .real = 0, .imaginary = 0 };
#pragma omp parallel for
  for (unsigned int k = 0; k < max; k++) {
    unsigned int i = k * incX, j = k * incY;
    ((complexe_double_t *) X + i)->imaginary *= -1;
    complexe_double_t t = mult_complexe_double(PX[i], PY[j]);
#pragma omp atomic
    dot.real += t.real;
#pragma omp atomic
    dot.imaginary += t.imaginary;
  }
  *(complexe_double_t *) dotc = dot;
}




