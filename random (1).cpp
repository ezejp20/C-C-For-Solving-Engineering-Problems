//
//  random.cpp
//  Example from CS106bReader
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "random.h"

void initRandomSeed(){
    static bool initialized=false;
    if(!initialized){
        srand(int(time(NULL)));
        initialized=true;
    }
}

int randomInteger(int low, int high){
    initRandomSeed();
    double d=rand()/(double(RAND_MAX)+1);
    double s=d*(double(high)-low+1);
    return int(floor(low+s));
}

double randomReal(double low,double high){
    initRandomSeed();
    double d=rand()/(double(RAND_MAX)+1);
    double s=d*(double(high)-low+1);
    return low+s;
}
bool randomChance(double p){
    initRandomSeed();
    return randomReal(0, 1)<p;
}
void setRandomSeed(int seed){
    initRandomSeed();srand(seed);
}