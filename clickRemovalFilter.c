//Lec3: Example for demonstrating stderr
#include <stdio.h>
#include <math.h>
#define SIZE 500000
void removeClicks(float *pData,int size);
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
    fprintf(stderr,"Number of data read:%lu\n",cnt);
	removeClicks(array,cnt);
    //writing array to output
    for (int i=0; i<cnt; i++) {
        printf("%3.10f\n",array[i]);
    }
	return 0;
}
void removeClicks(float *pData,int size){
    float diffPrev, diffPost;
	for(long i=1;i<(size-1);i++){
        diffPrev=fabs(*(pData+i) - *(pData+i-1));
        diffPost=fabs(*(pData+i) - *(pData+i+1));
        if(diffPrev>0.4 && diffPost>0.4){
            fprintf(stderr,"Click found at index:%lu\n",i);
            *(pData+i)=(*(pData+i-1) + *(pData+i+1))/2;
        }
	}
}
