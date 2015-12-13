#include "queue.h"

#ifndef STRUCT_H
#define STRUCT_H

typedef enum Type Type;
enum Type
{
  INIT, DEPARTURE, ARRIVAL
};

/*
* State variables:
*  - clock: the simulation clock
*  - server_status: the number of busy servers
*  - customers_in_queue: the number of customers in the queue
*  - time_of_last_event: the begining time of the next event
*
* Statistical variables:
*  - number_blocked: overall number of blocked customers
*  - total_number_customers: overall number of customers
*  - total_time_spent: overall time spent in the system by customers
*/
struct Parameters{
  int clock;
  int server_status;
  int customers_in_queue;
  int time_of_last_event;
  int number_blocked;
  int total_number_customers;
  int total_time_spent;

  int m;
  int s;
  int max_clock;

  struct linkedlist* event_list;
  struct listiterator event_iterator;
};

/*
* time: time which the the event occurs
* type: a Type object, the type of the event
*/
struct Event {
  float time;
  Type type;
};

#endif
