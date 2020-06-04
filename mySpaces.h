using namespace std;
namespace Polar{
	const double PI=3.14159;
	class Point{
	public:
		Point(double r,double t):r(r),theta(t){}
		void print(){cout<<"r="<<r<<",Q="<<theta<<endl;}
	private:
		double r,theta;
	};
}
namespace Cartesian{
	class Point{
	public:
		Point(double x,double y):x(x),y(y){}
		void print(){cout<<"("<<x<<","<<y<<")"<<endl;}
	private:
		double x,y;
	};
}
