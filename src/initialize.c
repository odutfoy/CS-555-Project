#include "initialize.h"

/*
* Initialize parameters and first events
*/
struct Parameters initialize(float lambda, float mu, int m, int c, int max_clock){

  /* Create first nodes (a event 0, an arrival and a departure) */
  struct Event * init_event=create_event(0.0, INIT);
  struct Event * first_arrival=create_event(poisson_distrib(lambda), ARRIVAL);

  printf("First arrival time %f\n", first_arrival->time);

  /* Initialize the RNG seed */
  srand(time(NULL));

  /* Declare and initialize parameters */
  struct Parameters parameters;

  parameters.clock=0;
  parameters.number_busy_servers=0;
  parameters.number_customers_in_queue=0;
  parameters.time_of_last_event=0;
  parameters.number_blocked=0;
  parameters.total_number_customers=0;
  parameters.total_time_spent=0;
  parameters.m=m;
  parameters.c=c;
  parameters.max_clock=max_clock;
  parameters.lambda=lambda;
  parameters.mu=mu;
  parameters.event_list=linkedlist__alloc_empty();

  linkedlist__push_back(parameters.event_list, init_event);

  parameters.event_iterator=listiterator__init_iterator(parameters.event_list);

  linkedlist__push_back(parameters.event_list, first_arrival);

  /* Test the initialization and return to the initial state */
  struct listiterator test_iterator = listiterator__init_iterator(parameters.event_list);
  assert(listiterator__get_data(test_iterator) == init_event && "1st node content != init event");
  test_iterator=listiterator__goto_next(test_iterator);
  assert(listiterator__get_data(test_iterator) == first_arrival && "2nd node != first arrival event");

  return parameters;
}
