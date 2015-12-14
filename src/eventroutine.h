#ifndef EVENTROUTINE_H
#define EVENTROUTINE_H

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "utilitary.h"

void new_arrival_process(struct Parameters* parameters);
void new_departure_process(struct Parameters* parameters);
void test_stop_condition(struct Parameters* parameters);

#endif
