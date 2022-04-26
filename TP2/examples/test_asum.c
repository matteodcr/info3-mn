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
#define NB_FOIS 10
#define SIZE 65536

int main() {
  int size = 10;

  float *v_floatA = init_vec_float(size);
  fill_vec_float(v_floatA, size, 1);

  printf("FLOAT\n");
  print_vec_f(v_floatA, size);
  float res_f = mnblas_sasum(size, v_floatA, 1);
  printf("RES = %f\n", res_f);

  double *v_doubleA = init_vec_double(size);
  fill_vec_double(v_doubleA, size, 1.0);

  printf("\n\nDOUBLE\n");
  print_vec_d(v_doubleA, size);
  double res_d = mnblas_dasum(size, v_doubleA, 1);
  printf("RES = %lf\n", res_d);

  complexe_float_t *v_cfloatA = init_vec_complexe_float(size);
  fill_vec_complexe_float(v_cfloatA, size, 1, 1);

  printf("\n\nCOMPLEXE_FLOAT\n");
  print_vec_cf(v_cfloatA, size);
  res_f = mnblas_scasum(size, v_cfloatA, 1);
  printf("RES = %f\n", res_f);

  complexe_double_t *v_cdoubleA = init_vec_complexe_double(size);
  fill_vec_complexe_double(v_cdoubleA, size, 1.0, 1.0);

  printf("\n\nCOMPLEXE_DOUBLE\n");
  print_vec_cd(v_cdoubleA, size);
  res_d = mnblas_dzasum(size, v_cdoubleA, 1);
  printf("RES = %lf\n", res_d);


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
    fill_vec_float(v_floatA, SIZE, 1);

    start_tsc = _rdtsc ();
    mnblas_scasum(SIZE, v_floatA, 1);
    end_tsc = _rdtsc ();

    calcul_flop_tsc("sdot tsc ", 2 * SIZE, end_tsc - start_tsc);
  }

  printf("==========================================================\n");

  init_flop_micro();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_float(v_floatA, SIZE, 1);

    TOP_MICRO(start)
    mnblas_scasum(SIZE, v_floatA, 1);
    TOP_MICRO(end)

    calcul_flop_micro("sdot micro", 2 * SIZE, tdiff_micro(&start, &end));
  }

  printf("==========================================================\n");

  init_flop_nano();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_float(v_floatA, SIZE, 1);

    TOP_NANO(start_spec)
    mnblas_scasum(SIZE, v_floatA, 1);
    TOP_NANO(end_spec)

    calcul_flop_nano("sdot nano ", 2 * SIZE, tdiff_nano(&start_spec, &end_spec));
  }

  printf("\n\n=========================================================\n");
  printf("PERFORMANCES DOUBLE");
  printf("\n=========================================================\n\n");

  init_flop_tsc();

  for (i = 0; i < NB_FOIS; i++) {
    v_doubleA = init_vec_double(SIZE);
    fill_vec_double(v_doubleA, SIZE, 1);

    start_tsc = _rdtsc ();
    mnblas_dasum(SIZE, v_doubleA, 1);
    end_tsc = _rdtsc ();

    calcul_flop_tsc("sdot tsc", 2 * SIZE, end_tsc - start_tsc);
  }

  printf("==========================================================\n");

  init_flop_micro();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_double(v_doubleA, SIZE, 1);

    TOP_MICRO(start)
    mnblas_dasum(SIZE, v_doubleA, 1);
    TOP_MICRO(end)

    calcul_flop_micro("sdot micro", 2 * SIZE, tdiff_micro(&start, &end));
  }

  printf("==========================================================\n");

  init_flop_nano();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_double(v_doubleA, SIZE, 1);

    TOP_NANO(start_spec)
    mnblas_dasum(SIZE, v_doubleA, 1);
    TOP_NANO(end_spec)

    calcul_flop_nano("sdot nano", 2 * SIZE, tdiff_nano(&start_spec, &end_spec));
  }

  printf("\n\n=========================================================\n");
  printf("PERFORMANCES COMPLEXE FLOAT");
  printf("\n=========================================================\n\n");

  init_flop_tsc();

  for (i = 0; i < NB_FOIS; i++) {
    v_cfloatA = init_vec_complexe_float(SIZE);

    fill_vec_complexe_float(v_cfloatA, SIZE, 1, 1);

    start_tsc = _rdtsc ();
    mnblas_scasum(SIZE, v_cfloatA, 1);
    end_tsc = _rdtsc ();

    calcul_flop_tsc("sdot tsc", 2 * SIZE, end_tsc - start_tsc);
  }

  printf("==========================================================\n");

  init_flop_micro();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_complexe_float(v_cfloatA, SIZE, 1, 1);

    TOP_MICRO(start)
    mnblas_scasum(SIZE, v_cfloatA, 1);
    TOP_MICRO(end)

    calcul_flop_micro("sdot micro", 2 * SIZE, tdiff_micro(&start, &end));
  }
  printf("==========================================================\n");

  init_flop_nano();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_complexe_float(v_cfloatA, SIZE, 1, 1);

    TOP_NANO(start_spec)
    mnblas_scasum(SIZE, v_cfloatA, 1);
    TOP_NANO(end_spec)

    calcul_flop_nano("sdot nano ", 2 * SIZE, tdiff_nano(&start_spec, &end_spec));
  }

  printf("\n\n=========================================================\n");
  printf("PERFORMANCES COMPLEXE DOUBLE");
  printf("\n=========================================================\n\n");

  init_flop_tsc();

  for (i = 0; i < NB_FOIS; i++) {
    v_cdoubleA = init_vec_complexe_double(SIZE);

    fill_vec_complexe_double(v_cdoubleA, SIZE, 1, 1);

    start_tsc = _rdtsc ();
    mnblas_dzasum(SIZE, v_cdoubleA, 1);
    end_tsc = _rdtsc ();

    calcul_flop_tsc("sdot tsc ", 2 * SIZE, end_tsc - start_tsc);
  }

  printf("==========================================================\n");

  init_flop_micro();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_complexe_double(v_cdoubleA, SIZE, 1, 1);

    TOP_MICRO(start)
    mnblas_dzasum(SIZE, v_cdoubleA, 1);
    TOP_MICRO(end)

    calcul_flop_micro("sdot micro", 2 * SIZE, tdiff_micro(&start, &end));
  }

  printf("==========================================================\n");

  init_flop_nano();

  for (i = 0; i < NB_FOIS; i++) {
    fill_vec_complexe_double(v_cdoubleA, SIZE, 1, 1);

    TOP_NANO(start_spec)
    mnblas_dzasum(SIZE, v_cdoubleA, 1);
    TOP_NANO(end_spec)

    calcul_flop_nano("sdot nano ", 2 * SIZE, tdiff_nano(&start_spec, &end_spec));
  }
}