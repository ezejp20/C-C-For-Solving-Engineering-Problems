/*
 ============================================================================
 Name        : test.c Author      : Ellen Zehra
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *histFile = fopen("histogram2.txt", "r");
	FILE *tonesFile = fopen("tones.txt", "ab+");
    int data[540];

    int i=0;
    int num;
    while(fscanf(histFile, "%d", &num) > 0) {
        int data[i] = num;
        i++;
    }
	double freq[270];
	double dist[270];
	int a;
	for(a=0;a<540;a++){
		if (a%2==0){
			freq[(a/2)]=data[a];
		}
		else{
		dist[((a-1)/2)]=data[a];
		}
	for(a=0;a<270;a++){
		if(dist[a]>0.0085 && dist[a]>dist[(a-1)] && dist[a]>dist[(a+1)]){
			int f;
			int a;
			int f=freq[a];
			printf("%d",f);
				int n=sin(2*3.14*f(1/(8000)));
				fprintf(tonesFile, "%d", n);
		}
    fclose(histFile);
    fclose(tonesFile);

	}
    return 0;
	}
}

