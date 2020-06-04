//Lec 3 example
#include <stdio.h>
int main()
{
    int x_int[10];
    double x_dbl[10];
    char x_char[10];
    printf("Address int-1: %p\tint-2: %p\n",&x_int[0],&x_int[1]);
    printf("Address dbl-1: %p\tdbl-2: %p\n",&x_dbl[0],&x_dbl[1]);
    printf("Address char-1: %p\tchar-2: %p\n",&x_char[0],&x_char[1]);
    return 0;
}

