#include "eventroutine.h"

void new_arrival_process(struct Parameters* parameters){
  add_event(create_arrival(parameters), parameters);
  increase_total_number_customers(parameters);
  if(parameters->number_customers_in_queue >= parameters->c){
    /* If the buffer is full */
    increase_blocked(parameters);
    del_current_event(parameters);
  } else {
    if(parameters->number_busy_servers >= parameters->m){
      increase_number_customers_in_queue(parameters);
    } else {
      increase_number_busy_servers(parameters);
      add_event(create_departure(parameters), parameters);
      del_current_event(parameters);
    }
  }
}

void new_departure_process(struct Parameters* parameters){
  if(parameters->number_customers_in_queue == 0){
    decrease_number_busy_servers(parameters);
    del_current_event(parameters);
  } else {
    add_event(create_departure(parameters), parameters);
    decrease_number_customers_in_queue(parameters);
    del_current_event(parameters);
    linkedlist__pop_front(parameters->event_list);
  }
}

void test_stop_condition(struct Parameters* parameters){
  if(parameters->clock >= parameters->max_clock){
    printf("Simulation finished\n");
    print_stats(parameters);
    exit(1);
  }
}

void print_stats(struct Parameters* parameters){
  printf("Blocking probability = %f\n", (float)parameters->number_blocked/(float)parameters->total_number_customers);
  printf("Mean number of customers = %f\n", (float)(parameters->total_number_customers-parameters->number_blocked)/parameters->clock);
}

void increase_blocked(struct Parameters* parameters){
  if(parameters->warming_up_time < parameters->clock)
    parameters->number_blocked += 1;
}

void increase_total_number_customers(struct Parameters* parameters){
  if(parameters->warming_up_time < parameters->clock)
    parameters->total_number_customers += 1;
}

void increase_number_customers_in_queue(struct Parameters* parameters){
  if(parameters->warming_up_time < parameters->clock)
    parameters->number_customers_in_queue += 1;
}

void increase_number_busy_servers(struct Parameters* parameters){
  if(parameters->warming_up_time < parameters->clock)
    parameters->number_busy_servers += 1;
}

void decrease_number_busy_servers(struct Parameters* parameters){
  if(parameters->warming_up_time < parameters->clock)
    parameters->number_busy_servers -= 1;
}

void decrease_number_customers_in_queue(struct Parameters* parameters){
  if(parameters->warming_up_time < parameters->clock)
    parameters->number_customers_in_queue -= 1;
}
