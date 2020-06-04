#include <iostream>
#include <vector>
#include "Point.h"
#include "Point3D.h"
#define PI 3.1416
using namespace std;
vector <Point> putPointOnLine(double line_r,double line_theta,int numPoints){
    vector <Point> result(numPoints);
    for (int i=0; i<numPoints; i++) {
        double r=line_r*i/numPoints;
        result[i].setPolar(r,line_theta);
    }
    return result;
}
void printPoints(vector<Point> &pArray){
    for (int i=0; i<pArray.size(); i++) {
        cout<<pArray[i].toString()<<endl;
    }
}
int main() {
    double line_r,line_theta,line_thetaDegr;int numPoints;
    cout<<"Specify line r:";cin>>line_r;
    cout<<"\nSpecify line theta(in degrees):";cin>>line_thetaDegr;
    line_theta=line_thetaDegr*PI/180;
    cout<<"\nNumber of points:";cin>>numPoints;
    vector <Point> pArray=putPointOnLine(line_r,line_theta,numPoints);
    printPoints(pArray);

    //demonstrate use of sub-class Point3D which adds one more parameter:h
    //and also includes new toString() implementation
    Point3D p3D;//constructors are not inherited
    p3D.setXY(3,4);p3D.setH(2.5);
    cout<<"Using toString of Point3D"<<endl<<p3D.toString()<<endl;

    //casting and re-calling toString
    Point pX=p3D;
    //since pX is a Point, toString method of Point will be used
    cout<<"Using toString after casting"<<pX.toString()<<endl;

    return 0;
}
