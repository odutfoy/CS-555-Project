#ifndef EVENTROUTINE_H
#define EVENTROUTINE_H

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "utilitary.h"

void new_arrival_process(struct Parameters* parameters);
void new_departure_process(struct Parameters* parameters);
void test_stop_condition(struct Parameters* parameters);
void print_stats(struct Parameters* parameters);
void increase_blocked(struct Parameters* parameters);
void increase_total_number_customers(struct Parameters* parameters);
void increase_number_customers_in_queue(struct Parameters* parameters);
void increase_number_busy_servers(struct Parameters* parameters);
void decrease_number_busy_servers(struct Parameters* parameters);
void decrease_number_customers_in_queue(struct Parameters* parameters);

#endif
