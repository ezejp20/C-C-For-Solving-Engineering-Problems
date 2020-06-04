/*
 Example for use of math functions: root finding for a second order polynomial
 Lec1 example
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>//includes for pow() and sqrt() methods

float discriminant(float a,float b,float c){
	return pow(b,2)-4*a*c;
}
int main(void) {
	float a,b,c, discr;//polynomial coefficients
	float root1,root2;//polynomial coefficients
	a=b=c=discr=0.0;//initialization
	puts("Specify polynomial coefficients for a second order polynomial:");
	puts("Coeff. for x^2:");scanf("%f",&a);
	puts("Coeff. for x:");scanf("%f",&b);
	puts("Coeff. for 1:");scanf("%f",&c);
	discr=discriminant(a,b,c);
	printf("%3.3f\n",discr);
	if(discr<0){
		puts("Complex roots:");
	}else if(discr==0){
		puts("Repeated roots:");
	}else{
		puts("Real, distinct roots:");
		root1=(-b+sqrt(discr))/(2*a);
		root2=(-b-sqrt(discr))/(2*a);
		printf("%3.3f\t%3.3f\n",root1,root2);
	}
	return 0;
}
