//Lec 3 example: Read-write via piping on terminal
//  compile using terminal and run:
//  >>readWriteMatOnSTDout < lena.txt > out.txt
#include <stdio.h>
#define MATSIZE 128
#define M(I,J) (*(m+(I)*numCols+(J)))
void printMat(int *m,int numRows, int numCols){
    for (int i=0; i<numRows; i++) {
        for (int j=0;j<numCols; j++) {
            if(j==numCols-1)
                printf("%d\n",M(i,j));
            else
                printf("%d,",M(i,j));
        }
    }
}
#undef M
int main() {
    int orgMat[MATSIZE][MATSIZE];
    for (int i=0; i<MATSIZE; i++) {
        for (int j=0;j<MATSIZE; j++) {
            scanf("%d,",&orgMat[i][j]);
        }
    }
    printMat(&orgMat[0][0],MATSIZE,MATSIZE);
    return 0;
}
