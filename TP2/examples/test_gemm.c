#include <stdio.h>
#include <assert.h>
#include "flop.h"

#ifndef MNBLAS_H
#define MNBLAS_H

#include "mnblas.h"

#endif

#ifndef COMPEXE_H
#define COMPEXE_H

#include "complexe.h"

#endif

#ifndef TESTUILS_H
#define TESTUILS_H

#include "utils.h"

#endif

#define NB_FOIS 10
#define SIZE 256

int main() {
  float *A = init_vec_float(12);
  float *B = init_vec_float(12);
  float *C = init_vec_float(9);

  fill_vec_float(A, 12, 1);
  fill_vec_float(B, 12, 1);

  float alphaf = 2.0;
  mncblas_sgemm(MNCblasRowMajor, MNCblasNoTrans, MNCblasNoTrans, 3, 3, 4, alphaf, A, 0, B, 0, 0, C, 0);
  assert(C[0] == 140.0 && C[7] == 576.0);

  /// Doubles

  double MatD[2] = {1, 2};
  double C2[1], C3[4];

  mncblas_dgemm(MNCblasRowMajor, MNCblasNoTrans, MNCblasTrans, 1, 1, 2, 1.0, MatD, 0, MatD, 0, 0, C2, 0);
  assert(C2[0] == 5.0);

  mncblas_dgemm(MNCblasRowMajor, MNCblasTrans, MNCblasNoTrans, 2, 2, 1, 1.0, MatD, 0, MatD, 0, 0, C3, 0);
  assert(C3[0] == 1.0 && C3[1] == 2.0 && C3[2] == 2.0 && C3[3] == 4.0);

  // Complexe float

  complexe_float_t MatC[2] = {{0, 1},
                              {2, 3}};
  complexe_float_t C4[1];

  mncblas_cgemm(MNCblasRowMajor, MNCblasNoTrans, MNCblasTrans, 1, 1, 2, &(complexe_float_t) {1, 0}, MatC, 0, MatC, 0,
                &(complexe_float_t) {0, 0}, C4, 0);
  // Complexe double

  complexe_double_t MatCD[2] = {{0, 1},
                                {2, 3}};
  complexe_double_t C5[1];

  mncblas_cgemm(MNCblasRowMajor, MNCblasNoTrans, MNCblasConjTrans, 1, 1, 2, &(complexe_double_t) {1, 0}, MatCD, 0,
                MatCD, 0, &(complexe_double_t) {0, 0}, C5, 0);
  print_mat_cd(C5, 1, 1);

  printf("Les assertions sont vérifiées\n");
  u_int64_t i;
  struct timespec start_spec, end_spec;

  printf("FLOAT ==========================================================\n");

  init_flop_nano();

  float *matA = malloc(SIZE * SIZE * sizeof(float));
  fill_vec_float(matA, SIZE * SIZE, 1.0f);
  float *matB = malloc(SIZE * SIZE * sizeof(float));
  fill_vec_float(matB, SIZE * SIZE, 1.0f);
  float *matF_r = malloc(SIZE * SIZE * sizeof(float));

  for (i = 0; i < NB_FOIS; i++) {
    TOP_NANO(start_spec)
    mncblas_sgemm(MNCblasRowMajor, MNCblasNoTrans, MNCblasNoTrans, SIZE, SIZE, SIZE, 1.0f, matA, 0, matB, 1, 0.0f,
                  matF_r, 1);
    TOP_NANO(end_spec)

    calcul_flop_nano("sdot nano ", SIZE * SIZE, tdiff_nano(&start_spec, &end_spec));
  }
  printf("DOUBLE ==========================================================\n");

  init_flop_nano();

  double *matC = malloc(SIZE * SIZE * sizeof(double));
  fill_vec_double(matC, SIZE * SIZE, 1.0);
  double *matD = malloc(SIZE * SIZE * sizeof(double));
  fill_vec_double(matD, SIZE * SIZE, 1.0);
  double *matD_r = malloc(SIZE * SIZE * sizeof(double));

  for (i = 0; i < NB_FOIS; i++) {
    TOP_NANO(start_spec)
    mncblas_dgemm(MNCblasRowMajor, MNCblasNoTrans, MNCblasNoTrans, SIZE, SIZE, SIZE, 1.0f, matC, 0, matD, 1, 0.0f,
                  matD_r, 1);
    TOP_NANO(end_spec)

    calcul_flop_nano("sdot nano ", SIZE * SIZE, tdiff_nano(&start_spec, &end_spec));
  }
  printf("==========================================================\n");

  init_flop_nano();

  complexe_float_t *matE = malloc(SIZE * SIZE * sizeof(complexe_float_t));
  fill_vec_complexe_float(matE, SIZE * SIZE, 1, 0);
  complexe_float_t *matF = malloc(SIZE * SIZE * sizeof(complexe_float_t));
  fill_vec_complexe_float(matF, SIZE * SIZE, 1, 0);
  complexe_float_t *matC_r = malloc(SIZE * SIZE * sizeof(complexe_float_t));

  for (i = 0; i < NB_FOIS; i++) {
    TOP_NANO(start_spec)
    mncblas_cgemm(MNCblasRowMajor, MNCblasNoTrans, MNCblasNoTrans, SIZE, SIZE, SIZE,
                  &(complexe_float_t) {.real = 1, .imaginary = 1}, matE, 0, matF, 1,
                  &(complexe_float_t) {.real = 0, .imaginary = 0},
                  matC_r, 1);
    TOP_NANO(end_spec)

    calcul_flop_nano("sdot nano ", 2 * SIZE * SIZE, tdiff_nano(&start_spec, &end_spec));
  }
  printf("==========================================================\n");

  init_flop_nano();

  complexe_double_t *matG = malloc(SIZE * SIZE * sizeof(complexe_double_t));
  fill_vec_complexe_double(matG, SIZE * SIZE, 1, 0);
  complexe_double_t *matH = malloc(SIZE * SIZE * sizeof(complexe_double_t));
  fill_vec_complexe_double(matH, SIZE * SIZE, 1, 0);
  complexe_double_t *matZ_r = malloc(SIZE * SIZE * sizeof(complexe_double_t));

  for (i = 0; i < NB_FOIS; i++) {
    TOP_NANO(start_spec)
    mncblas_zgemm(MNCblasRowMajor, MNCblasNoTrans, MNCblasNoTrans, SIZE, SIZE, SIZE,
                  &(complexe_double_t) {.real = 1, .imaginary = 1}, matG, 0, matH, 1,
                  &(complexe_double_t) {.real = 0, .imaginary = 0},
                  matZ_r, 1);
    TOP_NANO(end_spec)

    calcul_flop_nano("sdot nano ", 2 * SIZE * SIZE, tdiff_nano(&start_spec, &end_spec));
  }
  return 0;
}
