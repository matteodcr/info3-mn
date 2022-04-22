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
  printf("PERFORMANCES => TODO avec flop.c");
  printf("\n=========================================================\n\n\n");

  exit(0);
}