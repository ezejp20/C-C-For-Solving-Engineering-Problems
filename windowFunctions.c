#include <stdio.h>
#include <math.h>
#define WIN_LEN 100
#define PI 3.1416

//Your code starts here
void createWindow(double (*f)(double,double), double x[], int N){
    for (int i=0; i<N; i++) {
        x[i]=f((double)i,(double)N);
    }
}
//Your ends starts here
double triangle(double n,double N){
    return 1-fabs(n-(N-1)/2)/(N/2);
}
double hanning(double n,double N){
    return 0.5*(1-cos(2*PI*n/(N-1)));
}
double hamming(double n,double N){
    return 0.54+0.46*(1-cos(2*PI*n/(N-1)));
}
void writeToFile(char filename[],double x[]){
    FILE *fptr=fopen(filename, "w");
    for(int i=0;i<WIN_LEN;i++){
        fprintf(fptr, "%3.4f\n",x[i]);
    }
    fclose(fptr);
}
int main() {
    double x[WIN_LEN];
    createWindow(triangle,x,WIN_LEN);
    writeToFile("triangle.txt",x);
    createWindow(hanning,x,WIN_LEN);
    writeToFile("hanning.txt",x);
    createWindow(hamming,x,WIN_LEN);
    writeToFile("hamming.txt",x);
    return 0;
}
