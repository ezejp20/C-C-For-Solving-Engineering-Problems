//Lec 8 example on manipulators
//Resource: Programming abstractions in Cpp, E.S.Roberts
#include <iostream>
#include <iomanip>

using namespace std;
const double PI=3.14159265358979323846;
const double SPEED_OF_LIGHT=2.99792458E+8;
const double FINE_STRUCTURE=7.2573525E-3;
void printPrecisionTable();
int main() {
	cout<<"Default format:"<<endl<<endl;
	printPrecisionTable();
	cout<<"Fixed format:"<<fixed<<endl<<endl;
	printPrecisionTable();
	cout<<"Scientific format:"<<scientific<<endl<<endl;
	printPrecisionTable();
	return 0;
}
void printPrecisionTable(){
	cout<<" prec	|\tpi\t\t|\tspeed of light\t|\tfine-structure"<<endl;
	cout<<"------------------------------------------------------------------"<<endl;
	for(int prec=0;prec<=6;prec+=2){
		cout<<setw(4)<<prec<<"\t|";
		cout<<" "<<setw(15)<<setprecision(prec)<<PI<<"	|";
		cout<<" "<<setw(15)<<setprecision(prec)<<SPEED_OF_LIGHT<<"	|";
		cout<<" "<<setw(15)<<setprecision(prec)<<FINE_STRUCTURE<<"	|"<<endl;
	}
}
