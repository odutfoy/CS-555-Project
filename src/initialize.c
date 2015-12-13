#include "initialize.h"
#include "utilitary.h"

/*
 * Initialize parameters and first events
 */
struct Parameters initialize(){
  /* Declare and initialize parameters */
  struct Parameters parameters;

  parameters.clock=0;
  parameters.server_status=0;
  parameters.customers_in_queue=0;
  parameters.time_of_last_event=0;
  parameters.number_blocked=0;
  parameters.total_number_customers=0;
  parameters.total_time_spent=0;
  parameters.headp = listnode__alloc_empty();

  /* Add first nodes (an arrival and a departure) */

  add_arrival();
  add_departure();

  return parameters;
}
