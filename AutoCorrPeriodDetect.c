#include <stdio.h>
#include <math.h>
#define WINSIZE 2000
#define WINSHIFT 500
#define MAXNUMWINDOW 100
#define MAXT0 3000
#define MINT0 200
#define SAMPLINGFREQ 1000

void writeToFile(char filename[],double x[],int numData){
    FILE *fptr=fopen(filename, "w");
    for(int i=0;i<numData;i++){
        fprintf(fptr, "%3.4f\n",x[i]);
    }
    fclose(fptr);
}
int readFrame(FILE *fptr,double x[],int frameLen,int frameShift){
    double data;
    
    for (int i=0;i<(frameLen-frameShift); i++) {
        x[i]=x[i+frameShift];
    }
    //reading new data
    for (int i=0; i<frameShift; i++) {
        int numRead=fscanf(fptr,"%lf\n",&data);
        if(numRead>0){
            x[i+(frameLen-frameShift)]=data;
        }else{
            fclose(fptr);return 0;
        }
    }
    return (frameLen-frameShift);
}
//returns the index of the peak in the region
int findPeakInRegion(double r[],int lowLimit,int highLimit){
    double peakVal=r[lowLimit];
    int maxIndex=lowLimit;
    for (int i=lowLimit+1; i<=highLimit; i++) {
        if(peakVal<r[i]){
            peakVal=r[i];maxIndex=i;
        }
    }
    return maxIndex;
}
double detectPeriodAutoCorr(double x[]){
    //computing autocorrelation
    double r[WINSIZE];
    for (int n=0; n<WINSIZE; n++) {
        double sum=0;
        for (int k=0; k<WINSIZE-n; k++) {
            sum+=x[k]*x[k+n];
        }
        r[n]=sum/WINSIZE;
    }
    //finding the peak
    int maxInd=findPeakInRegion(r,MINT0,fmin(MAXT0,WINSIZE-1));
    double bmp=(double)SAMPLINGFREQ*60/maxInd;
    return bmp;
}

int main() {
    double x[WINSIZE], bmp[MAXNUMWINDOW];
    char filename[]="ecgSig2.txt";
    int numFrames=0;
    FILE *fptr;
    fptr=fopen(filename,"r");
    if(fptr!=NULL){
        while(readFrame(fptr,x,WINSIZE,WINSHIFT)){
            numFrames++;
            if(numFrames>=MAXNUMWINDOW){
                fclose(fptr);break;
            }
            /*the array gets filled only after the first WINSIZE/WINSHIFT loops*/
            if(numFrames>=(WINSIZE/WINSHIFT)){
                bmp[numFrames-(WINSIZE/WINSHIFT)]=detectPeriodAutoCorr(x);
            }
        }
        writeToFile("out.txt",bmp,numFrames-(WINSIZE/WINSHIFT)+1);
    }else{
        printf("Error in reading file\n");
    }
    return 0;
}
