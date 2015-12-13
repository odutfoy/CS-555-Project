#include "initialize.h"

struct Parameters initialize(){

  struct Parameters parameters;

  parameters.clock=0;
  parameters.server_status=0;
  parameters.customers_in_queue=0;
  parameters.time_of_last_event=0;
  parameters.number_blocked=0;
  parameters.total_number_customers=0;
  parameters.total_time_spent=0;
  parameters.headp = listnode__alloc_empty();

  return parameters;
}
