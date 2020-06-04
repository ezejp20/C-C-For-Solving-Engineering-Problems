
#ifndef __Points__Point__
#define __Points__Point__

#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
class Point{
public:
    //constructor with default values
    Point(double=0,double=0);
    void setXY(double,double);
    void setPolar(double,double);

    double getX();
    double getY();
    double getR();
    double getTheta();
    
    string toString();
    void operator+=(Point& p){x+=p.getX();y+=p.getY();}
    
private:
    double x,y;
    double r,theta;
    //these methods need not be accessible by user
    void computePolar();
    void computeCartesian();
};

#endif /* defined(__Points__Point__) */
