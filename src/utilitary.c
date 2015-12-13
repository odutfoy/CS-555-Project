#include "utilitary.h"
#include "RNG.h"

void add_arrival(){
}

void add_departure(){
}

struct Event * create_event(float time, Type type){
  struct Event * new_event=malloc(sizeof(new_event));
  new_event->time=time;
  new_event->type=type;

  return new_event;
}
