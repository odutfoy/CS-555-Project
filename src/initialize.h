#ifndef INITIALIZE_H
#define INITIALIZE_H

#include <stdlib.h>
#include "struct.h"
#include "RNG.h"
#include "utilitary.h"

struct Parameters initialize(float lambda, float mu, int m, int c, int max_clock);

#endif
