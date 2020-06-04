/*
 FileCopying_ChByCh.c
 
 Lec1 example
 */

#include <stdio.h>

int main() {
	char c;
	while((c=getchar())!=EOF){
		putchar(c);
	}
	return 0;
}
