#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "timing.h"
#include "initialize.h"
#include "eventroutine.h"

int main(int argc, char *argv[]){

  int initial_number_customers = 0;

  float lambda=10.0;
  float mu=1.0;
  int m=2;
  int c=5;
  int max_clock=100;

  struct Parameters parameters = initialize(lambda, mu, m, c, max_clock, initial_number_customers);

  while(1){
    clock_update(&parameters);

    printf("Clock: %f\n", parameters.clock);
    print_list(&parameters);
    printf("Number of customers in the buffer:%d\n", parameters.number_customers_in_queue);
    printf("Number of busy servers:%d\n", parameters.number_busy_servers);
    printf("Number of customers blocked:%d\n", parameters.number_blocked);

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
