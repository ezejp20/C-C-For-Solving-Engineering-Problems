// Example for function call by pointer
// Lec 3 example
#include <stdio.h>
void swap(char *x,char *y){
    char temp=*x;
    *x=*y;*y=temp;
}
int main() {
    char str[]="reverse me";
    int lenStr=sizeof(str)/sizeof(char)-1;
    //Your code starts here
    for (int i=0; i<lenStr/2; i++) {
        swap(&str[i],&str[lenStr-i-1]);
    }
    //Your code ends here
    printf("New string=%s\n",str);
    return 0;
}