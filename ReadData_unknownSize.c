//Lec 5: Reading data using header info and dynamic memory allocation
#include <stdio.h>
#include <stdlib.h>
#define SIZE_INI 100
long numDataRead,sizeAllocated;

int *readDataToArray(char inFile[]){
    int *intPtr;
    FILE *fptr;
    fptr=fopen(inFile,"r");
    if(fptr!=NULL){//if file opened
        //dynamic memory allocation with initial size
        intPtr=(int*)malloc(sizeof(int)*SIZE_INI);
        if(intPtr!=NULL){//check if allocation was successfull
            sizeAllocated=SIZE_INI;
            long i=0;
            while (fscanf(fptr,"%d",intPtr+i)==1) {
                i++;
                //if array size will be exceeded in next round
                //reallocate memory to double array size
                if (i>=sizeAllocated) {
                    sizeAllocated*=2;
                    intPtr=realloc(intPtr, sizeof(int)*sizeAllocated);
                }
            }
            numDataRead=i;
        }
        fclose(fptr);
    }else{
        intPtr=NULL;
    }
    printf("Read %lu integers from file\n",numDataRead);
    return intPtr;
}


int main() {
    char inFile[]="/Users/barisbozkurt/Documents/DERSLER/C/data/monoSoundExample.txt";
    int *dataPtr;
    dataPtr=readDataToArray(inFile);
    printf("First data:%d\tLast Data:%d\n",dataPtr[0],dataPtr[numDataRead-1]);
    free(dataPtr);
    return 0;
}
