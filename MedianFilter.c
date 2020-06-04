#include <stdio.h>
#include <stdlib.h>
#define NUM_ROWS 1601
#define NUM_COLS 4
#define M(I,J) (*(m+(I)*NUM_COLS+(J)))
#define N(I,J) (*(n+(I)*NUM_COLS+(J)))
void swap(double x[],int ind1,int ind2){
	double temp=x[ind1];
	x[ind1]=x[ind2];x[ind2]=temp;
}
void bubbleSort(double x[],int len){
	for (int pass=0; pass<len-1; pass++) {
		for (int k=0; k<(len-pass-1); k++) {
			if(x[k]>x[k+1]){
				swap(x,k,k+1);
			}
		}
	}
}
void copyColumnElements(double *array,double *m,int rowInd,int colInd,int numPoints){
	for(int i=0;i<numPoints;i++){
		array[i]=M(i+rowInd,colInd);
	}
}
void copyMat(double *n, double *m,int numRows, int numCols){
	for (int i=0; i<numRows; i++) {
		for (int j=0;j<numCols; j++) {
			N(i,j)=M(i,j);
		}
	}
}
void readFileIntoMat(FILE *fpt, double *m,int numRows, int numCols){
	for (int i=0; i<numRows; i++) {
		for (int j=0;j<numCols; j++) {
			fscanf(fpt,"%lf",&M(i,j));
		}
	}
	fclose(fpt);
}
void printMat2file(FILE *fpt,double *m,int numRows, int numCols){
	for (int i=0; i<numRows; i++) {
		for (int j=0;j<numCols; j++) {
			fprintf(fpt,"%3.4f\t",M(i,j));
		}
		fprintf(fpt,"\n");
	}
	fclose(fpt);
}
void medianFiltMat(double *n,double *m,int numRows, int numCols,int numPoints){
	int arrayLen=2*numPoints+1;
	double temp[arrayLen];

	for (int j=0;j<numCols; j++) {
		for (int i=0; i<numRows-arrayLen; i++) {
			copyColumnElements(temp,m,i,j,arrayLen);
			bubbleSort(temp,arrayLen);
			N(i+numPoints,j)=temp[numPoints+1];
		}
	}
}
#undef M
#undef N

int main(void) {
	double mat[NUM_ROWS][NUM_COLS],newMat[NUM_ROWS][NUM_COLS];
	int numPoints=2;
	FILE *inFptr=fopen("sig4Channel.txt","r");
	if(inFptr!=NULL){
		FILE *outFptr=fopen("out.txt","w");
		readFileIntoMat(inFptr,&mat[0][0],NUM_ROWS,NUM_COLS);
		copyMat(&newMat[0][0],&mat[0][0],NUM_ROWS,NUM_COLS);
		medianFiltMat(&newMat[0][0],&mat[0][0],NUM_ROWS,NUM_COLS,numPoints);
		printMat2file(outFptr,&newMat[0][0],NUM_ROWS,NUM_COLS);
	}else{
		printf("Could not open file to read");
	}
	printf("End of program");
	return 0;
}
