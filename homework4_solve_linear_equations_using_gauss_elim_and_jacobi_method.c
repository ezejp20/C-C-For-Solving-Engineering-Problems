//
//  main.c
//  Homework4
//
//  Created by Ellen Punter on 11/03/16.
//  Copyright © 2016 Ellen Punter. All rights reserved.
//
#include <math.h>
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
        printf("Unknown %d found by Gauss-Jordan Elimination = %3.3f\n",(i+1),A(i,numCols-1)/A(i,i));
    }
}
#undef A
#undef C
#define NUMEQS 4
void jacobi(double a[NUMEQS][NUMEQS],double b[],int max_iter,double tol, double x[]){
    double x_prev[NUMEQS];double ratio,maxRatio;
    double sum;int cnt=0;
    //initial estimate
    for (int i=0; i<NUMEQS; i++) {
        x[i]=b[i]/a[i][i];
    }
    while (1) {
        cnt++;
        //back-up old estimates
        for (int i=0; i<NUMEQS; i++) {
            x_prev[i]=x[i];
        }
        //compute new values
        for (int i=0; i<NUMEQS; i++) {
            sum=0;
            for (int j=0; j<NUMEQS; j++) {
                if(i!=j){
                    sum+=a[i][j]*x_prev[j];
                }
            }
            x[i]=(b[i]-sum)/a[i][i];
        }
        //find max difference in updating
        maxRatio=0;
        for (int i=0; i<NUMEQS; i++) {
            ratio=fabs((x_prev[i]-x[i])/x[i]);
            if(ratio>maxRatio)
                maxRatio=ratio;
        }
        if(cnt>max_iter || maxRatio<tol){
            break;
        }
    }
}




int main(int argc, const char * argv[]) {
    const int numRows=4;//First do Gauss-Jordan elimination
    const int numCols=4;
    double a[numRows][numCols]={{10.0, 1.0, -0.5, 3.2},{1.0,15.0,3,2},{-2.5,3,12.0,3.4},{2,1,-0.5,-7.0}};
    double b[numRows]={5.2,12,-20,30};
    double c[numRows][numCols+1];
    printf("--Matrix A--\n");
    printMatrix(&a[0][0],numRows,numCols);printf("\n");
    createExtendedMat(&a[0][0],numRows,numCols,b,&c[0][0]);
    printf("--Extended Matrix--\n");
    printMatrix(&c[0][0],numRows,numCols+1);printf("\n");
    simple_GaussJordan(&c[0][0],numRows,numCols+1);
    

    double x[NUMEQS];//Jacobi iteration
    int max_iter=25;//max number of iterations
    double tol=0.001;//tolarence as ratio of consequitive estimates
    int j;
    jacobi(a,b,max_iter,tol,x);
    for (int i=0; i<NUMEQS; i++) {
        j=i+1;
        printf("Unknown %d found by Jacobi Iteration = %3.3f\n",j,x[i]);
    }
    return 0;
}
