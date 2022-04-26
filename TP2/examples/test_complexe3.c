#include <stdio.h>
#include <stdlib.h>
#include "mnblas.h"
#include "complexe2.h"


#define    NB_FOIS        512

#include "flop.h"

int main() {

  complexe_double_t cd1;
  complexe_double_t cd2;

  unsigned long long int start, end;
  struct timeval start_val, end_val;
  struct timespec start_spec, end_spec;
  int i;

  cd1 = (complexe_double_t) {10.0, 7.0};
  cd2 = (complexe_double_t) {25.0, 32.0};


  /////////////
  init_flop_tsc();
  start = _rdtsc ();
  for (i = 0; i < NB_FOIS; i++) {
    add_complexe_double(cd1, cd2);
  }
  end = _rdtsc ();
  calcul_flop_tsc("calcul complexe tsc ", NB_FOIS * 2, end - start);

  /////////////
  init_flop_micro();
  TOP_MICRO(start_val)
  for (i = 0; i < NB_FOIS; i++) {
    add_complexe_double(cd1, cd2);
  }
  TOP_MICRO(end_val)
  end = _rdtsc ();
  calcul_flop_micro("calcul complexe micro ", NB_FOIS * 2, tdiff_micro(&start_val, &end_val));

  /////////////
  init_flop_nano();
  TOP_NANO(start_spec)
  for (i = 0; i < NB_FOIS; i++) {
    add_complexe_double(cd1, cd2);
  }
  TOP_NANO(end_spec)
  calcul_flop_nano("calcul complexe nano ", NB_FOIS * 2, tdiff_nano(&start_spec, &end_spec));

  exit(0);

}


