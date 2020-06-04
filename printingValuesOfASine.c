//
//  PrintingValuesOfASine
//
//  Created by Baris Bozkurt on 21/01/16.
//

#include <stdio.h>
#include <math.h>
//Your code starts here: define PI and FSAMPLE
#define PI 3.1416
#define FSAMPLE 1000
//Your code ends here

int main(int argc, const char * argv[]) {
    double t;
    double phase=0.0, amplitude=2.0, f0=100;
    double T0=1/f0;
    //Your code starts here
    printf("Time(sec.)\tSample\n");
    for (t=0.0; t<=2*T0; t=t+1.0/FSAMPLE) {
        printf("%2.3f\t\t%2.2f\n",t,amplitude*sin(2*PI*f0*t+phase));
    }
    //Your code ends here
    return 0;
}
