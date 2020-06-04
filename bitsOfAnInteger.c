//
//  Printing bits of an integer
//
//  Lec1 example

#include <stdio.h>

int main() {
    int i,x,bit1=1,numBits=sizeof(int)*8;
    
    while(1){
        printf("Your integer(0 for break): ");
        scanf("%d",&x);
        if (x==0) {
            break;
        }
        printf("Value in hex: %X\n",x);
        printf("Bits(in reverse order):\n");
        for(i=0;i<numBits;i++){
            printf("%d",x & bit1);
            x=x>>1;
        }
        printf("\n");
        printf("----------------------\n");
    }
    return 0;
}

