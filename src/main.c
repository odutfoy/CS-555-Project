#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "timing.h"
#include "initialize.h"
#include "eventroutine.h"

int main(int argc, char *argv[]){

    float lambda = 2.0;
    float mu = 1.0;
    int m = 2;
    int s = 5;

    struct Parameters parameters = initialize(lambda, mu);

    while(1){
      clock_update(&parameters);
    }

    return EXIT_SUCCESS;
}
