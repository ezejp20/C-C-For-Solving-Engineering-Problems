//Lec 9 example
#include <iostream>
#include "Time.h"
using namespace std;
int main() {
	Time midnight;//all default
	Time morning(8);//only hour specified
	Time workTime(9,30);//hour and minute specified
	Time noon(12,0,0);//all inputs specified
	midnight.printUniversal();morning.printUniversal();
	workTime.printUniversal();noon.printUniversal();
	try{
		Time afterMidnight(25,30,0);
	}catch(invalid_argument &exc){
		cout<<"Exception:"<<exc.what()<<endl;
	}
	return 0;
}
