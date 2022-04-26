#include "mnblas.h"
#include "complexe.h"

void mncblas_sgemv(const MNCBLAS_LAYOUT layout,
                   const MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                   const float alpha, const float *A, const int lda,
                   const float *X, const int incX, const float beta,
                   float *Y, const int incY) {
  register unsigned int i;
  register unsigned int j;
  register float save;

  bool trans = (layout == MNCblasColMajor);
  bool trans_a = trans ^ (TransA > MNCblasNoTrans);

  for (i = 0; i < M; i += incX) {
    save = beta * Y[i];
    for (j = 0; j < N; j += incY) {
      save += alpha * *MAT_Y_X(float, A, M, N, i, j, trans_a) * X[j];
    }
    Y[i] = save;
  }

}

void mncblas_dgemv(MNCBLAS_LAYOUT layout,
                   MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                   const double alpha, const double *A, const int lda,
                   const double *X, const int incX, const double beta,
                   double *Y, const int incY) {
  register unsigned int i;
  register unsigned int j;
  register double save;

  bool trans = (layout == MNCblasColMajor);
  bool trans_a = trans ^ (TransA > MNCblasNoTrans);

  for (i = 0; i < M; i += incX) {
    save = beta * Y[i];
    for (j = 0; j < N; j += incY) {
      save += alpha * *MAT_Y_X(double, A, M, N, i, j, trans_a) * X[j];
    }
    Y[i] = save;
  }
}

void mncblas_cgemv(MNCBLAS_LAYOUT layout,
                   MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                   const void *alpha, const void *A, const int lda,
                   const void *X, const int incX, const void *beta,
                   void *Y, const int incY) {
  register unsigned int i;
  register unsigned int j;
  register complexe_float_t save;

  bool trans = (layout == MNCblasColMajor);
  bool trans_a = trans ^ (TransA > MNCblasNoTrans);

  // cast
  complexe_float_t *Palpha = (complexe_float_t *) alpha;
  complexe_float_t *Pbeta = (complexe_float_t *) beta;
  complexe_float_t *PX = (complexe_float_t *) X;
  complexe_float_t *PY = (complexe_float_t *) Y;
  complexe_float_t *PA = (complexe_float_t *) A;

  // y := alpha*A*x + beta*y
  for (i = 0; i < M; i += incX) {
    // beta*y
    save = mult_complexe_float(*Pbeta, PY[i]);
    for (j = 0; j < N; j += incY) {
      // alpha*A*x
      save = add_complexe_float(save, mult_complexe_float(
              mult_complexe_float(*Palpha, *MAT_Y_X(complexe_float_t, PA, M, N, i, j, trans_a)),
              PX[j]));
    }
    PY[i] = save;
  }
}

void mncblas_zgemv(MNCBLAS_LAYOUT layout,
                   MNCBLAS_TRANSPOSE TransA, const int M, const int N,
                   const void *alpha, const void *A, const int lda,
                   const void *X, const int incX, const void *beta,
                   void *Y, const int incY) {
  register unsigned int i;
  register unsigned int j;
  register complexe_double_t save;

  bool trans = (layout == MNCblasColMajor);
  bool trans_a = trans ^ (TransA > MNCblasNoTrans);

  // cast
  complexe_double_t *Palpha = (complexe_double_t *) alpha;
  complexe_double_t *Pbeta = (complexe_double_t *) beta;
  complexe_double_t *PX = (complexe_double_t *) X;
  complexe_double_t *PY = (complexe_double_t *) Y;
  complexe_double_t *PA = (complexe_double_t *) A;

// y := alpha*A*x + beta*y
  for (i = 0; i < M; i += incX) {
    // beta*y
    save = mult_complexe_double(*Pbeta, PY[i]);
    for (j = 0; j < N; j += incY) {
      // alpha*A*x
      save = add_complexe_double(save,
                                 mult_complexe_double(
                                         mult_complexe_double(*Palpha, *MAT_Y_X(complexe_double_t, PA, M, N, i, j, trans_a)),
                                         PX[j]));
    }
    PY[i] = save;
  }
}
