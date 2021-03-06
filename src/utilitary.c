#include "utilitary.h"
#include "RNG.h"

struct Event * create_arrival(struct Parameters* parameters){
  return create_event(parameters->clock + poisson_distrib(parameters->lambda), ARRIVAL);
}

struct Event * create_departure(struct Parameters* parameters){
  struct Event* departure = create_event(parameters->clock + exp_distrib(parameters->mu), DEPARTURE);
  if(parameters->number_customers_in_queue > 0){
    add_total_time_spent(parameters, departure->time - parameters->clock);
  } else {
    add_total_time_spent(parameters, departure->time - ((struct Event*)((parameters->event_list->headNode)->data))->time);
  }
  return departure;
}

struct Event * create_event(float time, Type type){
  struct Event * new_event=malloc(sizeof(new_event));
  new_event->time=time;
  new_event->type=type;

  return new_event;
}

void add_event(struct Event * event, struct Parameters* parameters){
  float time = event->time;
  float next_time;
  struct listnode * next = parameters->event_list->headNode;
  struct listiterator iterator = listiterator__init_iterator(parameters->event_list);

  while (listiterator__has_next(iterator)){
    next_time = ((struct Event*)(listnode__get_next(next))->data)->time;

    if(time < next_time)
      break;

    next = listnode__get_next(next);
    iterator = listiterator__goto_next(iterator);
   }

  listiterator__insert_after(iterator, event);
}

void del_current_event(struct Parameters* parameters){
  ((struct Event *)listiterator__get_data(parameters->event_iterator))->type=DEL;
}

void free_event(struct Event* event){
  free(event);
}

void control_asserts(struct Parameters* parameters){
  assert(parameters->number_busy_servers <= parameters->m);
  assert(parameters->number_busy_servers >= 0);

  assert(parameters->number_customers_in_queue >= 0);
  assert(parameters->number_customers_in_queue <= parameters->c);

  assert(!(parameters->number_customers_in_queue > 0 && parameters->number_busy_servers < parameters->m));
}

void print_event(struct Event* event){
  printf("Type : %d\n", event->type);
  printf("Time : %f\n", event->time);
}

void print_list(struct Parameters* parameters){
  struct listiterator iterator = listiterator__init_iterator(parameters->event_list);

  printf("\nlist_size : %d\n", linkedlist__get_size(parameters->event_list));
  printf("HEAD : \n");
  print_event((struct Event *)listiterator__get_data(iterator));

  int i = 1;

  while (listiterator__has_next(iterator)){
    iterator = listiterator__goto_next(iterator);
    printf("\nEVENT : %d\n", i);
    print_event((struct Event *)listiterator__get_data(iterator));
    i++;
  }
  printf("----------------------\n");
}

void write_stats(struct Parameters* parameters){
  FILE *ca = fopen("tmp/customer-amount5.csv", "a+");
  FILE *cl = fopen("tmp/clock5.csv", "a+");

  assert(ca != NULL && cl != NULL && "Error opening file!");

  int customer_amount = parameters->number_busy_servers + parameters->number_customers_in_queue;

  fprintf(ca, "%d,", customer_amount);
  fprintf(cl, "%f,", parameters->clock);

  fclose(ca);
  fclose(cl);
}
