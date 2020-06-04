//Lec 7 example on using default values for function arguments
//Resource: How to program, C++, Deitel, Prentice Hall
#include <iostream>
using namespace std;
int boxVolume(int length=1,int width=1,int height=1);

int main() {
	cout <<boxVolume() << endl;
	cout <<boxVolume(5) << endl;
	cout <<boxVolume(5,10) << endl;
	cout <<boxVolume(5,10,2) << endl;
	return 0;
}
int boxVolume(int length,int width,int height){
	return length*width*height;
}
