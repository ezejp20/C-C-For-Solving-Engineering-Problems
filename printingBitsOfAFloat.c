// Bitwise operations: printing bits of a float
// Lec 1 drill

#include <stdio.h>
void printBits(int* ptr_int){
    puts("!!! Printing bits in reverse order");
    int bit1=1,x=*ptr_int;
    for(int i=0;i<sizeof(int)*8;i++){//for each bit
        printf("%d ",x & bit1);
        x=x>>1;
        if((i+1)%8==0){//add end of line for each byte
            printf("\n");
        }
    }
    
}
int main() {
    float inFloat;
    float* ptr_float=&inFloat;
    puts("Specify a floating point number");
    scanf("%f",ptr_float);
    //simply assign the pointer of the float
    //to pointer of an int and print bits of that integer
    //as implemented in the lecture
    if (sizeof(int)==sizeof(float)) {
        int *ptr_int;
        ptr_int=(int*)ptr_float;
        printBits(ptr_int);
    }
    return 0;
}