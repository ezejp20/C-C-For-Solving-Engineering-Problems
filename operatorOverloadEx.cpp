//Lec 9: operator overloading example
#include <iostream>
using namespace std;
class Point{
public:
	Point(double r=0,double t=0):r(r),theta(t){}
	void print(){cout<<"r="<<r<<",theta="<<theta<<endl;}
	double r,theta;
};
ostream &operator<<(ostream &output,Point &p){
	output<<"r="<<p.r<<",theta="<<p.theta<<endl;
	return output;
}
istream &operator>>(istream &input,Point &p){
	input>>p.r;
	input.ignore();//skip ,
	input>>p.theta;
	return input;
}
int main() {
	Point p1;
	cout<<"Input a point with format: r,theta:";
	cin>>p1;
	cout<<"Your point: "<<p1;
	return 0;
}
