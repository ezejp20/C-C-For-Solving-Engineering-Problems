/*
 Simple example for function call by pointer
 Lec 3 example
 */

#include <stdio.h>
/* function declaration */
void swap(int *x, int *y);

int main ()
{
   int a = 100, b = 200;
   swap(&a, &b);
   printf("After swap, value of a : %d and b: %d\n",a,b);
   return 0;
}
/* function implementation */
void swap(int *x, int *y)
{
   int temp;
   temp = *x;    /* save the value at address x */
   *x = *y;      /* put y into x */
   *y = temp;    /* put temp into y */
   return;
}
