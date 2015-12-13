#include "timing.h"

void clock_update(struct Parameters* parameters){
  //Deleting first event if it is of type INIT
  if (((struct Event *)listiterator__get_data(parameters->event_iterator))->type == INIT)
    parameters->event_iterator = listiterator__remove_node(parameters->event_iterator);

  else
     parameters->event_iterator = listiterator__goto_next(parameters->event_iterator);

  parameters->clock += ((struct Event *)listiterator__get_data(parameters->event_iterator))->time;
}
