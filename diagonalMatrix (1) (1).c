//Lec 3: Multi-dimensional arrays
#include <stdio.h>
//initialize array with zero entries
void zeros(int *mat,int nrows,int ncols){
    for (int i=0; i<nrows; i++) {
        for (int j=0;j<ncols; j++) {
            *(mat+i*ncols+j)=0;
        }
    }
}
void printMatrix(const int *mat,int nrows,int ncols){
    for (int i=0; i<nrows; i++) {
        for (int j=0;j<ncols; j++) {
            printf("%d\t",*(mat+i*ncols+j));
        }
        printf("\n");
    }
}
int isDiagonal(int *mat,int nrows,int ncols){
    for (int i=0; i<nrows; i++) {
        for (int j=0;j<ncols; j++) {
            if(*(mat+i*ncols+j)!=0 && i!=j){
                return 0;
            }
        }
    }
    return 1;
}
int main() {
    int nrows=4, ncols=4;
    int mat[nrows][ncols];
    //creating a diagonal matrix
    zeros(&mat[0][0],nrows,ncols);
    for (int i=0; i<ncols; i++) {
        mat[i][i]=i;
    }
    printMatrix(&mat[0][0],nrows,ncols);
    if(isDiagonal(&mat[0][0],nrows,ncols)){
        printf("Matrix is diagonal\n");
    }else{
        printf("Matrix is not diagonal\n");
    }
    return 0;
}
