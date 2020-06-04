//
//  Simple demonstration for printf and scanf

#include <stdio.h>

int main(void) {
    char *str;
    int val_i1;
    float val_d1;
    
    printf("Type a double, an integer and a string please:");
    scanf("%f %d %s",&val_d1,&val_i1,str);
    printf("Your double:%5.3f,integer:%d and string:%s\n",val_d1,val_i1,str);
    return 0;
}
