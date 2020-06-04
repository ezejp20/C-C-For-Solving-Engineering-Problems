//Arrays and pointers
//Lec 3 example
#include <stdio.h>
#define LEN 50
//Your code starts here
//Implement the methods createImpTrain() and createImpTrain_ptr()
void createImpTrain(int x[],int length,int T0){
    for (int i=0;i<length; i++) {
        if((i%T0)==0)
            x[i]=1;
        else
            x[i]=0;
    }
}
void createImpTrain_ptr(int *x,int length,int T0){
    for (int i=0;i<length; i++) {
        if((i%T0)==0)
            *(x+i)=1;//or x[i]=1;
        else
            *(x+i)=0;//or x[i]=0;
    }
}
//Your code ends here
int main()
{
    int T0=5;
    int x[LEN],y[LEN];
    createImpTrain(x,LEN,T0);
    createImpTrain_ptr(y,LEN,T0);
    
    //printing the result together with indexes
    printf("Ind\tX\tY\n");
    for (int i=0;i<LEN; i++) {
        printf("%d\t%d\t%d\n",i,x[i],y[i]);
    }

    
}

