#include <iostream>
#include "mySpaces.h"
int main() {
	Polar::Point p(1,2);p.print();
	Cartesian::Point p2(3,4);p2.print();
	using namespace Polar;
	cout<<PI<<endl;
	Point p3(3,5);p3.print();
	using namespace Cartesian;
	//Point p4(2,2);//there would be ambiguity for Point
	return 0;
}
