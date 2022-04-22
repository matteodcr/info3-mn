//
// Created by matteo on 20/04/2022.
//

#ifndef MNBLAS_H
#define MNBLAS_H

#include "mnblas.h"

#endif

#ifndef COMPEXE_H
#define COMPEXE_H

#include "complexe.h"

#endif

#ifndef TP2_UTILS_H
#define TP2_UTILS_H

/*INIT*/
float *init_vec_float(int size);

double *init_vec_double(int size);

complexe_float_t *init_vec_complexe_float(int size);

complexe_double_t *init_vec_complexe_double(int size);

/*FILL*/
void fill_vec_float(float *v, int size, float deb);

void fill_vec_double(double *v, int size, double deb);

void fill_vec_complexe_float(complexe_float_t *v, int size, float debre, float debim);

void fill_vec_complexe_double(complexe_double_t *v, int size, double debre, double debim);

/*PRINT*/
void print_vec_f(float *v, int size);

void print_vec_d(double *v, int size);

void print_vec_cf(complexe_float_t *v, int size);

void print_vec_cd(complexe_double_t *v, int size);

void print_mat_f(float *v, int size, int r);

void print_mat_d(double *v, int size, int r);

void print_mat_cf(complexe_float_t *v, int size, int r);

void print_mat_cd(complexe_double_t *v, int size, int r);


#endif //TP2_UTILS_H
