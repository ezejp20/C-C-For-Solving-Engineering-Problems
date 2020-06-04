//
//  main.c
//  homework3
//
//  Created by Ellen Punter on 07/03/16.
//  Copyright © 2016 Ellen Punter. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void quicksort(int x[10],int first,int last){//quick-sort method
    int pivot,j,temp,i;
    
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        
        while(i<j){
            while(x[i]<=x[pivot]&&i<last)
                i++;
            while(x[j]>x[pivot])
                j--;
            if(i<j){
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
        
        temp=x[pivot];
        x[pivot]=x[j];
        x[j]=temp;
        quicksort(x,first,j-1);
        quicksort(x,j+1,last);
        
    }
}
void shellSort(int numbers[], int array_size)
{
    int i, j, increment, temp;
    
    increment = array_size / 2;
    while (increment > 0)
    {
        for (i=0; i < array_size; i++)
        {
            j = i;
            temp = numbers[i];
            while ((j >= increment) && (numbers[j-increment] > temp))
            {
                numbers[j] = numbers[j - increment];
                j = j - increment;
            }
            numbers[j] = temp;
        }
        if (increment == 2)
            increment = 1;
        else 
            increment = increment * 5 / 11;
    }
}
void swap(int x[],int ind1,int ind2){
    int temp=x[ind1];
    x[ind1]=x[ind2];x[ind2]=temp;
}
void bubbleSort(int x[],int len){
    for (int pass=0; pass<len-1; pass++) {
        for (int k=0; k<(len-pass-1); k++) {
            if(x[k]>x[k+1]){
                swap(x,k,k+1);
            }
        }
    }
}
void selectionSort(int x[],int len){
    for (int j=0; j<len; j++) {
        int min=x[j], ind=j;
        for (int k=j+1; k<len; k++) {
            if(x[k]<min){
                min=x[k];ind=k;
            }
        }
        if(ind!=j)
            swap(x,ind,j);
    }
}


int main(int argc, const char * argv[]) {
//initialise all the arrays
    int array1[1000];int array2[2000];int array3[3000];int array4[4000];int array5[5000];int array6[6000];
    int size1=1000;int size2=2000;int size3=3000;int size4=4000;int size5=5000;int size6=6000;
    
    int i;
    int a=0;
    int b=100;
    for (i = 0; i < 1000; i++) {//fill arrays with random numbers from 0-100
        array1[i] = rand()%(b-a+1)+a;
    }
    for (i = 0; i < 1000; i++) {
        array2[i] = rand()%(b-a+1)+a;
    }
    for (i = 0; i < 1000; i++) {
        array3[i] = rand()%(b-a+1)+a;
    }
    for (i = 0; i < 1000; i++) {
        array4[i] = rand()%(b-a+1)+a;
    }
    for (i = 0; i < 1000; i++) {
        array5[i] = rand()%(b-a+1)+a;
    }
    for (i = 0; i < 1000; i++) {
        array6[i] = rand()%(b-a+1)+a;
    }
    //make sure same data is used to test each sorting method
    int array1qs[1000];int array1shs[1000];int array1ses[1000];int array1bs[1000];
    int array2qs[2000];int array2shs[2000];int array2ses[2000];int array2bs[2000];
    int array3qs[3000];int array3shs[3000];int array3ses[3000];int array3bs[3000];
    int array4qs[4000];int array4shs[4000];int array4ses[4000];int array4bs[4000];
    int array5qs[5000];int array5shs[5000];int array5ses[5000];int array5bs[5000];
    int array6qs[6000];int array6shs[6000];int array6ses[6000];int array6bs[6000];
    
    for (i=0;i<1000;i++){
        array1qs[i]=array1[i];array1shs[i]=array1[i];array1ses[i]=array1[i];array1bs[i]=array1[i];
    }
    for (i=0;i<2000;i++){
        array2qs[i]=array2[i];array2shs[i]=array2[i];array2ses[i]=array2[i];array2bs[i]=array2[i];
    }
    for (i=0;i<3000;i++){
        array3qs[i]=array3[i];array3shs[i]=array3[i];array3ses[i]=array3[i];array3bs[i]=array3[i];
    }
    for (i=0;i<4000;i++){
        array4qs[i]=array4[i];array4shs[i]=array4[i];array4ses[i]=array4[i];array4bs[i]=array4[i];
    }
    for (i=0;i<5000;i++){
        array5qs[i]=array5[i];array5shs[i]=array5[i];array5ses[i]=array5[i];array5bs[i]=array5[i];
    }
    for (i=0;i<6000;i++){
        array6qs[i]=array6[i];array6shs[i]=array6[i];array6ses[i]=array6[i];array6bs[i]=array6[i];
    }
    //Quick-sort method
    double timeSpentqs1;
    clock_t beginqs1, endqs1;
    beginqs1 = clock();
    quicksort(array1qs,0,size1-1);
    endqs1 = clock();
    timeSpentqs1 = (double)(endqs1 - beginqs1) / CLOCKS_PER_SEC;
    double arrayqsTimes[6];
    arrayqsTimes[0]=timeSpentqs1;
    double timeSpentqs2;
    clock_t beginqs2, endqs2;
    beginqs2 = clock();
    quicksort(array2qs,0,size2-1);
    endqs2 = clock();
    timeSpentqs2 = (double)(endqs2 - beginqs2) / CLOCKS_PER_SEC;
    arrayqsTimes[1]=timeSpentqs2;
    double timeSpentqs3;
    clock_t beginqs3, endqs3;
    beginqs3 = clock();
    quicksort(array3qs,0,size3-1);
    endqs3 = clock();
    timeSpentqs3 = (double)(endqs3 - beginqs3) / CLOCKS_PER_SEC;
    arrayqsTimes[2]=timeSpentqs3;
    double timeSpentqs4;
    clock_t beginqs4, endqs4;
    beginqs4 = clock();
    quicksort(array4qs,0,size4-1);
    endqs4 = clock();
    timeSpentqs4 = (double)(endqs4 - beginqs4) / CLOCKS_PER_SEC;
    arrayqsTimes[3]=timeSpentqs4;
    double timeSpentqs5;
    clock_t beginqs5, endqs5;
    beginqs5 = clock();
    quicksort(array5qs,0,size5-1);
    endqs5 = clock();
    timeSpentqs5 = (double)(endqs5 - beginqs5) / CLOCKS_PER_SEC;
    arrayqsTimes[4]=timeSpentqs5;
    double timeSpentqs6;
    clock_t beginqs6, endqs6;
    beginqs6 = clock();
    quicksort(array6qs,0,size6-1);
    endqs6 = clock();
    timeSpentqs6 = (double)(endqs6 - beginqs6) / CLOCKS_PER_SEC;
    arrayqsTimes[5]=timeSpentqs6;
    
    //Shell sort method
    double timeSpentshs1;
    clock_t beginshs1, endshs1;
    beginshs1 = clock();
    shellSort(array1shs,size1);
//    for(i=0;i<1000;i++){
//        printf("%d\t",array1shs[i]);}
    endshs1 = clock();
    timeSpentshs1 = (double)(endshs1 - beginshs1) / CLOCKS_PER_SEC;
    double arrayshsTimes[6];
    arrayshsTimes[0]=timeSpentshs1;
    
    double timeSpentshs2;
    clock_t beginshs2, endshs2;
    beginshs2 = clock();
    shellSort(array2shs,size2);
    endshs2 = clock();
    timeSpentshs2 = (double)(endshs2 - beginshs2) / CLOCKS_PER_SEC;
    arrayshsTimes[1]=timeSpentshs2;

    double timeSpentshs3;
    clock_t beginshs3, endshs3;
    beginshs3 = clock();
    shellSort(array3shs,size3);
    endshs3 = clock();
    timeSpentshs3 = (double)(endshs3 - beginshs3) / CLOCKS_PER_SEC;
    arrayshsTimes[2]=timeSpentshs3;
    
    double timeSpentshs4;
    clock_t beginshs4, endshs4;
    beginshs4 = clock();
    shellSort(array4shs,size4);
    endshs4 = clock();
    timeSpentshs4 = (double)(endshs4 - beginshs4) / CLOCKS_PER_SEC;
    arrayshsTimes[3]=timeSpentshs4;
    
    double timeSpentshs5;
    clock_t beginshs5, endshs5;
    beginshs5 = clock();
    shellSort(array5shs,size5);
    endshs5 = clock();
    timeSpentshs5 = (double)(endshs5 - beginshs5) / CLOCKS_PER_SEC;
    arrayshsTimes[4]=timeSpentshs5;
    
    double timeSpentshs6;
    clock_t beginshs6, endshs6;
    beginshs6 = clock();
    shellSort(array6shs,size6);
    endshs6 = clock();
    timeSpentshs6 = (double)(endshs6 - beginshs6) / CLOCKS_PER_SEC;
    arrayshsTimes[5]=timeSpentshs6;
    
    //Bubble-Sort Method
    double timeSpentbs1;
    clock_t beginbs1, endbs1;
    beginbs1 = clock();
    bubbleSort(array1bs,size1);
    endbs1 = clock();
    timeSpentbs1 = (double)(endbs1 - beginbs1) / CLOCKS_PER_SEC;
    double arraybsTimes[6];
    arraybsTimes[0]=timeSpentbs1;

    double timeSpentbs2;
    clock_t beginbs2, endbs2;
    beginbs2 = clock();
    bubbleSort(array2bs,size2);
    endbs2 = clock();
    timeSpentbs2 = (double)(endbs2 - beginbs2) / CLOCKS_PER_SEC;
    arraybsTimes[1]=timeSpentbs2;
    
    double timeSpentbs3;
    clock_t beginbs3, endbs3;
    beginbs3 = clock();
    bubbleSort(array3bs,size3);
    endbs3 = clock();
    timeSpentbs3 = (double)(endbs3 - beginbs3) / CLOCKS_PER_SEC;
    arraybsTimes[2]=timeSpentbs3;
    
    double timeSpentbs4;
    clock_t beginbs4, endbs4;
    beginbs4 = clock();
    bubbleSort(array4bs,size4);
    endbs4 = clock();
    timeSpentbs4 = (double)(endbs4 - beginbs4) / CLOCKS_PER_SEC;
    arraybsTimes[3]=timeSpentbs4;
    
    double timeSpentbs5;
    clock_t beginbs5, endbs5;
    beginbs5 = clock();
    bubbleSort(array5bs,size5);
    endbs5 = clock();
    timeSpentbs5 = (double)(endbs5 - beginbs5) / CLOCKS_PER_SEC;
    arraybsTimes[4]=timeSpentbs5;
    
    double timeSpentbs6;
    clock_t beginbs6, endbs6;
    beginbs6 = clock();
    bubbleSort(array6bs,size6);
    endbs6 = clock();
    timeSpentbs6 = (double)(endbs6 - beginbs6) / CLOCKS_PER_SEC;
    arraybsTimes[5]=timeSpentbs6;
    
    //Selection-Sort method

//    selectionSort(array1ses, size1);
////    for(i=0;i<1000;i++){
////        printf("%d\t",array1ses[i]);}
    double timeSpentses1;
    clock_t beginses1, endses1;
    beginses1 = clock();
    selectionSort(array1ses,size1);
    endses1 = clock();
    timeSpentses1 = (double)(endses1 - beginses1) / CLOCKS_PER_SEC;
    double arraysesTimes[6];
    arraysesTimes[0]=timeSpentses1;
    
    double timeSpentses2;
    clock_t beginses2, endses2;
    beginses2 = clock();
    selectionSort(array2ses,size2);
    endses2 = clock();
    timeSpentses2 = (double)(endses2 - beginses2) / CLOCKS_PER_SEC;
    arraysesTimes[1]=timeSpentses2;

    double timeSpentses3;
    clock_t beginses3, endses3;
    beginses3 = clock();
    selectionSort(array3ses,size3);
    endses3 = clock();
    timeSpentses3 = (double)(endses3 - beginses3) / CLOCKS_PER_SEC;
    arraysesTimes[2]=timeSpentses3;
    
    double timeSpentses4;
    clock_t beginses4, endses4;
    beginses4 = clock();
    selectionSort(array4ses,size4);
    endses4 = clock();
    timeSpentses4 = (double)(endses4 - beginses4) / CLOCKS_PER_SEC;
    arraysesTimes[3]=timeSpentses4;
    
    double timeSpentses5;
    clock_t beginses5, endses5;
    beginses5 = clock();
    selectionSort(array5ses,size5);
    endses5 = clock();
    timeSpentses5 = (double)(endses5 - beginses5) / CLOCKS_PER_SEC;
    arraysesTimes[4]=timeSpentses5;
    
    double timeSpentses6;
    clock_t beginses6, endses6;
    beginses6 = clock();
    selectionSort(array6ses,size6);
    endses6 = clock();
    timeSpentses6 = (double)(endses6 - beginses6) / CLOCKS_PER_SEC;
    arraysesTimes[5]=timeSpentses6;
    
    printf("Table 9.5: Comparison of execution times (in seconds) of sorting routines.\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("\t\t\t\tNumber of elements in array\n");
    printf("\t\t\t\t----------------------------------------------------------------\n");
    printf("Algorithm \t      1000     \t 2000     \t 3000     \t 4000     \t 5000     \t 6000\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("Quick Sort     \t %f\t %f\t %f\t %f\t %f\t %f\t\n", arrayqsTimes[0],arrayqsTimes[1],arrayqsTimes[2],arrayqsTimes[3],arrayqsTimes[4],arrayqsTimes[5]);
    printf("Shell Sort     \t %f\t %f\t %f\t %f\t %f\t %f\t\n", arrayshsTimes[0],arrayshsTimes[1],arrayshsTimes[2],arrayshsTimes[3],arrayshsTimes[4],arrayshsTimes[5]);
    printf("Selection Sort \t %f\t %f\t %f\t %f\t %f\t %f\t\n", arraysesTimes[0],arraysesTimes[1],arraysesTimes[2],arraysesTimes[3],arraysesTimes[4],arraysesTimes[5]);
    printf("Bubble Sort \t %f\t %f\t %f\t %f\t %f\t %f\t\n", arraybsTimes[0],arraybsTimes[1],arraybsTimes[2],arraybsTimes[3],arraybsTimes[4],arraybsTimes[5]);
    printf("-------------------------------------------------------------------------------------\n");
    
    
    return 0;
    
}
