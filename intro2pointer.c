//Lec 3: Intro to pointers, simplest example

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int var=20;
	int *p;
	p=&var;

	printf("Address of var: %x\n",&var);
	printf("Address pointed by p: %x\n",p);

	printf("Content at address pointed by p:%d\n",*p);

	return 0;
}
