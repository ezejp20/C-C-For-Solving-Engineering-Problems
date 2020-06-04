//Array processing example
//Lec 3 example
#include <stdio.h>
#define MAX_LEN 1000

int main()
{
    float currentVal,histArray[MAX_LEN];
    int cnt=0;
    while(scanf("%f",&currentVal)!=EOF){
        histArray[cnt]=currentVal;
        cnt++;
    }
    //Your code starts here
    for (int i=1; i<(cnt-1); i++) {
        if(histArray[i]>0.2){
            if(histArray[i]>histArray[i-1] && histArray[i]>histArray[i+1]){
                printf("Max val: %4.2f\t at index %d\n",histArray[i],i);
            }
        }
    }
    //Your code ends here
}