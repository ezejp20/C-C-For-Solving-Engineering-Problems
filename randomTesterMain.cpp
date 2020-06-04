//
//  Tester program for random.h/.cpp
//

#include <iostream>
#include "random.h"
using namespace std;
int main() {
    //Picking 10 random real values in range 1.0 to 5.0
    cout<<"Testing randomReal()..."<<endl;
    for (int i=0; i<10; i++) {
        cout<<randomReal(1.0, 5.0)<<endl;
    }
    //Picking 10 random int values in range 10 to 15
    cout<<"Testing randomInteger()..."<<endl;
    for (int i=0; i<10; i++) {
        cout<<randomInteger(10, 15)<<endl;
    }
    cout << "End of tests\n";
    return 0;
}
