#ifndef UTILITARY_H
#define UTILITARY_H

#include "struct.h"

struct Event * create_arrival(struct Parameters* parameter);
struct Event * create_departure(struct Parameters* parameter);
struct Event * create_event(float time, Type type);
void add_event(struct Event * event, struct Parameters* parameters);

#endif
