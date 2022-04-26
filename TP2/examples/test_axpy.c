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
#define NB_FOIS 4
#define SIZE 65536

int main(int argc, char **argv) {
  int size = 10;

  float *v_floatA = init_vec_float(size);
  float *v_floatB = init_vec_float(size);
  fill_vec_float(v_floatA, size, 1);

  printf("FLOAT\n");
  printf("AVANT AXPY\n");
  printf("SRC:  ");
  print_vec_f(v_floatA, size);
  printf("DST:  ");
  print_vec_f(v_floatB, size);

  mnblas_saxpy(size, 2.0, v_floatA, 1, v_floatB, 1);

  printf("APRES AXPY\n");
  printf("SRC:  ");
  print_vec_f(v_floatA, size);
  printf("DST:  ");
  print_vec_f(v_floatB, size);

  double *v_doubleA = init_vec_double(size);
  double *v_doubleB = init_vec_double(size);
  fill_vec_double(v_doubleA, size, 1.0);

  printf("\n\nDOUBLE\n");
  printf("AVANT AXPY\n");
  printf("SRC:  ");
  print_vec_d(v_doubleA, size);
  printf("DST:  ");
  print_vec_d(v_doubleB, size);

  mnblas_daxpy(size, 2.0, v_doubleA, 1, v_doubleB, 1);

  printf("APRES AXPY\n");
  printf("SRC:  ");
  print_vec_d(v_doubleA, size);
  printf("DST:  ");
  print_vec_d(v_doubleB, size);

  complexe_float_t *v_cfloatA = init_vec_complexe_float(size);
  complexe_float_t *v_cfloatB = init_vec_complexe_float(size);
  fill_vec_complexe_float(v_cfloatA, size, 1, 1);

  printf("\n\nCOMPLEXE_FLOAT\n");
  printf("AVANT AXPY\n");
  printf("SRC:  ");
  print_vec_cf(v_cfloatA, size);
  printf("DST:  ");
  print_vec_cf(v_cfloatB, size);
  complexe_float_t *alphaf = malloc(sizeof(complexe_float_t *));
  alphaf[0].real = 2.0;
  alphaf[0].imaginary = 3.0;

  mnblas_caxpy(size, alphaf, v_cfloatA, 1, v_cfloatB, 1);

  printf("APRES AXPY\n");
  printf("SRC:  ");
  print_vec_cf(v_cfloatA, size);
  printf("DST:  ");
  print_vec_cf(v_cfloatB, size);

  complexe_double_t *v_cdoubleA = init_vec_complexe_double(size);
  complexe_double_t *v_cdoubleB = init_vec_complexe_double(size);
  fill_vec_complexe_double(v_cdoubleA, size, 1.0, 1.0);

  printf("\n\nCOMPLEXE_DOUBLE\n");
  printf("AVANT AXPY\n");
  printf("SRC:  ");
  print_vec_cd(v_cdoubleA, size);
  printf("DST:  ");
  print_vec_cd(v_cdoubleB, size);
  complexe_double_t *alphad = malloc(sizeof(double *) * 2);
  alphad[0].real = 2.0;
  alphad[0].imaginary = 3.0;

  mnblas_zaxpy(size, alphad, v_cdoubleA, 1, v_cdoubleB, 1);

  printf("APRES AXPY\n");
  printf("SRC:  ");
  print_vec_cd(v_cdoubleA, size);
  printf("DST:  ");
  print_vec_cd(v_cdoubleB, size);

  printf("\n");


  printf("\n\n=========================================================\n");
  printf("PERFORMANCES FLOAT");
  printf("\n=========================================================\n\n");
  struct timeval start, end;
  struct timespec start_spec, end_spec;
  unsigned long long int start_tsc, end_tsc;

  int i;
  init_flop_tsc();

  for (i = 0; i < NB_FOIS; i++) {
    v_floatA = init_vec_float(SIZE);
    v_floatB = init_vec_float(SIZE);
    fill_vec_float(v_floatA, SIZE, 1);
    fill_vec_float(v_floatB, SIZE, 1);

    start_tsc = _rdtsc ();
    mnblas_saxpy(SIZE, 2.0, v_floatA, 1, v_floatB, 1);
    end_tsc = _rdtsc ();

    calcul_flop_tsc("sdot tsc ", 2 * SIZE, end_tsc - start_tsc);
  }

  printf("==========================================================\n");

  init_flop_micro();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_float(v_floatA, SIZE, 1);
    fill_vec_float(v_floatB, SIZE, 1);

    TOP_MICRO(start)
    mnblas_saxpy(SIZE, 2.0, v_floatA, 1, v_floatB, 1);
    TOP_MICRO(end)

    calcul_flop_micro("sdot micro", 2 * SIZE, tdiff_micro(&start, &end));
  }

  printf("==========================================================\n");

  init_flop_nano();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_float(v_floatA, SIZE, 1);
    fill_vec_float(v_floatB, SIZE, 1);

    TOP_NANO(start_spec)
    mnblas_saxpy(SIZE, 2.0, v_floatA, 1, v_floatB, 1);
    TOP_NANO(end_spec)

    calcul_flop_nano("sdot nano ", 2 * SIZE, tdiff_nano(&start_spec, &end_spec));
  }

  printf("\n\n=========================================================\n");
  printf("PERFORMANCES DOUBLE");
  printf("\n=========================================================\n\n");

  init_flop_tsc();

  for (i = 0; i < NB_FOIS; i++) {
    v_doubleA = init_vec_double(SIZE);
    v_doubleB = init_vec_double(SIZE);
    fill_vec_double(v_doubleA, SIZE, 1);
    fill_vec_double(v_doubleB, SIZE, 1);

    start_tsc = _rdtsc ();
    mnblas_daxpy(SIZE, 2.0, v_doubleA, 1, v_doubleB, 1);
    end_tsc = _rdtsc ();

    calcul_flop_tsc("sdot tsc", 2 * SIZE, end_tsc - start_tsc);
  }

  printf("==========================================================\n");

  init_flop_micro();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_double(v_doubleA, SIZE, 1);
    fill_vec_double(v_doubleB, SIZE, 1);

    TOP_MICRO(start)
    mnblas_daxpy(SIZE, 2.0, v_doubleA, 1, v_doubleB, 1);
    TOP_MICRO(end)

    calcul_flop_micro("sdot micro", 2 * SIZE, tdiff_micro(&start, &end));
  }

  printf("==========================================================\n");

  init_flop_nano();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_double(v_doubleA, SIZE, 1);
    fill_vec_double(v_doubleB, SIZE, 1);

    TOP_NANO(start_spec)
    mnblas_daxpy(SIZE, 2.0, v_doubleA, 1, v_doubleB, 1);
    TOP_NANO(end_spec)

    calcul_flop_nano("sdot nano", 2 * SIZE, tdiff_nano(&start_spec, &end_spec));
  }

  printf("\n\n=========================================================\n");
  printf("PERFORMANCES COMPLEXE FLOAT");
  printf("\n=========================================================\n\n");

  init_flop_tsc();

  for (i = 0; i < NB_FOIS; i++) {
    v_cfloatA = init_vec_complexe_float(SIZE);
    v_cfloatB = init_vec_complexe_float(SIZE);

    fill_vec_complexe_float(v_cfloatA, SIZE, 1, 1);
    fill_vec_complexe_float(v_cfloatB, SIZE, 1, 1);

    start_tsc = _rdtsc ();
    mnblas_caxpy(SIZE, alphaf, v_cfloatA, 1, v_cfloatB, 1);
    end_tsc = _rdtsc ();

    calcul_flop_tsc("sdot tsc", 2 * SIZE, end_tsc - start_tsc);
  }

  printf("==========================================================\n");

  init_flop_micro();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_complexe_float(v_cfloatA, SIZE, 1, 1);
    fill_vec_complexe_float(v_cfloatB, SIZE, 1, 1);

    TOP_MICRO(start)
    mnblas_caxpy(SIZE, alphaf, v_cfloatA, 1, v_cfloatB, 1);
    TOP_MICRO(end)

    calcul_flop_micro("sdot micro", 2 * SIZE, tdiff_micro(&start, &end));
  }
  printf("==========================================================\n");

  init_flop_nano();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_complexe_float(v_cfloatA, SIZE, 1, 1);
    fill_vec_complexe_float(v_cfloatB, SIZE, 1, 1);

    TOP_NANO(start_spec)
    mnblas_caxpy(SIZE, alphaf, v_cfloatA, 1, v_cfloatB, 1);
    TOP_NANO(end_spec)

    calcul_flop_nano("sdot nano ", 2 * SIZE, tdiff_nano(&start_spec, &end_spec));
  }

  printf("\n\n=========================================================\n");
  printf("PERFORMANCES COMPLEXE DOUBLE");
  printf("\n=========================================================\n\n");

  init_flop_tsc();

  for (i = 0; i < NB_FOIS; i++) {
    v_cdoubleA = init_vec_complexe_double(SIZE);
    v_cdoubleB = init_vec_complexe_double(SIZE);

    fill_vec_complexe_double(v_cdoubleA, SIZE, 1, 1);
    fill_vec_complexe_double(v_cdoubleB, SIZE, 1, 1);

    start_tsc = _rdtsc ();
    mnblas_zaxpy(SIZE, alphad, v_cdoubleA, 1, v_cdoubleB, 1);
    end_tsc = _rdtsc ();

    calcul_flop_tsc("sdot tsc ", 2 * SIZE, end_tsc - start_tsc);
  }

  printf("==========================================================\n");

  init_flop_micro();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_complexe_double(v_cdoubleA, SIZE, 1, 1);
    fill_vec_complexe_double(v_cdoubleB, SIZE, 1, 1);

    TOP_MICRO(start)
    mnblas_zaxpy(SIZE, alphad, v_cdoubleA, 1, v_cdoubleB, 1);
    TOP_MICRO(end)

    calcul_flop_micro("sdot micro", 2 * SIZE, tdiff_micro(&start, &end));
  }

  printf("==========================================================\n");

  init_flop_nano();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_complexe_double(v_cdoubleA, SIZE, 1, 1);
    fill_vec_complexe_double(v_cdoubleB, SIZE, 1, 1);

    TOP_NANO(start_spec)
    mnblas_zaxpy(SIZE, alphad, v_cdoubleA, 1, v_cdoubleB, 1);
    TOP_NANO(end_spec)

    calcul_flop_nano("sdot nano ", 2 * SIZE, tdiff_nano(&start_spec, &end_spec));
  }
}