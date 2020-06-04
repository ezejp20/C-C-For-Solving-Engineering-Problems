/*
 Brute force solution for linear set of equations
 See Lec2.pdf, pp. 39 for problem definition
 Lec2 example
 */

#include <stdio.h>

int main(void) {
	int i,j,k;
	for(i=1;i<99;i++){
		for(j=1;j<(100-i);j++){
			k=100-i-j;
			if((500*i+100*j+5*k)==10000)
				printf("%d %d %d\n",i,j,k);
		}
	}
	return 0;
}
