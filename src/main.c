#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "timing.h"
#include "initialize.h"
#include "eventroutine.h"

int main(int argc, char *argv[]){

  float lambda=2.0;
  float mu=1.0;
  int m=2;
  int c=5;
  int max_clock=4;

  struct Parameters parameters = initialize(lambda, mu, m, c, max_clock);

  while(1){
    clock_update(&parameters);

    if(((struct Event *)listiterator__get_data(parameters.event_iterator))->type == ARRIVAL){
      new_arrival_process(&parameters);
    }
    else if(((struct Event *)listiterator__get_data(parameters.event_iterator))->type == DEPARTURE){
      new_departure_process(&parameters);
    }else{
      perror("Bad event to process");
      exit(2);
    }

    test_stop_condition(&parameters);
  }
  printf("Finished !");
  return EXIT_SUCCESS;
}
