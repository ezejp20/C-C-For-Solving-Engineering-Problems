//
//  random.h
//  Example from CS106bReader



#ifndef _random_h
#define _random_h

#include <stdio.h>

int randomInteger(int low, int high);
double randomReal(double low,double high);
bool randomChance(double p);
void setRandomSeed(int seed);

#endif /* defined(__RandomTest__random__) */
