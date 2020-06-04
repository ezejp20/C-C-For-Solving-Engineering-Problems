//Lec10: very simple memory allocation example
#include <iostream>
using namespace std;
double *allocateArray(int size){
	return new double[size];
}
void readArray(double* array,int len){
	for(int i=0;i<len;i++){
		cout<<(i+1)<<":";cin>>array[i];
	}
}
void printArray(double* array,int len){
	cout<<"{";
	for(int i=0;i<len-1;i++){
		cout<<array[i]<<", ";
	}
	cout<<array[len-1]<<"}"<<endl;
}
int main() {
	int len;
	cout<<"Input size:";cin>>len;
	double *ptr=allocateArray(len);
	readArray(ptr,len);
	printArray(ptr,len);
	delete []ptr;
	return 0;
}
