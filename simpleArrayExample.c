//Simple array example: declaration, assignment, access
//Lec 3 example 
#include <stdio.h>
#define LEN 100
int main() {
    int x[LEN];
    //assigning values to an array
    for (int i=0; i<LEN; i++) {
        x[i]=i;
    }
    //accessing values of an array
    //computing average
    int sum=0;
    for (int i=0; i<LEN; i++) {
        sum+=x[i];
    }
    printf("Average: %f\n",((float)sum)/LEN);
    return 0;
}