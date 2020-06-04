//Lec3: Demonstration of arguments of the main() method
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("-------\n");
	for(int i=0;i<argc;i++){
		printf("Argv[%d]: %s\n",i,argv[i]);
	}
	printf("-------\n");
	return 0;
}
