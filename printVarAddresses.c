//Printing variable addresses
//Lec1 example
#include <stdio.h>
int main() {
    int xi=1, yi=10;
    char xc='x', yc=55;
    float xf=1.0,yf=-1.0;
    double xdb=1.0,ydb=-1.0;
    printf("1.st int:\t%p\n",&xi);
    printf("2.nd int:\t%p\n",&yi);
    printf("1.st char:\t%p\n",&xc);
    printf("2.nd char:\t%p\n",&yc);
    printf("1.st float:\t%p\n",&xf);
    printf("2.nd float:\t%p\n",&yf);
    printf("1.st double:\t%p\n",&xdb);
    printf("2.nd double:\t%p\n",&ydb);
    return 0;
}