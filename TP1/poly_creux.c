//
// Created by matteo on 15/02/2022.
//

#include "poly_creux.h"
#include "stdlib.h"
#include "math.h"

p_polyc_t creer_polynome(int degre) {
  p_polyc_t p;

  p = (p_polyc_t) malloc(sizeof(polyc_t));
  p->degre = degre;

  p->degres = (int *) malloc((degre) * sizeof(int));
  p->coeff = (float *) malloc((degre) * sizeof(float));

  return p;
}

void init_polynome(p_polyc_t p, float x) {
  for (int i = 0; i <= p->degre; i++) {
    p->degres[i] = i;
    p->coeff[i] = x;
  }
}

int espilon_egalite(float x, float y) {
  return (x - 0.1 <= y && x + 0.1 >= y);
}

int egalite_polynome(p_polyc_t p1, p_polyc_t p2) {
  if (p1->degre != p2->degre) return 0;
  for (int i = 0; i < p1->degre; i++) {
    if (p1->degres[i] != p2->degres[i] || !espilon_egalite(p1->coeff[i], p2->coeff[i])) return 0;
  }
  return 1;
}

p_polyc_t multiplication_polynome_scalaire(p_polyc_t p, float alpha) {
  for (int i = 0; i <= p->degre; i++) {
    p->coeff[i] = p->coeff[i] * alpha;
  }
  return p;
}

float eval_polynome(p_polyc_t p, float x) {
  float r = 0;
  for (int i = 0; i <= p->degre; i++) {
    r += p->coeff[i] * powf(x, (float) p->degres[i]);
  }
  return r;
}
