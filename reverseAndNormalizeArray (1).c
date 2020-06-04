//Lec 3 example for arrays
#include <stdio.h>
#define MAX_LEN 2000
void normalizeArray(float x[],int len){
    //finding the sum
    float sum=0.0;
    for (int i=0; i<len; i++) {
        sum+=x[i];
    }
    //scaling such that sum=1
    for (int i=0; i<len; i++) {
        x[i]/=sum;
    }
}
void reverseArray(float x[],int len){
    float temp;
    for (int i=0; i<len/2; i++) {
        temp=x[i];x[i]=x[len-1-i];
        x[len-1-i]=temp;
    }
}
void writeToFile(char fileName[],float x[],int len){
    FILE *fptr=fopen(fileName, "w");
    for(int i=0;i<len;i++){
        fprintf(fptr, "%3.4f\n",x[i]);
    }
    fclose(fptr);
}
int main() {
    char fileName[]="histogram.txt";
    float xf, histogram[MAX_LEN];
    int cnt=0;
    
    FILE *fp1;
    fp1=fopen(fileName,"r");//openning with read permission
    if(fp1!=NULL){
        while(fscanf(fp1, "%f",&xf)==1){
            histogram[cnt++]=xf;
        }
        fclose(fp1);
        //data read in histogram array, time to process it
        normalizeArray(histogram,cnt);
        reverseArray(histogram,cnt);
        writeToFile("histogram_reversed_normalized.txt",histogram,cnt);
    }else{
        printf("File %s could not be opened\n", fileName);
    }
    return 0;
}
