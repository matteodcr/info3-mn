#include "mnblas.h"
#include "complexe2.h"


float mncblas_sdot(const int N, const float *X, const int incX,
                   const float *Y, const int incY) {
  register unsigned int i = 0;
  register unsigned int j = 0;
  register float dot = 0;


  for (; i < N; i += incX, j += incY) {
    dot += X[i] * Y[j];
  }

  return dot;
}

double mncblas_ddot(const int N, const double *X, const int incX,
                    const double *Y, const int incY) {
  register unsigned int i = 0;
  register unsigned int j = 0;
  register double dot = 0.0;


  for (; i < N; i += incX, j += incY) {
    dot += X[i] * Y[j];
  }
  return dot;
}

void mncblas_cdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu) {
  register unsigned int i = 0;
  register unsigned int j = 0;
  register complexe_float_t dot;
  dot.real = 0;
  dot.imaginary = 0;

  complexe_float_t *PX = (complexe_float_t *) X;
  complexe_float_t *PY = (complexe_float_t *) Y;

  for (; i < N; i += incX, j += incY) {
    dot = add_complexe_float(dot, mult_complexe_float(PX[i], PY[j]));
  }
  *(complexe_float_t *) dotu = dot;
}

void mncblas_cdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc) {
  register unsigned int i = 0;
  register unsigned int j = 0;
  register complexe_float_t dot;
  dot.real = 0;
  dot.imaginary = 0;

  complexe_float_t *PX = (complexe_float_t *) X;
  complexe_float_t *PY = (complexe_float_t *) Y;

  for (; i < N; i += incX, j += incY) {
    PX[i].imaginary *= -1;
    dot = add_complexe_float(dot, mult_complexe_float(PX[i], PY[j]));
  }
  *(complexe_float_t *) dotc = dot;
}

void mncblas_zdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu) {
  register unsigned int i = 0;
  register unsigned int j = 0;
  register complexe_double_t dot;
  dot.real = 0;
  dot.imaginary = 0;

  complexe_double_t *PX = (complexe_double_t *) X;
  complexe_double_t *PY = (complexe_double_t *) Y;

  for (; i < N; i += incX, j += incY) {
    PX[i].imaginary *= -1;
    dot = add_complexe_double(dot, mult_complexe_double(PX[i], PY[j]));
  }
  *(complexe_double_t *) dotu = dot;
}

void mncblas_zdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc) {
  register unsigned int i = 0;
  register unsigned int j = 0;
  register complexe_double_t dot;
  dot.real = 0;
  dot.imaginary = 0;

  complexe_double_t *PX = (complexe_double_t *) X;
  complexe_double_t *PY = (complexe_double_t *) Y;

  for (; i < N; i += incX, j += incY) {
    ((complexe_double_t *) X + i)->imaginary *= -1;
    dot = add_complexe_double(dot, mult_complexe_double(PX[i], PY[j]));
  }
  *(complexe_double_t *) dotc = dot;
}




