#include "initialize.h"

/*
 * Initialize parameters and first events
 */
struct Parameters initialize(float lambda, float mu){
  /* Declare and initialize parameters */
  struct Parameters parameters;

  parameters.clock=0;
  parameters.server_status=0;
  parameters.customers_in_queue=0;
  parameters.time_of_last_event=0;
  parameters.number_blocked=0;
  parameters.total_number_customers=0;
  parameters.total_time_spent=0;
  parameters.headp = listnode__alloc_empty();

  /* Add first nodes (an arrival and a departure) */
  struct Event * first_arrival = malloc(sizeof(first_arrival));
  first_arrival->time = poisson_distrib(lambda);
  first_arrival->type = ARRIVAL;
  listnode__set_data(parameters.headp, first_arrival);

  struct Event * first_departure = malloc(sizeof(first_departure));
  first_departure->time = exp_distrib(mu);
  first_departure->type = DEPARTURE;

  struct listnode * next_event = malloc(sizeof(next_event));
  listnode__set_data(next_event, first_departure);
  listnode__set_next(parameters.headp, next_event);

  return parameters;
}
