#include <stdio.h>
#include <stdlib.h>
#include "RNG.h"

int main(){
  printf("Hello World\n");
  test_rng(1000000);
  
  float mean = 0;
  
  //Uncomment next block to test exp_distrib
  /*
  for (int i = 0; i < 1000000; i++)
    mean += exp_distrib(1);
  printf("mean : %f\n", mean/1000000);
  */

  //Uncomment next block to test poisson_distrib
  /*
  for (int i = 0; i < 1000000; i++)
    mean += poisson_distrib(1);
  printf("mean : %f\n", mean/1000000);
  */

  return 0;
}
