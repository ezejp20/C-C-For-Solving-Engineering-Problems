/*
 Computing permutations
 
 Lec1 example
 */

#include <stdio.h>
#include <stdlib.h>

//factorial may quickly get larger than int boundaries, use long instead
//Your code starts here
long factorial(int x){
	long fact=1;
	for(int i=1;i<=x;i++)
		fact*=i;
	return fact;
}
long permutation(int x, int y){
	//To be corrected using the formula
	return factorial(x)/factorial(x-y);
}
//Your code ends here
int main(void) {
	int x,y;
	puts("Specify x:");scanf("%i",&x);
	puts("Specify y:");scanf("%i",&y);
	printf("P(%i,%i)=%li\n",x,y,permutation(x,y));
	return 0;
}
