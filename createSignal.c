//
//  Creating a cosine signal to be plotted in Matlab
//  Lec1 example

#include <stdio.h>
#include <math.h>
#define FSAMPLE 10000
#define PI 3.1416

int main() {
    double t,dt=1.0/FSAMPLE;
    for (t=0.0; t<0.03; t+=dt) {
        printf("%6.4f\t%6.4f\n",t,2*cos(2*PI*100*t+0));
    }
    return 0;
}
