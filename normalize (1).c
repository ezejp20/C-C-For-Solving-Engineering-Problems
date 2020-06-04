//Lec3: Example for demonstrating pipe in command-line running of programs
#include <stdio.h>
#include <math.h>
#define SIZE 500000
void normalize(float *pData,int size, float maxValue);
int main(void) {
	float array[SIZE],tempF;
	long cnt=0,numRead;
    array[SIZE-1]=0;
	while(1){
		numRead=scanf("%f",&tempF);
		if(numRead>0 && cnt<SIZE){
			array[cnt++]=tempF;
		}else{
			break;
		}
    }
	normalize(array,cnt,0.9);
    //writing array to output
    for (int i=0; i<cnt; i++) {
        printf("%3.10f\n",array[i]);
    }
	return 0;
}
void normalize(float *pData,int size, float maxValue){
    //find maximum value
    float maxInData=*pData;//set to first value
	for(long i=1;i<size;i++){
        if(*(pData+i)>maxInData )
            maxInData=*(pData+i);
	}
    //normalize the signal
    float ratio=maxValue/maxInData;
    for(long i=0;i<size;i++){
        *(pData+i)=*(pData+i)*ratio;
    }
}
