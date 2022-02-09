#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "poly.h"

#include <x86intrin.h>

p_polyf_t creer_polynome (int degre)
{
  p_polyf_t p ;
  
  p = (p_polyf_t) malloc (sizeof (polyf_t)) ;
  p->degre = degre ;

  p->coeff = (float *) malloc ((degre+1) * sizeof (float))  ;

  return p ;
}

void detruire_polynome (p_polyf_t p)
{
  free (p->coeff) ;
  free (p) ;

  return ;
}

void init_polynome (p_polyf_t p, float x)
{
  register unsigned int i ;

  for (i = 0 ; i <= p->degre; ++i)
    p->coeff [i] = x ;

  return ;
}



p_polyf_t lire_polynome_float (char *nom_fichier)
{
  FILE *f ;
  p_polyf_t p ;
  int degre ;
  int i  ;
  int cr ;
  
  f = fopen (nom_fichier, "r") ;
  if (f == NULL)
    {
      fprintf (stderr, "erreur ouverture %s \n", nom_fichier) ;
      exit (-1) ;
    }
  
  cr = fscanf (f, "%d", &degre) ;
  if (cr != 1)
    {
      fprintf (stderr, "erreur lecture du degre\n") ;
      exit (-1) ;
    }
  p = creer_polynome (degre) ;
  
  for (i = 0 ; i <= degre; i++)
    { 
      cr = fscanf (f, "%f", &p->coeff[i]) ;
       if (cr != 1)
    {
      fprintf (stderr, "erreur lecture coefficient %d\n", i) ;
      exit (-1) ;
    }
       
    }

  fclose (f) ;

  return p ;
}

void ecrire_polynome_float (p_polyf_t p)
{
  int i ;

  printf ("%f + %f x ", p->coeff [0], p->coeff [1]) ;
  
  for (i = 2 ; i <= p->degre; i++)
    {  
      printf ("+ %f X^%d ", p->coeff [i], i) ;
    }
  
  printf ("\n") ;

  return ;
}

int egalite_polynome (p_polyf_t p1, p_polyf_t p2)
{
  if (p1->degre != p2->degre) return 0;
  for (int i = 0; i <= p1->degre; i++){
    if (p1->coeff[i] != p2->coeff[i]) return 0;
  }
  return 1;
}

p_polyf_t addition_polynome (p_polyf_t p1, p_polyf_t p2)
{
  p_polyf_t p3 ;
  register unsigned int i ;
  
  p3 = creer_polynome (max (p1->degre, p2->degre));

  for (i = 0 ; i <= min (p1->degre, p2->degre); ++i)
    {
      p3->coeff [i] = p1->coeff [i] + p2->coeff [i] ;
    }

  if (p1->degre > p2->degre)
    {
      for (i = (p2->degre + 1) ; i <= p1->degre; ++i)
	p3->coeff [i] = p1->coeff [i] ;
    }
  else if (p2->degre > p1->degre)
    {
      for (i = (p1->degre + 1) ; i <= p2->degre; ++i)
	p3->coeff [i] = p2->coeff [i] ;
    }
    
  return p3 ;
}

p_polyf_t multiplication_polynome_scalaire (p_polyf_t p, float alpha)
{
  for (int i =0; i<=p->degre; i++){
    p->coeff[i] = p->coeff[i] * alpha;
  }

  return p;
}

float eval_polynome (p_polyf_t p, float x)
{
  float acc = 0;

  float x_pow = 1;
  for (size_t i = 0; i <= p->degre; i++) {
    acc += (p->coeff[i] * x_pow);
    x_pow *= x;
  }

  return acc;
}

p_polyf_t multiplication_polynomes (p_polyf_t p1, p_polyf_t p2)
{
  p_polyf_t new = creer_polynome(p1->degre + p2->degre - 1);
  memset(new->coeff, 0, new->degre * sizeof(int));

  for (size_t i = 0; i <= p1->degre; i++) {
    for (size_t j = 0; j <= p2->degre; j++) {
      new->coeff[i+j] = p1->coeff[i] + p2->coeff[j];
    }
  }

  return new;
}

p_polyf_t puissance_polynome (p_polyf_t p, int n)
{


  return NULL ;
}

p_polyf_t composition_polynome (p_polyf_t p, p_polyf_t q)
{
  p_polyf_t new = creer_polynome((p->degre + 1) * (q->degre + 1));
  memset(new->coeff, 0, new->degre * sizeof(int));

  for (size_t i = 0; i <= p->degre; i++) {
    for (size_t j = 0; j <= q->degre; j++) {
      new->coeff[i + j] = p->coeff[i] * q->coeff[j];
    }
  }

  return new;
}



