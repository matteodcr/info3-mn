//
// Created by matteo on 15/02/2022.
//

#ifndef INFO3_MN_POLY_CREUX_H
#define INFO3_MN_POLY_CREUX_H
#define MAX 20
typedef struct {
    int degre;
    int *degres; // -1 si pas de data
    float *coeff;
} polyc_t, *p_polyc_t;

p_polyc_t creer_polynome(int degre);

void init_polynome(p_polyc_t p, float x);

float eval_polynome(p_polyc_t p, float x);

p_polyc_t multiplication_polynome_scalaire(p_polyc_t p, float alpha);

int egalite_polynome(p_polyc_t p1, p_polyc_t p2);

int espilon_egalite(float x, float y);

float eval_polynome(p_polyc_t p, float x);


#endif //INFO3_MN_POLY_CREUX_H
