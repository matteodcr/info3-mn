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

#include "flop.h"

#define VECSIZE    65536

#define NB_FOIS    10

typedef float vfloat[VECSIZE];

vfloat vec1, vec2;

void vector_init(vfloat V, float x) {
  register unsigned int i;

  for (i = 0; i < VECSIZE; i++)
    V[i] = x;
}

void vector_print(vfloat V) {
  register unsigned int i;

  for (i = 0; i < VECSIZE; i++)
    printf("%f ", V[i]);
  printf("\n");
}

int main(int argc, char **argv) {
  int size = 10;

  float *v_floatA = init_vec_float(size);
  float *v_floatB = init_vec_float(size);
  fill_vec_float(v_floatA, size, 1);
  fill_vec_float(v_floatB, size, 5);

  printf("FLOAT\n");
  printf("AVANT DOT\n");
  printf("SRC:  ");
  print_vec_f(v_floatA, size);
  printf("DST:  ");
  print_vec_f(v_floatB, size);

  float res_f = mncblas_sdot(size, v_floatA, 1, v_floatB, 1);
  printf("RES : %f\n", res_f);

  double *v_doubleA = init_vec_double(size);
  double *v_doubleB = init_vec_double(size);
  fill_vec_double(v_doubleA, size, 1.0);
  fill_vec_double(v_doubleB, size, 5.0);

  printf("\n\nDOUBLE\n");
  printf("AVANT DOT\n");
  printf("SRC:  ");
  print_vec_d(v_doubleA, size);
  printf("DST:  ");
  print_vec_d(v_doubleB, size);

  double res_d = mncblas_ddot(size, v_doubleA, 1, v_doubleB, 1);
  printf("RES : %lf\n", res_d);


  complexe_float_t *v_cfloatA = init_vec_complexe_float(size);
  complexe_float_t *v_cfloatB = init_vec_complexe_float(size);
  complexe_float_t *dot_cfloatB = init_vec_complexe_float(size);
  fill_vec_complexe_float(v_cfloatA, size, 1, 1);
  fill_vec_complexe_float(v_cfloatB, size, 5, 5);
  fill_vec_complexe_float(dot_cfloatB, size, 0, 0);

  printf("\n\nCOMPLEXE_FLOAT NON CONJUGUE\n");
  printf("AVANT DOT\n");
  printf("SRC:  ");
  print_vec_cf(v_cfloatA, size);
  printf("DST:  ");
  print_vec_cf(v_cfloatB, size);
  printf("DOT:  ");
  print_vec_cf(dot_cfloatB, size);

  mncblas_cdotu_sub(size, v_cfloatA, 1, v_cfloatB, 1, dot_cfloatB);

  printf("APRES DOT\n");
  printf("dot:  ");
  print_vec_cf(dot_cfloatB, size);

  printf("\n\nCOMPLEXE_FLOAT CONJUGUE\n");
  printf("AVANT DOT\n");
  printf("SRC:  ");
  print_vec_cf(v_cfloatA, size);
  printf("DST:  ");
  print_vec_cf(v_cfloatB, size);
  printf("DOT:  ");
  print_vec_cf(dot_cfloatB, size);

  mncblas_cdotc_sub(size, v_cfloatA, 1, v_cfloatB, 1, dot_cfloatB);

  printf("APRES DOT\n");
  print_vec_cf(dot_cfloatB, size);

  complexe_double_t *v_cdoubleA = init_vec_complexe_double(size);
  complexe_double_t *v_cdoubleB = init_vec_complexe_double(size);
  complexe_double_t *dot_cdoubleB = init_vec_complexe_double(size);
  fill_vec_complexe_double(v_cdoubleA, size, 1.0, 1.0);
  fill_vec_complexe_double(v_cdoubleB, size, 5.0, 5.0);
  fill_vec_complexe_double(dot_cdoubleB, size, 0, 0);

  printf("\n\nCOMPLEXE_DOUBLE NON CONJUGUE\n");
  printf("AVANT COPIE\n");
  printf("SRC:  ");
  print_vec_cd(v_cdoubleA, size);
  printf("DST:  ");
  print_vec_cd(v_cdoubleB, size);
  printf("DOT:  ");
  print_vec_cd(dot_cdoubleB, size);

  mncblas_zdotu_sub(size, v_cdoubleA, 1, v_cdoubleB, 1, dot_cdoubleB);

  printf("APRES DOT\n");
  print_vec_cd(dot_cdoubleB, size);

  printf("\n\nCOMPLEXE_DOUBLE CONJUGUE\n");
  printf("AVANT COPIE\n");
  printf("SRC:  ");
  print_vec_cd(v_cdoubleA, size);
  printf("DST:  ");
  print_vec_cd(v_cdoubleB, size);
  printf("DOT:  ");
  print_vec_cd(dot_cdoubleB, size);

  mncblas_zdotc_sub(size, v_cdoubleA, 1, v_cdoubleB, 1, dot_cdoubleB);

  printf("APRES DOT\n");
  print_vec_cd(dot_cdoubleB, size);

  printf("\n");


  printf("\n\n=========================================================\n");
  printf("PERFORMANCES");
  printf("\n=========================================================\n\n\n");
  struct timeval start, end;
  unsigned long long int start_tsc, end_tsc;

  float res;
  int i;

  init_flop_tsc();

  for (i = 0; i < NB_FOIS; i++) {
    vector_init(vec1, 1.0);
    vector_init(vec2, 2.0);
    res = 0.0;

    start_tsc = _rdtsc ();
    res = mncblas_sdot(VECSIZE, vec1, 1, vec2, 1);
    end_tsc = _rdtsc ();

    calcul_flop_tsc("sdot nano ", 2 * VECSIZE, end_tsc - start_tsc);
  }

  printf("res = %f\n", res);
  printf("==========================================================\n");

  init_flop_micro();

  for (i = 0; i < NB_FOIS; i++) {
    vector_init(vec1, 1.0);
    vector_init(vec2, 2.0);
    res = 0.0;

    TOP_MICRO(start);
    res = mncblas_sdot(VECSIZE, vec1, 1, vec2, 1);
    TOP_MICRO(end);

    calcul_flop_micro("sdot micro", 2 * VECSIZE, tdiff_micro(&start, &end));
  }

  printf("res = %f\n", res);
  printf("==========================================================\n");

  init_flop_tsc();

  for (i = 0; i < NB_FOIS; i++) {
    vector_init(vec1, 1.0);
    vector_init(vec2, 2.0);
    res = 0.0;

    start_tsc = _rdtsc ();
    res = mncblas_sdot(VECSIZE, vec1, 1, vec2, 1);
    end_tsc = _rdtsc ();

    calcul_flop_nano("sdot nano ", 2 * VECSIZE, end_tsc - start_tsc);
  }

  printf("res = %f\n", res);
  printf("==========================================================\n");

}
