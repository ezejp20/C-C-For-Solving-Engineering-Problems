
#include <stdio.h>
#define ARRAY_LEN 100000

void conv(double x[], double h[],double *y, long len_x, long len_h);
void initArray(double *x,long len);
void copyArray(double source[],double *target,long len);
long readArrayFromFile(char filename[],double *array, long maxLen);

int main() {
    double x[ARRAY_LEN/2], h[ARRAY_LEN/2];
    double y[ARRAY_LEN];
    char filename_x[]="/Users/barisbozkurt/Documents/DERSLER/C/data/guitarRecording/guitarRecording_11025.txt";
    char filename_h[]="/Users/barisbozkurt/Documents/DERSLER/C/data/impulseCathedral/impulse_cathedral_11025.txt";
    long len_x=readArrayFromFile(filename_x,x,ARRAY_LEN/2);
    long len_h=readArrayFromFile(filename_h,h,ARRAY_LEN/2);
    
    conv(x,h,y,len_x,len_h);
    //will write to file using pipe: ./main > out.txt
    for (long i=0; i<len_x+len_h; i++) {
        printf("%4.10f\n",y[i]);
    }
    
    return 0;
}

void conv(double x[], double h[],double *y, long len_x, long len_h){
    double tempX[ARRAY_LEN], tempH[ARRAY_LEN];
    long totalLen=len_x+len_h-1;
    initArray(tempX,totalLen);initArray(tempH,totalLen);
    copyArray(x,tempX,len_x);copyArray(h,tempH,len_h);
    for (long n=0; n<(len_h+len_x-1); n++) {
        *(y+n)=0;
        for (long k=0; k<len_x; k++) {
            if(n-k>=0){
                *(y+n)=*(y+n)+tempX[k]*tempH[n-k];
            }
        }
    }
}
void initArray(double *x,long len){
    for (long i=0; i<len; i++) {
        *(x+i)=0.0;
    }
}
void copyArray(double source[],double *target,long len){
    for (long i=0; i<len; i++) {
        *(target+i)=source[i];
    }
}
long readArrayFromFile(char filename[],double *array, long maxLen){
    
    float xf;
    long cnt=0;
    
    FILE *fp1;
    fp1=fopen(filename,"r");
    if(fp1!=NULL){
        while(fscanf(fp1, "%f",&xf)==1 && cnt<maxLen){
            *(array+cnt)=xf;
            cnt++;
        }
        fclose(fp1);
    }else{
        printf("File %s could not be opened\n", filename);
    }
    return cnt;
}