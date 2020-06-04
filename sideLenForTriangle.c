/*
Example for use of math functions: finding side length of a triangle
 Lec1 example
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14//!! no semi-colons(;) needed

int main(void) {
	float a,b,c,alpha,alpha_rad;
	puts("b=? ");scanf("%f",&b);
	puts("c=? ");scanf("%f",&c);
	puts("alpha=?(degrees) ");scanf("%f",&alpha);
	alpha_rad=PI*alpha/180;
	a=sqrt(pow(b,2)+pow(c,2)-2*b*c*cos(alpha_rad));
	printf("Third side length=%3.5f\n",a);
	return 1;
}
