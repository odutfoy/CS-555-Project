#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "initialize.h"

int main(int argc, char *argv[]){

    float lambda = 2.0;
    float mu = 1.0;

    struct Parameters parameters = initialize(lambda, mu);

    printf("First arrival time: %f\n", ((struct Event*)(parameters.headp)->data)->time);
    printf("First departure time: %f\n", ((struct Event*)listnode__get_next(parameters.headp)->data)->time);

    return EXIT_SUCCESS;
}
