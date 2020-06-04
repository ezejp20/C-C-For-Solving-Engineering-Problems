//Lec3: Image processing example (use of multi-dimensional arrays)
#include <stdio.h>
#include <math.h>
#define MATSIZE 128//assume the matrix size is given
#define MAX_COLOR 64//max val for color map
#define M(I,J) (*(m+(I)*numCols+(J)))
#define N(I,J) (*(n+(I)*numCols+(J)))
void printMatToFile(const char filename[],const int *m,int numRows, int numCols){
    FILE *fp1;fp1=fopen(filename,"w");
    for (int i=0; i<numRows; i++) {
        for (int j=0;j<numCols; j++) {
            if(j==numCols-1)
                fprintf(fp1,"%d\n",M(i,j));
            else
                fprintf(fp1,"%d,",M(i,j));
        }
    }
    fclose(fp1);
}
void enhanceEdgesInMat(int *n,const int *m,int numRows, int numCols){
    int maxVal=0;
    for (int i=0; i<numRows; i++) {
        for (int j=0;j<numCols; j++) {
            //set boundary elements to zero
            if (i==0 || j==0 || i==numRows-1 || j==numCols-1) {
                N(i,j)=0;
            }else{
                N(i,j)=fabs(((M(i-1, j-1)+M(i-1, j)+M(i-1, j+1)+M(i+1, j-1)+M(i+1, j)+M(i+1, j+1)+M(i, j-1)+M(i, j+1))/8-M(i,j)));
            }
            maxVal=(maxVal>N(i,j)) ? maxVal : N(i,j);
        }
    }
    //normalize and subtract from MAX_COLOR(because 0 is black and MAX_COLOR is white)
    for (int i=0; i<numRows; i++) {
        for (int j=0;j<numCols; j++) {
            N(i,j)=MAX_COLOR-N(i,j)*MAX_COLOR/maxVal;
        }
    }
}
#undef M
void readFileToNByNMat(char filename[],int array[][MATSIZE], int maxLen){
    FILE *fp1;fp1=fopen(filename,"r");
    if(fp1!=NULL){
        for (int i=0; i<MATSIZE; i++) {
            for (int j=0;j<MATSIZE; j++) {
                fscanf(fp1,"%d,",&array[i][j]);
            }
        }
        fclose(fp1);
    }else{
        printf("File %s could not be opened\n", filename);
    }
}
int main() {
    int orgMat[MATSIZE][MATSIZE],newMat[MATSIZE][MATSIZE];
    char filename[]="lena.txt",outfile[]="out.txt";
    readFileToNByNMat(filename,orgMat,MATSIZE);
    enhanceEdgesInMat(&newMat[0][0],&orgMat[0][0],MATSIZE,MATSIZE);
    printMatToFile(outfile,&newMat[0][0],MATSIZE,MATSIZE);
    return 0;
}
