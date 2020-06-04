//
//  Demonstrating use of enum
//
//  Lec1 example

#include <stdio.h>

enum SecurityLevel{
    risky,
    average,
    safe
};

int main() {
    enum SecurityLevel currentSecLevel=safe;
    
    switch (currentSecLevel) {
        case safe:
            printf("Safe, you can come out\n");
            break;
        case risky:
            printf("You'd better stay inside\n");
            break;
        default:
            break;
    }
    return 0;
}
