#include "mnblas.h"
#include "complexe.h"
#include "math.h"

float mnblas_sasum(const int N, const float *X, const int incX) {
  register unsigned int i = 0;
  register float sum = 0;
  for (; i < N; i += incX) {
    sum += fabsf(X[i]);
  }
  return sum;
}

double mnblas_dasum(const int N, const double *X, const int incX) {
  register double sum = 0;
  register unsigned int i = 0;
  for (; i < N; i += incX) {
    sum += fabs(X[i]);
  }
  return sum;
}

float mnblas_scasum(const int N, const void *X, const int incX) {
  register unsigned int i = 0;
  register float sum = 0;
  complexe_float_t *PX = (complexe_float_t *) X;
  for (; i < N; i += incX) {
    sum += fabsf(PX[i].real) + fabsf(PX[i].imaginary);
  }
  return sum;
}

double mnblas_dzasum(const int N, const void *X, const int incX) {
  register unsigned int i = 0;
  register double sum = 0;
  complexe_double_t *PX = (complexe_double_t *) X;
  for (; i < N; i += incX) {
    sum += fabs(PX[i].real) + fabs(PX[i].imaginary);
  }
  return sum;
}


