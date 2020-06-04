#include <stdio.h>
#include <math.h>
#define TWOPI 6.2832

int main() {
    double amp1, freq1,amp2, freq2;
    double currentVal;
    printf("Input amplitude for the first signal:");
    scanf("%lf",&amp1);
    printf("Input frequency for the first signal:");
    scanf("%lf",&freq1);
    printf("Input amplitude for the second signal:");
    scanf("%lf",&amp2);
    printf("Input amplitude for the second signal:");
    scanf("%lf",&freq2);
    
    FILE *fptr=fopen("out.txt", "w");
    //duration is not given in the question, so let's use 1 sec
    for (double t=0; t<=1.0; t+=1.0/10000) {
        currentVal=amp1*sin(TWOPI*freq1*t)+amp2*sin(TWOPI*freq2*t);
        fprintf(fptr, "%3.4f\n",currentVal);
    }
    fclose(fptr);
    return 0;
}
