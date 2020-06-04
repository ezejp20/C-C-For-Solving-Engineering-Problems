//Lec 3
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	clock_t begin, end;
	double timeSpent;//time in seconds

	begin = clock();
	//your time consuming task goes here
	end = clock();
	timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time spent: %3.5f seconds\n",timeSpent);
	return 0;
}
