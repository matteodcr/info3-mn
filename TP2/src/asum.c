#include "mnblas.h"
#include "complexe.h"

float val_abs_float(float x) {
  return x <= 0 ? -x : x;
}

double val_abs_double(double x) {
  return x <= 0 ? -x : x;
}

float mnblas_sasum(const int N, const float *X, const int incX) {
  register unsigned int i = 0;
  register float sum = 0;
  for (; i < N; i += incX) {
    sum += val_abs_float(X[i]);
  }
  return sum;
}

double mnblas_dasum(const int N, const double *X, const int incX) {
  register double sum = 0;
  register unsigned int i = 0;
  for (; i < N; i += incX) {
    sum += val_abs_double(X[i]);
  }
  return sum;
}

float mnblas_scasum(const int N, const void *X, const int incX) {
  register unsigned int i = 0;
  register float sum = 0;
  complexe_float_t *PX = (complexe_float_t *) X;
  for (; i < N; i += incX) {
    sum += val_abs_float(PX[i].real) + (PX[i].imaginary);
  }
  return sum;
}

double mnblas_dzasum(const int N, const void *X, const int incX) {
  register unsigned int i = 0;
  register double sum = 0;
  complexe_double_t *PX = (complexe_double_t *) X;
  for (; i < N; i += incX) {
    sum += val_abs_double(PX[i].real) + (PX[i].imaginary);
  }
  return sum;
}


