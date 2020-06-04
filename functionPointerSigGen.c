//Lec 4: Function pointer example
#include <stdio.h>
#include <math.h>
#define MAXLEN 10000
#define TWOPI 6.2832

//Your code starts here
void createSignal(double (*f)(double), double x[], double Amplitude,double frequency,double phase, int Fsample){
    double t, delta_t=1.0/Fsample;

    for (int i=0; i<MAXLEN; i++) {
        t=i*delta_t;
        x[i]=f(TWOPI*frequency*t+phase);
    }
}
//Your ends starts here
double cosine(double theta){
    return cos(theta);
}
double sine(double theta){
    return sin(theta);
}
double squareWave(double theta){
    double remainder;
    int division;
    division = (int)(theta/(TWOPI));
    remainder=theta-(division*TWOPI);
    if (remainder<(TWOPI/2)) {
        return 1;
    }else{
        return 0;
    }
    
    return 0;
}
void writeToFile(char filename[],double x[]){
    FILE *fptr=fopen(filename, "w");
    for(int i=0;i<MAXLEN;i++){
        fprintf(fptr, "%3.4f\n",x[i]);
    }
    fclose(fptr);
}
int main(int argc, const char * argv[]) {
    double x[MAXLEN];
    createSignal(cosine,x,10,200,0,10000);
    writeToFile("cosine.txt",x);
    createSignal(sine,x,10,200,0,10000);
    writeToFile("sine.txt",x);
    createSignal(squareWave,x,10,200,0,10000);
    writeToFile("square.txt",x);
    return 0;
}
