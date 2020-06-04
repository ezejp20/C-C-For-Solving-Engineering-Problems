//Lec 5 example: demonstration of struct, typedef and memory allocation for struct elements
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
	double real,imag;
}Complex;
void getMagnitude(const Complex *pComp,double *pAmp,int len){
	for(int i=0;i<len;i++)
		pAmp[i]=sqrt(pow(pComp[i].real,2)+pow(pComp[i].imag,2));
}
void printArray(double *pAmpArr,int len){
	for(int i=0;i<len;i++) printf("%3.3f\t",pAmpArr[i]);
	printf("\n");
}
int main(void) {
	int len;double real, imag;
	Complex *pCompArr;
	double *pAmpArr;
	printf("Input number of elements:");scanf("%d",&len);
	pCompArr=(Complex *)malloc(sizeof(Complex)*len);
	if(pCompArr!=NULL){
		//Reading complex elements in to array of Complex
		for(int i=0;i<len;i++){//reading complex valued inputs
			printf("\n%dth element, ",(i+1));
			printf("Real part: ");scanf("%lf",&real);
			printf("Imaginary part: ");scanf("%lf",&imag);
			Complex c={real,imag};
			*(pCompArr+i)=c;
		}
		//computing the amplitude array
		pAmpArr=(double*)malloc(sizeof(double)*len);
		getMagnitude(pCompArr,pAmpArr,len);
		printArray(pAmpArr,len);
		free(pAmpArr);
		free(pCompArr);
	}
	return 0;
}
