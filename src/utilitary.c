#include "utilitary.h"
#include "RNG.h"

struct Event * create_arrival(struct Parameters* parameters){
  return create_event(parameters->clock + poisson_distrib(parameters->lambda), ARRIVAL);
}

struct Event * create_departure(struct Parameters* parameters){
  printf("New departure created\n");
  return create_event(parameters->clock + exp_distrib(parameters->mu), DEPARTURE);
}

struct Event * create_event(float time, Type type){
  struct Event * new_event=malloc(sizeof(new_event));
  new_event->time=time;
  new_event->type=type;

  return new_event;
}

void add_event(struct Event * event, struct Parameters* parameters){
  //For simpler code
  float time = event->time;
  float current_time;
  struct listiterator iterator = listiterator__init_iterator(parameters->event_list);

  if (!listiterator__has_next(iterator)){
    listiterator__insert_after(iterator, event);
  } else {
    while (listiterator__has_next(iterator)){
      iterator = listiterator__goto_next(iterator);
      current_time = ((struct Event *)listiterator__get_data(iterator))->time;

      if(time < current_time){
        listiterator__insert_before(iterator, event);
        break;
      }
    }
  }
}

void del_current_event(struct Parameters* parameters){
  ((struct Event *)listiterator__get_data(parameters->event_iterator))->type=DEL;
}
