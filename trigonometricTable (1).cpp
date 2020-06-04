//Lec 8 example: trigonometric table
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	int n,prec;
	cout<<"Input number of segments for trigonometric table:";
	cin>>n;
	cout<<"Specify precision:";
	cin>>prec;
	cout<<"Theta\t|SIN\t|COS\t|TAN\t|"<<fixed<<endl;
	for(double theta=0;theta<=(2*M_PI);theta+=(2*M_PI)/n){
		cout<<" "<<setw(6)<<setprecision(prec)<<(theta/M_PI)*180<<"\t|";
		cout<<" "<<setw(6)<<setprecision(prec)<<sin(theta)<<"\t|";
		cout<<" "<<setw(6)<<setprecision(prec)<<cos(theta)<<"\t|";
		cout<<" "<<setw(6)<<setprecision(prec)<<tan(theta)<<"\t|"<<endl;
	}
	return 0;
}
