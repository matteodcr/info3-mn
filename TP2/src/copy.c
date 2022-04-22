#include "mnblas.h"
#include "complexe2.h"

void mncblas_scopy(const int N, const float *X, const int incX,
                   float *Y, const int incY) {
  register unsigned int i = 0;
  register unsigned int j = 0;

  for (; ((i < N) && (j < N)); i += incX, j += incY) {
    Y[j] = X[i];
  }
}

void mncblas_dcopy(const int N, const double *X, const int incX,
                   double *Y, const int incY) {
  register unsigned int i = 0;
  register unsigned int j = 0;

  for (; ((i < N) && (j < N)); i += incX, j += incY) {
    Y[j] = X[i];
  }
}

void mncblas_ccopy(const int N, const void *X, const int incX,
                   void *Y, const int incY) {
  register unsigned int i = 0;
  register unsigned int j = 0;

  complexe_float_t *PX = (complexe_float_t *) X;
  complexe_float_t *PY = (complexe_float_t *) Y;

  for (; ((i < N) && (j < N)); i += incX, j += incY) {
    PY[j] = PX[i];
  }
}

void mncblas_zcopy(const int N, const void *X, const int incX,
                   void *Y, const int incY) {
  register unsigned int i = 0;
  register unsigned int j = 0;
  complexe_double_t *PX = (complexe_double_t *) X;
  complexe_double_t *PY = (complexe_double_t *) Y;

  for (; ((i < N) && (j < N)); i += incX, j += incY) {
    PY[j] = PX[i];
  }
}

