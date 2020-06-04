//Example: Lec 3 - Sorting algorithms - Selection sort
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
    int arr1[]={9,5,3,4,7,8,5,4,1,2,7,4,5};
    int len=13;
    printf("Array elements before sorting\n");
    printArray(arr1,len);
    selectionSort(arr1,len);
    printf("Array elements after sorting\n");
    printArray(arr1,len);
    return 0;
}
