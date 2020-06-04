//Lec 3
#include <stdio.h>
void printArray(int x[],int len){
    for (int k=0; k<len; k++) {
        printf("%d\t",x[k]);
    }
    printf("\n");
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
void bubbleSort_2(int x[],int len){
    int isSorted;
    for (int pass=0; pass<len-1; pass++) {
        isSorted=1;
        for (int k=0; k<(len-pass-1); k++) {
            if(x[k]>x[k+1]){
                swap(x,k,k+1);
                isSorted=0;
            }
        }
        if(isSorted)
            break;
    }
}

int main(int argc, const char * argv[]) {
    int arr1[]={9,5,3,4,7,8,5,4,1,2,7,4,5};
    int len=13;
    printf("Original array\n");
    printArray(arr1,len);
    bubbleSort(arr1,len);
    printf("Array sorted using Bubble sort\n");
    printArray(arr1,len);
    //re-setting to original values
    int arr2[]={9,5,3,4,7,8,5,4,1,2,7,4,5};
    bubbleSort_2(arr2,len);
    printf("Array sorted using Modified Bubble sort\n");
    printArray(arr2,len);

    return 0;
}
