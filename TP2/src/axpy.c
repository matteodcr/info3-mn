#include "mnblas.h"
#include "complexe2.h"

void mnblas_saxpy(const int N, const float alpha, const float *X, const int incX, float *Y,
                  const int incY) {
#pragma omp parallel for
  for (int k = 0; k < N; k++) {
    unsigned int i = k * incX;
    unsigned int j = k * incY;
    Y[j] += alpha * X[i];
  }
}

void mnblas_daxpy(const int N, const double alpha, const double *X, const int incX, double *Y,
                  const int incY) {
//#pragma omp parallel for
  for (int k = 0; k < N; k++) {
    unsigned int i = k * incX;
    unsigned int j = k * incY;
    Y[j] += alpha * X[i];
  }
}

void mnblas_caxpy(const int N, const void *alpha, const void *X, const int incX, void *Y,
                  const int incY) {
  complexe_float_t *PX = (complexe_float_t *) X;
  complexe_float_t *PY = (complexe_float_t *) Y;
//#pragma omp parallel for
  for (int k = 0; k < N; k++) {
    unsigned int i = k * incX;
    unsigned int j = k * incY;
    PY[j] = mult_complexe_float(*(complexe_float_t *) alpha, PX[i]);
  }
}

void mnblas_zaxpy(const int N, const void *alpha, const void *X, const int incX, void *Y,
                  const int incY) {
  complexe_float_t *PX = (complexe_float_t *) X;
  complexe_float_t *PY = (complexe_float_t *) Y;
//#pragma omp parallel for
  for (int k = 0; k < N; k++) {
    unsigned int i = k * incX;
    unsigned int j = k * incY;
    PY[j] = mult_complexe_float(*(complexe_float_t *) alpha, PX[i]);
  }
}