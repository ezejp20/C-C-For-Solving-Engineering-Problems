#include <stdio.h>
int sumOfDigits(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;n/=10;
    }
    return sum;
}
//Your code starts here
//implement a recursive version of the function above
int sumOfDigitsR(int n,int sum){
    sum+=n%10;
    if((n/10)>0){
        return sumOfDigitsR(n/10,sum);
    }else{
        return sum;
    }
}
//Your code ends here
int main(){
    int num;
    printf("Input an integer:");scanf("%d",&num);
    printf("Sum of digits:%d\n",sumOfDigits(num));
    printf("Sum of digits:%d\n",sumOfDigitsR(num,0));
    return 0;
}

