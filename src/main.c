#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "initialize.h"

/**
 *
 **/
int main(int argc, char *argv[]){

    float lambda = 2.0;
    float mu = 1.0;

    struct Parameters parameters = initialize(lambda, mu);
    printf("%d", parameters.clock);

    return EXIT_SUCCESS;
}
