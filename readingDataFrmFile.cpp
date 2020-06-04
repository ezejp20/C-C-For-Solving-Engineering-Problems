#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *histFile = fopen("histogram2.txt", "r");
	FILE *tonesFile = fopen("tones.txt", "ab+");
    int data[540];

    int i=0;
    int num;
    while(fscanf(histFile, "%d", &num) > 0) {
        integers[i] = num;
        i++;
    }
	double freq[270];
	double dist[270];
	for(a=0;a<540;a++){
		if (a%2==0){
			freq[(a/2)]=data[a];
		}
		else{
		dist[((a-1)/2)]=data[a];
		}
	for(a=0;a<270;a++){
		if(dist[a]>0.0085 && dist[a]>dist[(a-1)] && dist[a]>dist[(a+1)]){
			int f=freq[a];
			printf("%d",f);
			for(i=0;i<8000;i++){
				fprintf(tonesFile, "%d", i);
			}
			
		}
    fclose(histFile);
    fclose(tonesFile);
	
	}
    return 0;

}

