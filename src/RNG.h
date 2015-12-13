#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <unistd.h>

#ifndef RNH_h
#define RNG_h

/**
 * Displays the average difference between two corresponding elements of 2 sequences of random numbers between 0 and 1 generated with different seeds
 * Writes the values of one of the sequences in a file in order to plot a graph representing distribution
 * Parameters :
 * - size : size of sequences to generate (strictly positive integer)
 * Output : mean error between two corresponding elements of the sequences
**/

float test_rng(int size);

/**
 * Simulates the exponential distribution
 * Parameters :
 * - mu : service rate of server
 * Output : service time
**/

float exp_distrib(float mu);

/**
 * Simulates poissonian arrivals
 * Parameters :
 * - lamda : arrival rate of server
 * Output : arrival time
**/

float poisson_distrib(float lambda);

#endif
