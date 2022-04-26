#include <stdio.h>
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

#define NB_FOIS 1024
#define SIZE 256


int main(int argc, char **argv) {
  // dimension
  int M = 3;
  int N = 4;

  float *mat_float = init_vec_float(12);
  float *vec_floatA = init_vec_float(4);
  float *vec_floatB = init_vec_float(3);

  fill_vec_float(mat_float, 12, 1);
  fill_vec_float(vec_floatA, 4, 1);
  fill_vec_float(vec_floatB, 3, 1);

  float alphaf = 2.0;
  float betaf = 2.0;

  printf("\nFLOAT\n\n");
  printf("==AVANT==\n");
  printf("MATRICE\n");
  print_mat_f(mat_float, 12, 4);
  printf("VEC A\n");
  print_vec_f(vec_floatA, 4);
  printf("VEC B\n");
  print_vec_f(vec_floatB, 3);
  printf("\n");

  mncblas_sgemv(101, 111, M, N, alphaf, mat_float, 0, vec_floatA, 1, betaf, vec_floatB, 1);

  printf("==RESULTAT==\n");
  print_vec_f(vec_floatB, 3);

  double *mat_double = init_vec_double(12);
  double *vec_doubleA = init_vec_double(4);
  double *vec_doubleB = init_vec_double(3);

  fill_vec_double(mat_double, 12, 1);
  fill_vec_double(vec_doubleA, 4, 1);
  fill_vec_double(vec_doubleB, 3, 1);

  float alphad = 2.0;
  float betad = 2.0;

  printf("\nDOUBLE\n\nAvant gemv :\nMatrice A : ");
  printf("==AVANT==\n");
  printf("MATRICE\n");
  print_mat_d(mat_double, 12, 4);
  printf("VEC A\n");
  print_vec_d(vec_doubleA, 4);
  printf("VEC B\n");
  print_vec_d(vec_doubleB, 3);
  printf("\n");

  mncblas_dgemv(101, 111, M, N, alphad, mat_double, 0, vec_doubleA, 1, betad, vec_doubleB, 1);

  printf("==RESULTAT==\n");
  print_vec_d(vec_doubleB, 3);


  complexe_float_t *mat_cfloat = init_vec_complexe_float(12);
  complexe_float_t *vec_cfloatA = init_vec_complexe_float(4);
  complexe_float_t *vec_cfloatB = init_vec_complexe_float(3);

  fill_vec_complexe_float(mat_cfloat, 12, 1, 1);
  fill_vec_complexe_float(vec_cfloatA, 4, 1, 1);
  fill_vec_complexe_float(vec_cfloatB, 3, 1, 1);

  complexe_float_t *alphacf = malloc(sizeof(complexe_float_t *));
  complexe_float_t *betacf = malloc(sizeof(complexe_float_t *));
  alphacf[0].real = 2.0;
  alphacf[0].imaginary = 2.0;
  betacf[0].real = 2.0;
  betacf[0].imaginary = 2.0;

  printf("\nCOMPLEXE FLOAT\n\n");
  printf("==AVANT==\n");
  printf("MATRICE\n");
  print_mat_cf(mat_cfloat, 12, 4);
  printf("VEC A\n");
  print_vec_cf(vec_cfloatA, 4);
  printf("VEC B\n");
  print_vec_cf(vec_cfloatB, 3);
  printf("\n");

  mncblas_cgemv(101, 111, M, N, alphacf, mat_cfloat, 0, vec_cfloatA, 1, betacf, vec_cfloatB, 1);

  printf("==RESULTAT==\n");
  print_vec_cf(vec_cfloatB, 3);

  complexe_double_t *mat_cdouble = init_vec_complexe_double(12);
  complexe_double_t *vec_cdoubleA = init_vec_complexe_double(4);
  complexe_double_t *vec_cdoubleB = init_vec_complexe_double(3);

  complexe_double_t *alphacd = malloc(sizeof(double *) * 2);
  complexe_double_t *betacd = malloc(sizeof(double *) * 2);

  fill_vec_complexe_double(mat_cdouble, 12, 1, 1);
  fill_vec_complexe_double(vec_cdoubleA, 4, 1, 1);
  fill_vec_complexe_double(vec_cdoubleB, 3, 1, 1);
  alphacd[0].real = 2.0;
  alphacd[0].imaginary = 2.0;
  betacd[0].real = 2.0;
  betacd[0].imaginary = 2.0;

  printf("\nCOMPLEXE DOUBLE\n\n");
  printf("==AVANT==\n");
  printf("MATRICE\n");
  print_mat_cd(mat_cdouble, 12, 4);
  printf("VEC A\n");
  print_vec_cd(vec_cdoubleA, 4);
  printf("VEC B\n");
  print_vec_cd(vec_cdoubleB, 3);
  printf("\n");

  mncblas_zgemv(101, 111, M, N, alphacd, mat_cdouble, 0, vec_cdoubleA, 1, betacd, vec_cdoubleB, 1);

  printf("==RESULTAT==\n");
  print_vec_cd(vec_cdoubleB, 3);

  u_int64_t i;
  struct timespec start_spec, end_spec;

  printf("==========================================================\n");

  init_flop_nano();

  float* matF = malloc(SIZE * SIZE * sizeof(float));
  fill_vec_float(matF, SIZE * SIZE, 1.0f);
  float* vecF = malloc(SIZE * sizeof(float));
  fill_vec_float(vecF, SIZE, 1.0f);
  float* vecF_r = malloc(SIZE * sizeof(float));

  for (i = 0; i < NB_FOIS; i++) {
    TOP_NANO(start_spec)
    mncblas_sgemv(MNCblasRowMajor, MNCblasNoTrans, SIZE, SIZE, 1.0f, matF, 0, vecF, 1, 0.0f, vecF_r, 1);
    TOP_NANO(end_spec)

    calcul_flop_nano("sdot nano ", SIZE * SIZE, tdiff_nano(&start_spec, &end_spec));
  }
  printf("==========================================================\n");

  init_flop_nano();

  double* matD = malloc(SIZE * SIZE * sizeof(double));
  fill_vec_double(matD, SIZE * SIZE, 1.0);
  double* vecD = malloc(SIZE * sizeof(double));
  fill_vec_double(vecD, SIZE, 1.0);
  double* vecD_r = malloc(SIZE * sizeof(double));

  for (i = 0; i < NB_FOIS; i++) {
    TOP_NANO(start_spec)
    mncblas_dgemv(MNCblasRowMajor, MNCblasNoTrans, SIZE, SIZE, 1.0, matD, 0, vecD, 1, 0.0, vecD_r, 1);
    TOP_NANO(end_spec)

    calcul_flop_nano("sdot nano ", SIZE * SIZE, tdiff_nano(&start_spec, &end_spec));
  }
  printf("==========================================================\n");

  init_flop_nano();

  complexe_float_t* matC = malloc(SIZE * SIZE * sizeof(complexe_float_t));
  fill_vec_complexe_float(matC, SIZE * SIZE, 1, 0);
  complexe_float_t* vecC = malloc(SIZE * sizeof(complexe_float_t));
  fill_vec_complexe_float(vecC, SIZE, 1, 0);
  complexe_float_t* vecC_r = malloc(SIZE * sizeof(complexe_float_t));

  for (i = 0; i < NB_FOIS; i++) {
    TOP_NANO(start_spec)
    mncblas_cgemv(MNCblasRowMajor, MNCblasNoTrans, SIZE, SIZE, &(complexe_float_t) { .real = 1, .imaginary = 0 }, matC, 0, vecC, 1, &(complexe_float_t) { .real = 0, .imaginary = 0 }, vecC_r, 1);
    TOP_NANO(end_spec)

    calcul_flop_nano("sdot nano ", 2 * SIZE * SIZE, tdiff_nano(&start_spec, &end_spec));
  }
  printf("==========================================================\n");

  init_flop_nano();

  complexe_double_t* matZ = malloc(SIZE * SIZE * sizeof(complexe_double_t));
  fill_vec_complexe_double(matZ, SIZE * SIZE, 1, 0);
  complexe_double_t* vecZ = malloc(SIZE * sizeof(complexe_double_t));
  fill_vec_complexe_double(vecZ, SIZE, 1, 0);
  complexe_double_t* vecZ_r = malloc(SIZE * sizeof(complexe_double_t));

  for (i = 0; i < NB_FOIS; i++) {
    TOP_NANO(start_spec)
    mncblas_cgemv(MNCblasRowMajor, MNCblasNoTrans, SIZE, SIZE, &(complexe_double_t) { .real = 1, .imaginary = 0 }, matZ, 0, vecZ, 1, &(complexe_double_t) { .real = 0, .imaginary = 0 }, vecZ_r, 1);
    TOP_NANO(end_spec)

    calcul_flop_nano("sdot nano ", 2 * SIZE * SIZE, tdiff_nano(&start_spec, &end_spec));
  }
}
