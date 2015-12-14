#include "eventroutine.h"

void new_arrival_process(struct Parameters* parameters){
  printf("Hey, you've a new customer !\n");
  printf("Clock: %f\n", parameters->clock);

  add_event(create_arrival(parameters), parameters);

  if(parameters->number_customers_in_queue >= parameters->c){
    /* If the buffer is full */
    parameters->number_blocked += 1;
    del_current_event(parameters);
  } else {
    if(parameters->number_busy_servers >= parameters->m){
      parameters->number_customers_in_queue += 1;
    } else {
      parameters->number_busy_servers += 1;
      add_event(create_departure(parameters), parameters);
      del_current_event(parameters);
    }
  }
}

void new_departure_process(struct Parameters* parameters){
  printf("Run, you're customer is leaving !\n");
  printf("Clock: %f\n", parameters->clock);

  if(parameters->number_customers_in_queue == 0){
    parameters->number_busy_servers -= 1;
    del_current_event(parameters);
  } else {
    add_event(create_departure(parameters), parameters);
    parameters->number_customers_in_queue -= 1;
    del_current_event(parameters);
    linkedlist__pop_front(parameters->event_list);
  }
}

void test_stop_condition(struct Parameters* parameters){
  if(parameters->clock > parameters->max_clock){
    printf("Simulation finished");
    exit(1);
  }
}
