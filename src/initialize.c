#include "initialize.h"

/*
* Initializes parameters and first events
*/
struct Parameters initialize(float lambda, float mu, int m, int c, int max_clock, float warming_up_time,  int initial_number_customers){

  /* Tests if initial_number_customers value fits the system */
  if(initial_number_customers >= m+c){
    perror("Too many initial customers for the system capacity");
    exit(2);
  }

  /* Creates first nodes (a event 0, an arrival and a departure) */
  struct Event * init_event=create_event(0.0, INIT);
  struct Event * first_arrival=create_event(poisson_distrib(lambda), ARRIVAL);

  printf("First arrival time %f\n", first_arrival->time);

  /* Initializes the RNG seed */
  srand(time(NULL));

  /* Declares and initialize parameters */
  struct Parameters parameters;

  parameters.clock=0;
  parameters.warming_up_time=warming_up_time;
  if(initial_number_customers > m){
    parameters.number_busy_servers=m;
    parameters.number_customers_in_queue=initial_number_customers-m;
  } else {
    parameters.number_busy_servers=initial_number_customers;
    parameters.number_customers_in_queue=0;
  }
  parameters.number_blocked=0;
  parameters.total_number_customers=initial_number_customers;
  parameters.total_time_spent=0;
  parameters.m=m;
  parameters.c=c;
  parameters.max_clock=max_clock;
  parameters.lambda=lambda;
  parameters.mu=mu;
  parameters.event_list=linkedlist__alloc_empty();

  /* Creates initial event, an arrival and initialize */
  linkedlist__push_back(parameters.event_list, init_event);
  parameters.event_iterator=listiterator__init_iterator(parameters.event_list);
  linkedlist__push_back(parameters.event_list, first_arrival);
  int i=0;
  for(i=0; i<parameters.number_busy_servers; i++){
    add_event(create_departure(&parameters), &parameters);
  }
  int j=0;
  for(j=0; j<parameters.number_customers_in_queue; j++){
    linkedlist__push_front(parameters.event_list, create_event(-1.00, ARRIVAL));
  }

  return parameters;
}
