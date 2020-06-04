
#include "Point.h"
#include "math.h"
using namespace std;

Point::Point(double x,double y):x(x),y(x){
    computePolar();
}
void Point::setXY(double xc,double yc){
    x=xc;y=yc;computePolar();
}

void Point::setPolar(double r, double theta){
    this->r=r;this->theta=theta;
    computeCartesian();
}
//for computing polar coordinates from cartesian
void Point::computePolar(){
    r=sqrt(x*x+y*y);theta=atan(y/x);
}
void Point::computeCartesian(){
    x=r*cos(theta);y=r*sin(theta);
}

double Point::getX(){return x;}
double Point::getY(){return y;}
double Point::getR(){return r;}
double Point::getTheta(){return theta;}

string Point::toString(){
    string str="("+to_string(x)+","+to_string(y)+")";
    return str;
}
