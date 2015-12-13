#include "RNG.h"

float test_rng(int size){
  assert(size > 0 && "size must be strictly positive");

  srand(time(NULL));
  
  float sequence[size];
  int i;
  float error = 0;
  float tmp;

  for(i = 0; i < size; i++){
    sequence[i] = 1 - (float)rand()/RAND_MAX;
    assert(sequence[i] <= 1 && sequence[i] >= 0 && "number generated not between 0 and 1");
  }
   

  //Ensuring seed is different
  srand(time(NULL) + 1);

  for(i = 0; i < size; i++){
    tmp = 1 - (float)rand()/RAND_MAX;
    assert(tmp <= 1 && tmp >= 0 && "number generated not between 0 and 1");
    error += fabs(sequence[i] - tmp);
  }
  
  printf("The mean difference between elements of both generated sequence is %f \n" , error/(float)size);
  
  return error/(float)size;
}

float exp_distrib(float mu){  
  float r = 1 - (float)rand()/RAND_MAX;
  assert(r < 1 && r >= 0 && "number generated not between 0 and 1");

  return log(1-r)*(-mu);
}

int poisson_distrib(float lambda){
  float L = exp(-lambda);
  int k = 0;
  float p = 1;
  float r;
  
  do {
    k++;
    r =  1 - (float)rand()/RAND_MAX;
    p *= r;
  } while (p > L);

  return k-1;
}





