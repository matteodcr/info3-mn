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

#define SIZE    65536
#define NB_FOIS    10

int main(int argc, char **argv) {
  int size = 10;

  float *v_floatA = init_vec_float(size);
  float *v_floatB = init_vec_float(size);
  fill_vec_float(v_floatA, size, 1);
  fill_vec_float(v_floatB, size, 5);

  printf("FLOAT\n");
  printf("AVANT DOT\n");
  printf("X:  ");
  print_vec_f(v_floatA, size);
  printf("Y:  ");
  print_vec_f(v_floatB, size);

  float res_f = mncblas_sdot(size, v_floatA, 1, v_floatB, 1);
  printf("RES : %f\n", res_f);

  double *v_doubleA = init_vec_double(size);
  double *v_doubleB = init_vec_double(size);
  fill_vec_double(v_doubleA, size, 1.0);
  fill_vec_double(v_doubleB, size, 5.0);

  printf("\n\nDOUBLE\n");
  printf("AVANT DOT\n");
  printf("X:  ");
  print_vec_d(v_doubleA, size);
  printf("Y:  ");
  print_vec_d(v_doubleB, size);

  double res_d = mncblas_ddot(size, v_doubleA, 1, v_doubleB, 1);
  printf("RES : %lf\n", res_d);


  complexe_float_t *v_cfloatA = init_vec_complexe_float(size);
  complexe_float_t *v_cfloatB = init_vec_complexe_float(size);
  complexe_float_t *dot_cfloat = init_vec_complexe_float(size);
  fill_vec_complexe_float(v_cfloatA, size, 1, 1);
  fill_vec_complexe_float(v_cfloatB, size, 5, 5);
  fill_vec_complexe_float(dot_cfloat, size, 0, 0);

  printf("\n\nCOMPLEXE_FLOAT NON CONJUGUE\n");
  printf("AVANT DOT\n");
  printf("X:  ");
  print_vec_cf(v_cfloatA, size);
  printf("Y:  ");
  print_vec_cf(v_cfloatB, size);
  printf("DOT:  ");
  print_vec_cf(dot_cfloat, size);

  mncblas_cdotu_sub(size, v_cfloatA, 1, v_cfloatB, 1, dot_cfloat);

  printf("APRES DOT\n");
  printf("dot:  ");
  print_vec_cf(dot_cfloat, size);

  printf("\n\nCOMPLEXE_FLOAT CONJUGUE\n");
  printf("AVANT DOT\n");
  printf("X:  ");
  print_vec_cf(v_cfloatA, size);
  printf("Y:  ");
  print_vec_cf(v_cfloatB, size);
  printf("DOT:  ");
  print_vec_cf(dot_cfloat, size);

  mncblas_cdotc_sub(size, v_cfloatA, 1, v_cfloatB, 1, dot_cfloat);

  printf("APRES DOT\n");
  print_vec_cf(dot_cfloat, size);

  complexe_double_t *v_cdoubleA = init_vec_complexe_double(size);
  complexe_double_t *v_cdoubleB = init_vec_complexe_double(size);
  complexe_double_t *dot_cdouble = init_vec_complexe_double(size);
  fill_vec_complexe_double(v_cdoubleA, size, 1.0, 1.0);
  fill_vec_complexe_double(v_cdoubleB, size, 5.0, 5.0);
  fill_vec_complexe_double(dot_cdouble, size, 0, 0);

  printf("\n\nCOMPLEXE_DOUBLE NON CONJUGUE\n");
  printf("AVANT COPIE\n");
  printf("X:  ");
  print_vec_cd(v_cdoubleA, size);
  printf("Y:  ");
  print_vec_cd(v_cdoubleB, size);
  printf("DOT:  ");
  print_vec_cd(dot_cdouble, size);

  mncblas_zdotu_sub(size, v_cdoubleA, 1, v_cdoubleB, 1, dot_cdouble);

  printf("APRES DOT\n");
  print_vec_cd(dot_cdouble, size);

  printf("\n\nCOMPLEXE_DOUBLE CONJUGUE\n");
  printf("AVANT COPIE\n");
  printf("X:  ");
  print_vec_cd(v_cdoubleA, size);
  printf("Y:  ");
  print_vec_cd(v_cdoubleB, size);
  printf("DOT:  ");
  print_vec_cd(dot_cdouble, size);

  mncblas_zdotc_sub(size, v_cdoubleA, 1, v_cdoubleB, 1, dot_cdouble);

  printf("APRES DOT\n");
  print_vec_cd(dot_cdouble, size);

  printf("\n");


  printf("\n\n=========================================================\n");
  printf("PERFORMANCES FLOAT");
  printf("\n=========================================================\n\n");
  struct timeval start, end;
  struct timespec start_spec, end_spec;
  unsigned long long int start_tsc, end_tsc;

  float res_FLOAT;
  int i;
  init_flop_tsc();

  for (i = 0; i < NB_FOIS; i++) {
    v_floatA = init_vec_float(SIZE);
    v_floatB = init_vec_float(SIZE);
    fill_vec_float(v_floatA, SIZE, 1);
    fill_vec_float(v_floatB, SIZE, 1);
    res_FLOAT = 0.0;

    start_tsc = _rdtsc ();
    res_FLOAT = mncblas_sdot(SIZE, v_floatA, 1, v_floatB, 1);
    end_tsc = _rdtsc ();

    calcul_flop_tsc("sdot tsc ", 2 * SIZE, end_tsc - start_tsc);
  }

  printf("res = %f\n", res_FLOAT);
  printf("==========================================================\n");

  init_flop_micro();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_float(v_floatA, SIZE, 1);
    fill_vec_float(v_floatB, SIZE, 1);
    res_FLOAT = 0.0;

    TOP_MICRO(start)
    res_FLOAT = mncblas_sdot(SIZE, v_floatA, 1, v_floatB, 1);
    TOP_MICRO(end)

    calcul_flop_micro("sdot micro", 2 * SIZE, tdiff_micro(&start, &end));
  }

  printf("res = %f\n", res_FLOAT);
  printf("==========================================================\n");

  init_flop_nano();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_float(v_floatA, SIZE, 1);
    fill_vec_float(v_floatB, SIZE, 1);
    res_FLOAT = 0.0;

    TOP_NANO(start_spec)
    res_FLOAT = mncblas_sdot(SIZE, v_floatA, 1, v_floatB, 1);
    TOP_NANO(end_spec)

    calcul_flop_nano("sdot nano ", 2 * SIZE, tdiff_nano(&start_spec, &end_spec));
  }

  printf("\n\n=========================================================\n");
  printf("PERFORMANCES DOUBLE");
  printf("\n=========================================================\n\n");

  double res_DOUBLE;
  init_flop_tsc();

  for (i = 0; i < NB_FOIS; i++) {
    v_doubleA = init_vec_double(SIZE);
    v_doubleB = init_vec_double(SIZE);
    fill_vec_double(v_doubleA, SIZE, 1);
    fill_vec_double(v_doubleB, SIZE, 1);
    res_DOUBLE = 0.0;

    start_tsc = _rdtsc ();
    res_DOUBLE = mncblas_ddot(SIZE, v_doubleA, 1, v_doubleB, 1);
    end_tsc = _rdtsc ();

    calcul_flop_tsc("sdot tsc", 2 * SIZE, end_tsc - start_tsc);
  }

  printf("res = %f\n", res_DOUBLE);
  printf("==========================================================\n");

  init_flop_micro();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_double(v_doubleA, SIZE, 1);
    fill_vec_double(v_doubleB, SIZE, 1);
    res_DOUBLE = 0.0;

    TOP_MICRO(start)
    res_DOUBLE = mncblas_ddot(SIZE, v_doubleA, 1, v_doubleB, 1);
    TOP_MICRO(end)

    calcul_flop_micro("sdot micro", 2 * SIZE, tdiff_micro(&start, &end));
  }

  printf("res = %f\n", res_DOUBLE);
  printf("==========================================================\n");

  init_flop_nano();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_double(v_doubleA, SIZE, 1);
    fill_vec_double(v_doubleB, SIZE, 1);
    res_DOUBLE = 0.0;

    TOP_NANO(start_spec)
    res_DOUBLE = mncblas_ddot(SIZE, v_doubleA, 1, v_doubleB, 1);
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
    dot_cfloat = init_vec_complexe_float(SIZE);

    fill_vec_complexe_float(v_cfloatA, SIZE, 1, 1);
    fill_vec_complexe_float(v_cfloatB, SIZE, 1, 1);

    start_tsc = _rdtsc ();
    mncblas_cdotu_sub(SIZE, v_cfloatA, 1, v_cfloatB, 1, dot_cfloat);
    end_tsc = _rdtsc ();

    calcul_flop_tsc("sdot tsc", 2 * SIZE, end_tsc - start_tsc);
  }

  printf("==========================================================\n");

  init_flop_micro();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_complexe_float(v_cfloatA, SIZE, 1, 1);
    fill_vec_complexe_float(v_cfloatB, SIZE, 1, 1);

    TOP_MICRO(start)
    mncblas_cdotu_sub(SIZE, v_cfloatA, 1, v_cfloatB, 1, dot_cfloat);
    TOP_MICRO(end)

    calcul_flop_micro("sdot micro", 2 * SIZE, tdiff_micro(&start, &end));
  }
  printf("==========================================================\n");

  init_flop_nano();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_complexe_float(v_cfloatA, SIZE, 1, 1);
    fill_vec_complexe_float(v_cfloatB, SIZE, 1, 1);

    TOP_NANO(start_spec)
    mncblas_cdotu_sub(SIZE, v_cfloatA, 1, v_cfloatB, 1, dot_cfloat);
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
    dot_cdouble = init_vec_complexe_double(SIZE);

    fill_vec_complexe_double(v_cdoubleA, SIZE, 1, 1);
    fill_vec_complexe_double(v_cdoubleB, SIZE, 1, 1);

    start_tsc = _rdtsc ();
    mncblas_zdotu_sub(SIZE, v_cdoubleA, 1, v_cdoubleB, 1, dot_cdouble);
    end_tsc = _rdtsc ();

    calcul_flop_tsc("sdot tsc ", 2 * SIZE, end_tsc - start_tsc);
  }

  printf("==========================================================\n");

  init_flop_micro();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_complexe_double(v_cdoubleA, SIZE, 1, 1);
    fill_vec_complexe_double(v_cdoubleB, SIZE, 1, 1);

    TOP_MICRO(start)
    mncblas_zdotu_sub(SIZE, v_cdoubleA, 1, v_cdoubleB, 1, dot_cdouble);
    TOP_MICRO(end)

    calcul_flop_micro("sdot micro", 2 * SIZE, tdiff_micro(&start, &end));
  }

  printf("==========================================================\n");

  init_flop_nano();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_complexe_double(v_cdoubleA, SIZE, 1, 1);
    fill_vec_complexe_double(v_cdoubleB, SIZE, 1, 1);

    TOP_NANO(start_spec)
    mncblas_zdotu_sub(SIZE, v_cdoubleA, 1, v_cdoubleB, 1, dot_cfloat);
    TOP_NANO(end_spec)

    calcul_flop_nano("sdot nano ", 2 * SIZE, tdiff_nano(&start_spec, &end_spec));
  }
}
