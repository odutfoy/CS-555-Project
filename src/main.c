#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "initialize.h"

/**
 *
 **/
int main(int argc, char *argv[]){

    struct Parameters parameters = initialize();
    printf("%d", parameters.clock);

    return EXIT_SUCCESS;
}
