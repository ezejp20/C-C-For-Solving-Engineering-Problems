//Lec 4 - Numerical methods: Iterative solution of linear system of equations
#include <stdio.h>
#include <math.h>
//assume number of equations = number of unknowns
#define NUMEQS 3
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

int main() {
    
    double a[NUMEQS][NUMEQS]={{10,2,3},{1,5,2},{3,2,6}};
    double b[NUMEQS]={11,20,-12};
    double x[NUMEQS];
    int max_iter=20;//max number of iterations
    double tol=0.001;//tolarence as ratio of consequitive estimates
    
    jacobi(a,b,max_iter,tol,x);
    for (int i=0; i<NUMEQS; i++) {
        printf("%3.3f\n",x[i]);
    }
    return 0;
}
