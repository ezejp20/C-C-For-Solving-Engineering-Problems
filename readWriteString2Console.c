//
//  Simple demonstration for puts and fgets


#include <stdio.h>
int main() {
    char str[50];puts("Provide an input:");
    fgets(str, sizeof(str), stdin);
    puts("Here is your input: ");puts(str);
    return 0;
}
