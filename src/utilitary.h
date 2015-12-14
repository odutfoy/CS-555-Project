#ifndef UTILITARY_H
#define UTILITARY_H

#include "struct.h"

struct Event * create_arrival(struct Parameters* parameter);
struct Event * create_departure(struct Parameters* parameter);
struct Event * create_event(float time, Type type);

/**
 * Adds an event to the linked list in parameters
**/
void add_event(struct Event * event, struct Parameters* parameters);
void del_current_event(struct Parameters* parameter);

#endif
