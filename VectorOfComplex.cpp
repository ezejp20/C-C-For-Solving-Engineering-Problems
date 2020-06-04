#include "Complex.h"
#include <vector>

void multiplyVectors(vector<Complex> &x, const vector<Complex> &y){
    for (int i=0; i<x.size(); i++) {
        x[i].multiply(y[i]);
    }
}
void initRampVector(vector<Complex> &x){
    for (int i=0; i<x.size(); i++) {
        x[i].setReal(i);
        x[i].setImag(i);
    }
}
void printVector(vector<Complex> &x){
    for (int i=0; i<x.size(); i++) {
        x[i].print();
    }
}
int main() {
    const int len=5;
    vector <Complex> complexArray1(len);
    vector <Complex> complexArray2(len);
    initRampVector(complexArray1);
    printVector(complexArray1);
    multiplyVectors(complexArray1,complexArray2);
    puts("Vector after multiplication");
    printVector(complexArray1);
    return 0;
}
