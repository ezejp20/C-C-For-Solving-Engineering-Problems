//
//  PrintingATable
//
//  Lec1 example
//

#include <stdio.h>

int main() {
    int i,j;
    printf("\t|\t");
    for (j=1; j<4; j++) {
        printf("%d\t",j);
    }
    printf("\n-----------------\n");
    for (i=1; i<4; i++) {
        printf("%d\t|\t",i);
        for (j=1; j<4; j++) {
            printf("%d\t",i*j);
        }
        printf("\n");
    }
    return 0;
}

