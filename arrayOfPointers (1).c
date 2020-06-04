//Example from "An Introduction to the C Programming Language and Software Design, by Tim Bailey"
//Lec 3 example
#include <stdio.h>

int main(void){
    //an array of char pointers
    char *months[ ] = { "Illegal", "January", "February", "March",
        "April", "May", "June", "July", "August", "September",
        "October", "November", "December" };
    int i, j;
    
    printf("Input an integer between 1 and 12: ");
    scanf("%d", &i);
    if (i<1 || i>12) i=0;
    
    printf("Month number %d is %s.\n", i, months[i]); /* print string */
    
    printf("The letters of the month are: ");
    /* access elements using [ ][ ] */
    for (j = 0; months[i][j] != '\0'; ++j)
        printf("%c ", months[i][j]);
}

