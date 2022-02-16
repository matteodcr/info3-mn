//
// Created by matteo on 16/02/2022.
//

#include "poly_creux.h"
#include "stdbool.h"
#include "stdio.h"


bool test_init_polynome() {
  p_polyc_t p = creer_polynome(4);
  init_polynome(p, 4);
  return (p->coeff[0] == 4 && p->coeff[1] == 4 && p->coeff[2] == 4 && p->coeff[3] == 4 && p->coeff[4] == 4);
}

bool test_egalite() {
  p_polyc_t p1 = creer_polynome(4);
  init_polynome(p1, 4);
  p_polyc_t p2 = creer_polynome(4);
  init_polynome(p2, 4);
  p_polyc_t p3 = creer_polynome(4);
  init_polynome(p3, 5);
  return (egalite_polynome(p1, p2) && !egalite_polynome(p1, p3));
}

bool test_mult_scalaire() {
  p_polyc_t p1 = creer_polynome(4);
  init_polynome(p1, 4);
  p1 = multiplication_polynome_scalaire(p1, 2);
  p_polyc_t p2 = creer_polynome(4);
  init_polynome(p2, 8);

  return (egalite_polynome(p1, p2));
}

bool test_eval() {
  p_polyc_t p = creer_polynome(2);
  init_polynome(p, 4);
  float rp = eval_polynome(p, 2);
  return espilon_egalite(rp, 28);
}

int main() {
  printf("TEST INIT:");
  if (test_init_polynome()) { printf("OK\n"); }
  else { printf("NOT OK\n"); }

  printf("TEST EGALITE:");
  if (test_egalite()) { printf("OK\n"); }
  else { printf("NOT OK\n"); }

  printf("TEST MULT :");
  if (test_mult_scalaire()) { printf("OK\n"); }
  else { printf("NOT OK\n"); }

  printf("TEST EVAL :");
  if (test_eval()) { printf("OK\n"); }
  else { printf("NOT OK\n"); }
}