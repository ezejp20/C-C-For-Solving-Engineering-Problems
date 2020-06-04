#include "Array.h"
using namespace std;
int main() {
	int len;cout<<"Vector size:";cin>>len;
	Array vect1(len);textread("data1.txt",vect1);
	Array vect2(len);textread("data2.txt",vect2);
	Array vect3(len);textread("data3.txt",vect3);

	vect1+=vect2;
	if(vect2==vect3) cout<<"Vectors have the same content"<<endl;
	vect2*=vect3;

	textwrite("addOut.txt",vect1);
	textwrite("multOut.txt",vect2);

	return 0;
}
