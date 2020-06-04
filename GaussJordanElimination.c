//Lec 4
#include <stdio.h>
#define A(I,J) (*(a+(I)*numCols+(J)))
#define C(I,J) (*(c+(I)*(numCols+1)+(J)))
void createExtendedMat(double *a,int numRows,int numCols,
                       double b[],double *c){
    for (int i=0; i<numRows; i++) {
        for (int j=0; j<numCols; j++) {
            C(i,j)=A(i,j);
        }
        C(i,numCols)=b[i];
    }
}
void printMatrix(double *a,int numRows,int numCols){
    for (int i=0; i<numRows; i++) {
        for (int j=0;j<numCols; j++) {
            printf("%3.3f\t",A(i,j));
        }
        printf("\n");
    }
}
void simple_GaussJordan(double *a,int numRows,int numCols){
    double m;//row scaling factor
    for (int ref=0; ref<numRows; ref++) {
        for (int modif=0; modif<numRows; modif++) {
            if(modif!=ref){
                m=A(ref,ref)/A(modif,ref);
                for (int j=0; j<numCols; j++) {
                    A(modif, j)-=A(ref,j)/m;
                }
            }
        }
        printf("--%dth row removed--\n",(ref+1));
        printMatrix(a,numRows,numCols);
    }
    //solving from diagonal matrix
    for (int i=0; i<numRows; i++) {
        printf("%dth unknown = %3.3f\n",(i+1),A(i,numCols-1)/A(i,i));
    }
}
#undef A
#undef C

int main() {
    const int numRows=3;
    const int numCols=3;
    double a[numRows][numCols]={{2,3,5},{1,2,4},{4,7,3}};
    double b[numRows]={10,5,15};
    double c[numRows][numCols+1];
    printf("--Matrix A--\n");
    printMatrix(&a[0][0],numRows,numCols);printf("\n");
    createExtendedMat(&a[0][0],numRows,numCols,b,&c[0][0]);
    printf("--Extended Matrix--\n");
    printMatrix(&c[0][0],numRows,numCols+1);printf("\n");
    simple_GaussJordan(&c[0][0],numRows,numCols+1);
    
    return 0;
}
