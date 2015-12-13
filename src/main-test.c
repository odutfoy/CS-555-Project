#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "RNG.h"

int main(){
  FILE *f1 = fopen("tmp/exp-seq.csv", "w");
  FILE *f2 = fopen("tmp/poisson-seq.csv", "w");

  assert(f1 != NULL && f2 != NULL && "Error opening one of the files!");

  test_rng(100000);

  srand(time(NULL));

  float mean = 0;
  int i;
  float tmp;

  //Uncomment next block to test exp_distrib

  for (i = 0; i < 100000; i++){
    tmp = exp_distrib(1);
    mean += tmp;
    fprintf(f1, "%f," , tmp);
  }
  printf("mean_exp : %f\n", mean/100000);


  //Uncomment next block to test poisson_distrib

  for (i = 0; i < 100000; i++){
    tmp = poisson_distrib(10);
    mean += tmp;
    fprintf(f2, "%f," , tmp);
  }
  printf("mean_poiss : %f\n", mean/100000);

  //removing last ',' of files
  fseek(f1,-1,SEEK_END);
  ftruncate(fileno(f1), ftell(f1));

  fseek(f2,-1,SEEK_END);
  ftruncate(fileno(f2), ftell(f2));

  fclose(f1);
  fclose(f2);

  return 0;
}
