//Lec 5 example: use of static variable
#include <stdio.h>
void func(void);/* function declaration */
static int count = 5;/* global variable */
main() {
	while(count--) {
		func();
	}
	return 0;
} /* function definition */
void func( void ) {
	static int i = 5;/* local static variable */
	i++;
	printf("i is %d and count is %d\n", i, count);
}
