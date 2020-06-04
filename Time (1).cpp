#include <iostream>
#include <iomanip>
#include "Time.h"
#include <stdexcept>
using namespace std;
Time::Time(){setTime(0,0,0);}
Time::Time(int h,int m,int s){setTime(h,m,s);}
void Time::setTime(int h,int m,int s){
	if((h>=0 && h<=24) && (m>=0 && m<=60) && (s>=0 && s<=60)){
		hour=h;minute=m;second=s;
	}else{
		throw invalid_argument("Hour, minute or second out of range");
	}
}
void Time::printUniversal(){
	cout<<setfill('0')<<setw(2)<<hour<<":"
			<<setw(2)<<minute<<":"
			<<setw(2)<<second<<endl;
}
