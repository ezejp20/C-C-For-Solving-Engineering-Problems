//Euclid's method for finding greatest common divisor
//Lec2 example

#include <stdio.h>

int EuclidGcd(int x, int y){
    //Your code starts here
    int small,large, remainder;
    if(x>y){
        large=x; small=y;
    }else{
        large=y; small=x;
    }
    while(small>0){
        remainder=large%small;
        printf("%d %% %d => %d\n",large,small,remainder);
        large=small;
        small=remainder;
    }
    return large;
    //Your code ends here
}
int main()
{
    int input1, input2;
    printf("Specify two integers to find their GCD:\n");
    scanf("%d %d",&input1,&input2);
    printf("GCD = %d\n",EuclidGcd(input1,input2));
}