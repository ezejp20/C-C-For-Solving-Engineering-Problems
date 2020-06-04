/*
 Demonstration of sizeof()
 
 Lec1 example
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("Size of variables on this machine:");
	printf("Double : %lu bytes\n",sizeof(double));
	printf("Float : %lu bytes\n",sizeof(float));
	printf("Short : %lu bytes\n",sizeof(short));
	printf("Int : %lu bytes\n",sizeof(int));
	printf("Unsigned int : %lu bytes\n",sizeof(unsigned int));
	printf("Long : %lu bytes\n",sizeof(long));
	printf("Char : %lu bytes\n",sizeof(char));
	return 0;
}
