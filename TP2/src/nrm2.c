#include "mnblas.h"
#include "complexe.h"
#include <math.h>

float mnblas_snrm2(const int N, const float *X, const int incX) { // NB OPE FLOTANTE = 2*N + 1 (pour sqrf)
  register float sum = 0;
#pragma omp parallel for reduction(+:sum)
  for (register unsigned int i = 0; i < N; i += incX) {
    sum += X[i] * X[i];
  }
  return sqrtf(sum);
}

double mnblas_dnrm2(const int N, const double *X, const int incX) { // NB OPE FLOTANTE = 2*N + 1 (pour sqrf)
  register double sum = 0;
#pragma omp parallel for reduction(+:sum)
  for (register unsigned int i = 0; i < N; i += incX) {
    sum += X[i] * X[i];
  }
  return sqrt(sum);
}

float mnblas_scnrm2(const int N, const void *X, const int incX) { // NB OPE FLOTANTE = 4*N + 1 (pour sqrf)
  register float sum = 0;
#pragma omp parallel for reduction(+:sum)
  complexe_float_t *PX = (complexe_float_t *) X;
  for (register unsigned int i = 0; i < N; i += incX) {
    sum += PX[i].real * PX[i].real + PX[i].imaginary * PX[i].imaginary;
  }
  return sqrtf(sum);
}

double mnblas_dznrm2(const int N, const void *X, const int incX) { // NB OPE FLOTANTE = 4*N + 1 (pour sqrf)
  register double sum = 0;
#pragma omp parallel for reduction(+:sum)
  complexe_double_t *PX = (complexe_double_t *) X;
  for (register unsigned int i = 0; i < N; i += incX) {
    sum += PX[i].real * PX[i].real + PX[i].imaginary * PX[i].imaginary;
  }
  return sqrt(sum);
}