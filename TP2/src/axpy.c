#include "mnblas.h"
#include "complexe2.h"

void mnblas_saxpy(const int N, const float alpha, const float *X, const int incX, float *Y,
                  const int incY) {
  register unsigned int i = 0;
  register unsigned int j = 0;
  for (; i < N; i += incX, j += incY) {
    Y[j] += alpha * X[i];
  }
}

void mnblas_daxpy(const int N, const double alpha, const double *X, const int incX, double *Y,
                  const int incY) {
  register unsigned int i = 0;
  register unsigned int j = 0;

  for (; i < N; i += incX, j += incY) {
    Y[j] += alpha * X[i];
  }
}

void mnblas_caxpy(const int N, const void *alpha, const void *X, const int incX, void *Y,
                  const int incY) {
  register unsigned int i = 0;
  register unsigned int j = 0;
  complexe_float_t *PX = (complexe_float_t *) X;
  complexe_float_t *PY = (complexe_float_t *) Y;
  for (; ((i < N) && (j < N)); i += incX, j += incY) {
    PY[j] = mult_complexe_float(*(complexe_float_t *) alpha, PX[i]);
  }
}

void mnblas_zaxpy(const int N, const void *alpha, const void *X, const int incX, void *Y,
                  const int incY) {
  register unsigned int i = 0;
  register unsigned int j = 0;
  complexe_double_t *PX = (complexe_double_t *) X;
  complexe_double_t *PY = (complexe_double_t *) Y;
  for (; ((i < N) && (j < N)); i += incX, j += incY) {
    PY[j] = mult_complexe_double(*(complexe_double_t *) alpha, PX[i]);
  }
}