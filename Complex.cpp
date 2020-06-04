#include <iostream>
#include "Complex.h"
using namespace std;

Complex::Complex(){
    setReal(0);setImag(0);
}
Complex::Complex(double r, double i){
    setReal(r);setImag(i);
}
double Complex::getReal(){return real;}
double Complex::getImag(){return imag;}
void Complex::setReal(double r){real=r;}
void Complex::setImag(double i){imag=i;}
void Complex::print(){
    cout<<getReal()<<"+j("<<getImag()<<")"<<endl;}
void Complex::add(Complex x){
    real+=x.getReal();imag+=x.getImag();}
void Complex::multiply(Complex x){
    real=(real*x.getReal()-imag*x.getImag());
    imag=(real*x.getImag()+imag*x.getReal());}