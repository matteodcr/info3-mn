#include "mnblas.h"
#include "complexe.h"
#include "math.h"

CBLAS_INDEX mnblas_isamin(const int N, const float *X, const int incX) {
  register CBLAS_INDEX index_min;
  register float min;
  if (N <= 0) {
    return 0;
  } else {
    index_min = 0;
    min = X[0];
  }
  for (register unsigned int i = 1; i < N; i += incX) {
    if (X[i] < min) {
      min = X[i];
      index_min = i;
    }
  }
  return index_min;
}

CBLAS_INDEX mnblas_idamin(const int N, const double *X, const int incX) {
  register CBLAS_INDEX index_min;
  register double min;
  if (N <= 0) {
    return 0;
  } else {
    index_min = 0;
    min = X[0];
  }
  for (register unsigned int i = 1; i < N; i += incX) {
    if (X[i] < min) {
      min = X[i];
      index_min = i;
    }
  }
  return index_min;
}

CBLAS_INDEX mnblas_icamin(const int N, const void *X, const int incX) {
  register CBLAS_INDEX index_min;
  register float min, tmp;
  complexe_float_t *PX = (complexe_float_t *) X;


  if (N <= 0) {
    return 0;
  } else {
    index_min = 0;
    min = fabsf(PX->real + PX->imaginary);
  }
  for (register unsigned int i = 1; i < N; i += incX) {
    tmp = fabsf(PX[i].real + PX[i].imaginary);

    if (tmp < min) {
      min = tmp;
      index_min = i;
    }
  }
  return index_min;
}

CBLAS_INDEX mnblas_izamin(const int N, const void *X, const int incX) {
  register CBLAS_INDEX index_min;
  register double min, tmp;

  complexe_double_t *PX = (complexe_double_t *) X;

  if (N <= 0) {
    return 0;
  } else {
    index_min = 0;
    min = fabs(PX->real + PX->imaginary);
  }
  for (register unsigned int i = 1; i < N; i += incX) {
    tmp = fabs(PX[i].real + PX[i].imaginary);
    if (tmp < min) {
      min = tmp;
      index_min = i;
    }
  }
  return index_min;
}
