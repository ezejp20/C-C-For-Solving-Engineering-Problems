//Example from "An Introduction to the C Programming Language and Software Design, by Tim Bailey"
//Lec 4 example
#include <stdio.h>
#include <assert.h>
double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a-b; }
double mult(double a, double b) { return a * b; }
double divide(double a, double b) { assert(b != 0.0); return a / b; }

int main(void)
{
    int i;
    double val1, val2;
    double (*pf[ ])(double,double) = { add, sub, mult, divide };
    
    printf("Enter two floating-point values, and an integer between 0 and 3: ");
    scanf("%lf%lf%d", &val1, &val2, &i);
    if (i<0 || i>3) i = 0;
    
    printf("Performing operation %d on %3.2f and %3.2f equals %3.2f\n",
           i, val1, val2, pf[i](val1, val2));
}
