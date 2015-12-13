#ifndef UTILITARY_H
#define UTILITARY_H

#include "struct.h"

void add_arrival(void);
void add_departure(void);
struct Event * create_event(float time, Type type);

#endif
