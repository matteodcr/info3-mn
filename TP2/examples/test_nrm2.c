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
#define NB_FOIS 4194
#define SIZE 100

#define NB_FOIS 4194
#define SIZE 100

float *vec1;
float *vec2;

double *vec1d;
double *vec2d;

complexe_float_t *vec1cf;
complexe_float_t *vec2cf;

complexe_double_t *vec1cd;
complexe_double_t *vec2cd;

complexe_float_t *copycf;
complexe_double_t *copycd;

int main(int argc, char **argv) {
  int size = 10;

  float *v_floatA = init_vec_float(size);
  fill_vec_float(v_floatA, size, 1);

  printf("FLOAT\n");
  print_vec_f(v_floatA, size);
  float res_f = mnblas_snrm2(size, v_floatA, 1);
  printf("RES = %f\n", res_f);

  double *v_doubleA = init_vec_double(size);
  fill_vec_double(v_doubleA, size, 1.0);

  printf("\n\nDOUBLE\n");
  print_vec_d(v_doubleA, size);
  double res_d = mnblas_dnrm2(size, v_doubleA, 1);
  printf("RES = %lf\n", res_d);

  complexe_float_t *v_cfloatA = init_vec_complexe_float(size);
  fill_vec_complexe_float(v_cfloatA, size, 1, 1);

  printf("\n\nCOMPLEXE_FLOAT\n");
  print_vec_cf(v_cfloatA, size);
  res_f = mnblas_scnrm2(size, v_cfloatA, 1);
  printf("RES = %f\n", res_f);

  complexe_double_t *v_cdoubleA = init_vec_complexe_double(size);
  fill_vec_complexe_double(v_cdoubleA, size, 1.0, 1.0);

  printf("\n\nCOMPLEXE_DOUBLE\n");
  print_vec_cd(v_cdoubleA, size);
  res_d = mnblas_dznrm2(size, v_cdoubleA, 1);
  printf("RES = %lf\n", res_d);


  printf("\n\n=========================================================\n");
  printf("PERFORMANCES => TODO avec flop.c");
  printf("\n=========================================================\n\n\n");

  exit(0);
}