//Lec 4: root finding
#include <stdio.h>
void findRoot(double (*f)(double),double xLimLeft, double xLimRight, double xStep, double *root){
    while(f(xLimLeft)*f(xLimRight)<0){
        xLimLeft=xLimLeft+xStep;
        xLimRight=xLimRight-xStep;
        if(xLimLeft>xLimRight){
            printf("Root could not be found");
        }
    }
    //check in which boundary there was sign change
    if (f(xLimLeft)*f(xLimLeft-xStep)<0) {
        *root=xLimLeft-xStep/2;
    }else
        *root=xLimRight+xStep/2;
}
double function1(double x){
    return x*x*x-4*x*x-4*x+15;
}
int main(int argc, const char * argv[]) {
    double root;
    findRoot(function1,-10.0,10.0,0.01,&root);
    printf("Root=%3.4f\n",root);
    return 0;
}
