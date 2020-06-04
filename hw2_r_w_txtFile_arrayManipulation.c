//
//  main.c
//  testc
//
//  Created by Ellen Punter on 02/03/16.
//  Copyright © 2016 Ellen Punter. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    FILE *guitarFile = fopen("/Users/jalepunter/Documents/workspace/guitarRecording/guitarRecording_11025.txt", "r");
    if (guitarFile == NULL)
    {
        printf("Error opening guitar file!\n");
        exit(1);
    }
    FILE *modifiedFile= fopen("modified.txt", "w");
    if (modifiedFile == NULL)
    {
        printf("Error opening modified file!\n");
        exit(1);
    }
    double originalSamples[101631];
    int i=0;
    int j=0;
    int m=0;
    int p=0;
    float num;
    if(guitarFile!=NULL){
    while(fscanf(guitarFile, "%f", &num) > 0) {
        originalSamples[i] = num;
        i++;
    }
    }
    double finalSig[101631];
    for(i=0;i<101631;i++){
        finalSig[i]=originalSamples[i];
    }
    int delayValues[5];
    double gains[5];
    int correct=0;
    int correct2=0;
    int delaySamp;
    int Fs=11025;
    double temp[101631];
    
    printf ("Enter 5 delay values between 50-80 milliseconds: ");
    for(i=0;i<5;i++){
    scanf ("%d", &delayValues[i]);
    }
//    for(i=0;i<5;i++){
//    printf("%d\n",delayValues[i]);
//    }
    
    while(correct==0){
    for(i=0;i<5;i++){
        if(delayValues[i]<=80 && delayValues[i]>=50){
            correct=1;
        }
        else{
            printf("Delay values must be between 50-80 milliseconds, enter new delay values: ");
            for(i=0;i<5;i++){
            scanf ("%d", &delayValues[i]);
            }
        }
    }
    }
    printf ("Enter corresponding gains: ");
    for(i=0;i<5;i++){
    scanf ("%lf", &gains[i]);
    }
    while(correct2==0){
        for(i=0;i<5;i++){
            if(gains[i]<1.0){
                correct2=1;
            }
            else{
                printf("Gain values must be less than 1, enter new gain values: ");
                for(i=0;i<5;i++){
                scanf ("%lf", &gains[i]);
                }
            }
        }
    }

    for(i=0;i<101631;i++){
        temp[i]=originalSamples[i];
    }//creating temporary array which is the same as the original sample
    for(i=0;i<5;i++){//for each delay value:
        delaySamp=(delayValues[i]*Fs/1000);//finding number of spaces to shift each delay by
        for(j=0;j<101631;j++){
            temp[j]=(temp[j]*gains[i]);//mutliplying each value by corresponding gain value
        }
        for(m=0;m<101631-delaySamp;m++){
            temp[m]=temp[m-delaySamp];//shifting values by delay
            for(p=0;p<delaySamp;p++){//setting first few values to zero
                temp[p]=0;
            }
        }
        finalSig[i]=finalSig[i]+temp[i];
    }
    if(modifiedFile!=NULL){
    for(i=0;i<101631;i++){
    fprintf(modifiedFile, "%lf", finalSig[i]);
    printf("%lf", finalSig[i]);
    }
    }
    
    fclose(modifiedFile);
    fclose(guitarFile);
    return 0;
}
