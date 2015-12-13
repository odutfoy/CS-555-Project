#include "initialize.h"

/*
* Initialize parameters and first events
*/
struct Parameters initialize(float lambda, float mu){

  /* Create first nodes (a event 0, an arrival and a departure) */
  struct Event * init_event=create_event(0.0, INIT);
  struct Event * first_arrival=create_event(poisson_distrib(lambda), ARRIVAL);
  struct Event * first_departure=create_event(first_arrival->time+exp_distrib(mu), DEPARTURE);

  /* Declare and initialize parameters */
  struct Parameters parameters;

  parameters.clock=0;
  parameters.server_status=0;
  parameters.customers_in_queue=0;
  parameters.time_of_last_event=0;
  parameters.number_blocked=0;
  parameters.total_number_customers=0;
  parameters.total_time_spent=0;
  parameters.event_list=linkedlist__alloc_empty();

  linkedlist__push_back(parameters.event_list, init_event);

  parameters.event_iterator=listiterator__init_iterator(parameters.event_list);

  linkedlist__push_back(parameters.event_list, first_arrival);
  linkedlist__push_back(parameters.event_list, first_departure);

  /* Test the initialization */
  assert(listiterator__get_data(parameters.event_iterator) == init_event && "1st node content != init event");
  parameters.event_iterator=listiterator__goto_next(parameters.event_iterator);
  assert(listiterator__get_data(parameters.event_iterator) == first_arrival && "2nd node != first arrival event");
  parameters.event_iterator=listiterator__goto_next(parameters.event_iterator);
  assert(listiterator__get_data(parameters.event_iterator) == first_departure && "3nd node content != first departure event");

  parameters.event_iterator=listiterator__goto_previous(parameters.event_iterator);
  parameters.event_iterator=listiterator__goto_previous(parameters.event_iterator);
  parameters.event_iterator=listiterator__goto_previous(parameters.event_iterator);

  return parameters;
}
