#ifndef UTILITARY_H
#define UTILITARY_H

#include "struct.h"

/**
* Use create_event to create an arrival and returns it
**/
struct Event * create_arrival(struct Parameters* parameter);

/**
* Use create_event to create a departure and returns it
**/
struct Event * create_departure(struct Parameters* parameter);

/**
* Creates a ganeral event
**/
struct Event * create_event(float time, Type type);

/**
* Adds an event to the linked list in parameters
**/
void add_event(struct Event * event, struct Parameters* parameters);

/**
* Transforms an event to type DEL so it is deleted by the clock
**/
void del_current_event(struct Parameters* parameter);

/**
* Free event allocated memory
**/
void free_event(struct Event* event);

/**
* Print the event list
**/
void print_list(struct Parameters* parameter);

/**
* Print an event with its caracteristics
**/
void print_event(struct Event* event);

/**
 * Writes stats in a file
**/
void write_stats(struct Parameters* parameter);


#endif
