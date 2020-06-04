//Lec 3
//Example: Multi-dimensional arrays as function arguments
#include <stdio.h>
#include <stdlib.h>
void printArray1d(short x[],int len){
	printf("One-dim matrix:\n");
	for(int i=0;i<len;i++){
		printf("%d\t",x[i]);
	}
	printf("\n\n");
}
void printArray2d(short x[][3],int nrows,int ncols){
	printf("Two-dim matrix:\n");
	for(int i=0;i<nrows;i++){
		for(int j=0;j<ncols;j++){
			printf("%d\t",x[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
//second version considering two-dim as a single dim array
//	this time we do not need to specify a dim of the array
void printArray2d_v2(short *x,int nrows,int ncols){
	printf("Two-dim matrix (pointer version):\n");
	for(int i=0;i<nrows;i++){
		for(int j=0;j<ncols;j++){
			printf("%d\t",*(x+i*ncols+j));
		}
		printf("\n");
	}
	printf("\n\n");
}
//third version, this time using a macro to simplify the syntax
#define X(I,J) (*(x+(I)*ncols+(J)))
void printArray2d_v3(short *x,int nrows,int ncols){
	printf("Two-dim matrix (pointer version with macro):\n");
	for(int i=0;i<nrows;i++){
		for(int j=0;j<ncols;j++){
			printf("%d\t",X(i,j));
		}
		printf("\n");
	}
	printf("\n\n");
}
#undef M
void printArray3d(short mat[][2][3],int x,int y,int z){
	printf("Three-dim matrix:------\n");
	for(int i=0;i<x;i++){
		printf("Sub-matrix%d\n",i);
		for(int j=0;j<y;j++){
			for(int k=0;k<z;k++){
				printf("%d\t",mat[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("------\n\n");
}
int main(void) {
	short array1d[]={5, 3, -6, 8};

	short array2d[][3]={
			{2, 1, -3},
			{5, 4, -8}
	};
	short array3d[4][2][3] = {
			{{ 0, 1, 2 }, { 3, 4, 5 }},
			{{ 6, 7, 8}, {9,10,11}},
			{{ 12, 13, 14}, { 15, 16, 17}},
			{{ 18, 19, 20 }, { 21, 22, 23 }}
	};

	//Implement printing functions for these arrays
	printArray1d(array1d,sizeof(array1d)/sizeof(short));
	printArray2d(array2d,2,3);
	printArray2d_v2(array2d[0],2,3);//or (&array2d[0][0],2,3)
	printArray2d_v3(&array2d[0][0],2,3);
	printArray3d(array3d,4,2,3);
	return 0;
}
