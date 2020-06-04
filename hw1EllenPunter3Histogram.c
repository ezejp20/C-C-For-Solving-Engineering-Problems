/*
 ============================================================================
 Name        : hw1EllenPunter3.c
 Author      : Ellen Zehra
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	char fileName[]="/Users/jalepunter/Downloads/TuningAnalysisHomework1/histogram2.txt";
	float xf;
	int cnt=0;
	double freq[636];
	double dist[636];
	double signal[40000];
	int count=0;


	int n;
	int cntfreq=0;
	int cntdist=0;

	FILE *fp1;
	fp1=fopen(fileName,"r");
	if(fp1!=NULL){
		while(fscanf(fp1, "%f",&xf)==1){

			if (cnt%2==0){

				freq[(cntfreq)]=xf;
				cntfreq++;
			}
			else{
				dist[cntdist]=xf;
				cntdist++;
			}
			cnt++;
		}
//		int m;
//		double b;
//		for(m=0;m<636;m++){
//			b=dist[m];
//			printf("%3.5f\n",b);
//		}
//		for(m=0;m<636;m++){
//			b=freq[m];
//			printf("%3.5f\n",b);
//		}

		int a;
		for(a=1;a<635;a++){
			if(dist[a]>0.0085 && dist[a]>dist[(a-1)] && dist[a]>dist[(a+1)]){
				double f;
				f=freq[a];
				printf("%3.5f\n",f);
				double t;
				t=0;
				for(a=0;a<8000;a++){
					count++;
					double PI;
					PI=3.14159265358979323846;
					t=t+(1.0/8000);
					signal[a]=sin(2*PI*f*t);
				}
			}

		}
		fclose(fp1);
	}else{
		printf("File %s could not be opened\n", fileName);
	}
	char fileName2[]="/Users/jalepunter/Downloads/TuningAnalysisHomework1/tones.txt";
	FILE *fp2;
	fp2=fopen(fileName2,"w");
	if(fp2!=NULL){
		for(n=0;n<40000;n++){
			fprintf(fp2, "%f\n",signal[n]);
		}
		fclose(fp2);
	}
	else{

		printf("File %s could not be opened\n", fileName2);
	}

	return 0;
}
