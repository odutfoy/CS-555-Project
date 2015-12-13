#include <stdio.h>
#include <stdlib.h>
#include "RNG.h"

int main(){
  printf("Hello World\n");
  test_rng(10000);

  srand(time(NULL));
  
  /*
  float mean = 0;
  int i;
  
  //Uncomment next block to test exp_distrib
  
  for (i = 0; i < 1000000; i++)
    mean += exp_distrib(1);
  printf("mean_exp : %f\n", mean/1000000);
  

  //Uncomment next block to test poisson_distrib
  
  for (i = 0; i < 1000000; i++)
    mean += poisson_distrib(10);
  printf("mean_poiss : %f\n", mean/1000000);
  */

  return 0;
}
