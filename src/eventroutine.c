#include "eventroutine.h"

void new_arrival_process(struct Parameters* parameters){
  printf("Coucou, t'as reçu un client !\n");
  printf("Clock: %d\n", parameters->clock);
}

void new_departure_process(struct Parameters* parameters){
  printf("Cours, ton client se barre !\n");
  printf("Clock: %d\n", parameters->clock);
}

void test_stop_condition(struct Parameters* parameters){
  if(parameters->clock > parameters->max_clock){
    exit(1);
  }
}
