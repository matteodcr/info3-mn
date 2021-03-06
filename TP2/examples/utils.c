#include <stdio.h>
#include <stdlib.h>

#ifndef TESTUILS_H
#define TESTUILS_H

#include "utils.h"

#endif



////////////
/*VECTEURS*/
///////////

/*INIT*/

float *init_vec_float(int size) {
  return malloc(sizeof(float *) * size);
}

double *init_vec_double(int size) {
  return malloc(sizeof(float *) * size);
}

complexe_float_t *init_vec_complexe_float(int size) {
  return malloc(sizeof(float *) * (size));
}

complexe_double_t *init_vec_complexe_double(int size) {
  return malloc(sizeof(double *) * (size * 2));
}

/*FILL*/

void fill_vec_float(float *v, int size, float deb) {
  float cpt = deb;
  for (int i = 0; i < size; i++) {
    v[i] = cpt;
    cpt++;
  }
}

void fill_vec_double(double *v, int size, double deb) {
  double cpt = deb;
  for (int i = 0; i < size; i++) {
    v[i] = cpt;
    cpt++;
  }
}

void fill_vec_complexe_float(complexe_float_t *v, int size, float debre, float debim) {
  complexe_float_t cpt = {debre, debim};
  for (int i = 0; i < size; i++) {
    v[i].real = cpt.real;
    v[i].imaginary = cpt.imaginary;
    cpt.real++;
    cpt.imaginary++;
  }
}

void fill_vec_complexe_double(complexe_double_t *v, int size, double debre, double debim) {
  complexe_double_t cpt = {debre, debim};
  for (int i = 0; i < size; i++) {
    v[i].real = cpt.real;
    v[i].imaginary = cpt.imaginary;
    cpt.real++;
    cpt.imaginary++;
  }
}

/*PRINT*/

void print_vec_f(float *v, int size) {
  for (int i = 0; i < size; i++) {
    printf("%.1f, ", v[i]);
  }
  printf("\n");
}

void print_vec_d(double *v, int size) {
  for (int i = 0; i < size; i++) {
    printf("%.1lf, ", v[i]);
  }
  printf("\n");
}

void print_vec_cf(complexe_float_t *v, int size) {
  for (int i = 0; i < size; i++) {
    printf("(%.1f, %.1f), ", v[i].real, v[i].imaginary);
  }
  printf("\n");
}

void print_vec_cd(complexe_double_t *v, int size) {
  for (int i = 0; i < size; i++) {
    printf("(%.1lf, %.1lf), ", v[i].real, v[i].imaginary);
  }
  printf("\n");
}

////////////
/*MATRICES*/
////////////q

void print_mat_f(float *v, int size, int r) {
  for (int i = 0; i < size; i++) {
    if (i % r == 0) {
      printf("\n");
    }
    printf("%.1f, ", v[i]);
  }
  printf("\n");
}

void print_mat_d(double *v, int size, int r) {
  for (int i = 0; i < size; i++) {
    if (i % r == 0) {
      printf("\n");
    }
    printf("%.1lf, ", v[i]);
  }
  printf("\n");
}

void print_mat_cf(complexe_float_t *v, int size, int r) {
  for (int i = 0; i < size; i++) {
    if (i % r == 0) {
      printf("\n");
    }
    printf("(%.1f, %.1f), ", v[i].real, v[i].imaginary);
  }
  printf("\n");
}

void print_mat_cd(complexe_double_t *v, int size, int r) {
  for (int i = 0; i < size; i++) {
    if (i % r == 0) {
      printf("\n");
    }
    printf("(%.1lf, %.1lf), ", v[i].real, v[i].imaginary);
  }
  printf("\n");
}

void transposition_mat_float(float *v, int size, int hauteur, int largeur) {
  float *tmp = init_vec_float(size);
  for (int i = 0; i < largeur; i++) {
    for (int j = 0; j < hauteur; j++) {
      tmp[i * hauteur + j] = tmp[j * largeur];
    }
  }
  v = tmp;
}


