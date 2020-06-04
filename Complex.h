
#include <iostream>
using namespace std;
class Complex{
public:
    Complex();
    Complex(double r, double i);
    double getReal();
    double getImag();
    void setReal(double r);
    void setImag(double i);
    void print();
    void add(Complex x);
    void multiply(Complex x);
private:
    double real;
    double imag;
};

