#include "mnblas.h"
#include "complexe.h"
#include "math.h"

CBLAS_INDEX mnblas_isamax(const int N, const float *X, const int incX) {
  register CBLAS_INDEX index_max;
  register float max;
  if (N <= 0) {
    return 0;
  } else {
    index_max = 0;
    max = X[0];
  }
  for (register unsigned int i = 1; i < N; i += incX) {
    if (X[i] > max) {
      max = X[i];
      index_max = i;
    }
  }
  return index_max;
}

CBLAS_INDEX mnblas_idamax(const int N, const double *X, const int incX) {
  register CBLAS_INDEX index_max;
  register double max;
  if (N <= 0) {
    return 0;
  } else {
    index_max = 0;
    max = X[0];
  }
  for (register unsigned int i = 1; i < N; i += incX) {
    if (X[i] > max) {
      max = X[i];
      index_max = i;
    }
  }
  return index_max;
}

CBLAS_INDEX mnblas_icamax(const int N, const void *X, const int incX) {
  register CBLAS_INDEX index_max;
  register float max, tmp;
  complexe_float_t *PX = (complexe_float_t *) X;


  if (N <= 0) {
    return 0;
  } else {
    index_max = 0;
    max = fabsf(PX->real + PX->imaginary);
  }
  for (register unsigned int i = 1; i < N; i += incX) {
    tmp = fabsf(PX[i].real + PX[i].imaginary);

    if (tmp > max) {
      max = tmp;
      index_max = i;
    }
  }
  return index_max;
}

CBLAS_INDEX mnblas_izamax(const int N, const void *X, const int incX) {
  register CBLAS_INDEX index_max;
  register double max, tmp;
  complexe_double_t *PX = (complexe_double_t *) X;

  if (N <= 0) {
    return 0;
  } else {
    index_max = 0;
    max = fabs(PX->real + PX->imaginary);
  }
  for (register unsigned int i = 1; i < N; i += incX) {
    tmp = fabs(PX[i].real + PX[i].imaginary);

    if (tmp > max) {
      max = tmp;
      index_max = i;
    }
  }
  return index_max;
}


