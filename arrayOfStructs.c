//Lec 5 example: Arrays of structs
#include <stdio.h>
#include <stdlib.h>
typedef struct{double x;double y;}Point;
void printArray(const Point p[],int len){
	for(int i=0;i<len;i++){
		printf("(%2.1f,%2.1f)\t",p[i].x,p[i].y);
	}
	printf("\n");
}
//version with pointers. implemented for demo purposes
void printArray2(const Point *p,int len){
	for(int i=0;i<len;i++){
		printf("(%2.1f,%2.1f)\t",p->x,p->y);p++;
	}
	printf("\n");
}
void initializeArray(Point p[],int len){
	for(int i=0;i<len;i++){
		p[i].x=0;p[i].y=0;
	}
}
int main(void) {
	Point pointArray[5];
	int numElements=sizeof(pointArray)/sizeof(Point);
	initializeArray(pointArray,numElements);
	printArray(pointArray,numElements);
	printArray2(pointArray,numElements);
	return 0;
}
