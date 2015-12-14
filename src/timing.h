#ifndef TIMING_H
#define TIMING_H

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "queue.h"
#include "utilitary.h"

/**
 * Updates clock
 * parameters : a pointer to the structure containing current parameters of the system
 **/
void clock_update(struct Parameters* parameters);

#endif
