#include "utilitary.h"
#include "RNG.h"

struct Event * create_arrival(struct Parameters* parameters){
  create_event(parameters->clock + poisson_distrib(parameters->lambda), ARRIVAL);
}

struct Event * create_departure(struct Parameters* parameters){
  return create_event(parameters->clock + exp_distrib(parameters->mu), DEPARTURE);
}

struct Event * create_event(float time, Type type){
  struct Event * new_event=malloc(sizeof(new_event));
  new_event->time=time;
  new_event->type=type;

  return new_event;
}

void add_event(struct Event * event, struct Parameters* parameters){

}
