# CS-555-Project

In order to run the project input following commands at root of project :

make
./bin/simulator

You can clean temporary folders with :
make clean

Some test we used (cf report) concerning the poissonian, exponential and uniform RNG can be ran using:

make test
./bin/test

The system can run any M/M/m/m+c system. The default in put are :

lambda = 2
mu = 1
number of customers in the system at t0 = 0
m = 2
c = 5

Those values can be changed in main.c
