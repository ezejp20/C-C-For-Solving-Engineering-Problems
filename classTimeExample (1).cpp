//Lec 9 example
#include <iostream>
#include "Time.h"
using namespace std;
int main() {
	Time noon(12,0,0);
	Time workOff;workOff.setTime(17,30,0);
	noon.printUniversal();
	workOff.printUniversal();
	try{
		Time afterMidnight(25,30,0);
	}catch(invalid_argument &exc){
		cout<<"Exception:"<<exc.what()<<endl;
	}
	return 0;
}
