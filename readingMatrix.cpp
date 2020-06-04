//Lec 8: example for using string and file streams
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	char filename[]="lena.txt";
	string line,temp;
	ifstream inFileStream;
	inFileStream.open(filename);
	if(inFileStream){//if file opened
		while(getline(inFileStream,line)){
			stringstream ss(line);
			while(getline(ss,temp,',')){//using delimiter ','
				int val=stoi(temp);//string to int conv.
				cout<<val<<"\t";
			}
			cout<<endl;
		}
		inFileStream.close();
	}else{
		cout<<"File could not be opened"<<endl;
	}
	return 0;
}
