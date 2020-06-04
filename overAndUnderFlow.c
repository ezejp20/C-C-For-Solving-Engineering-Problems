//
//  Demonstrating overflow and underflow
//  
//  Lec1 example

#include <stdio.h>
#include <float.h>
int main() {
    //Demonstrating underflow
    float f1=1000*FLT_MIN,f2;
    for (int i=0; i<15; i++) {
        f1/=10;f2=f1/10;
        printf("%E\t%E\t%E\n",f1,f2,f1/f2);
    }
    printf("-------------------");
    //Demonstrating overflow
    f1=FLT_MAX/1000;
    for (int i=0; i<5; i++) {
        f1*=10;f2=f1*10;
        printf("%E\t%E\t%E\n",f1,f2,f1/f2);
    }
    return 0;
}
