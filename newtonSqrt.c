//Square root using Newton's method
//Lec2 example
#include <stdio.h>
#include <math.h>

double newtonSqrt(double x){
    double guess=x/2;
    do{
        guess=(guess+x/guess)/2;
        printf("guess = %4.4f\n",guess);
    } while(fabs(guess*guess-x)>(x/1000));
    
    return guess;
}
int main() {
    double x=257.345;
    printf("sqrt of %4.4f = %4.4f\n",x,newtonSqrt(x));
    return 0;
}