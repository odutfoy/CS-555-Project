#ifndef STRUCT_H
#define STRUCT_H

/**
  clock: the simulation clock
  server_status: the number of busy servers
  customers_in_queue: the number of customers in the queue
  time_of_last_event: the begining time of the next event
  number_blocked: overall number of blocked customers
  total_number_customer: overall number of customers
  total_time_spent: overall time spent in the system by customers
**/
struct Parameters{
  int clock;
  int server_status;
  int customers_in_queue;
  int time_of_last_event;
  int number_blocked;
  int total_number_customer;
  int total_time_spent;
};

#endif
