
#ifndef ARRAY_H_
#define ARRAY_H_
#include <iostream>
#include <fstream>

using namespace std;
class Array{
public:
	Array(int len=1,double iniVal=0){
		if(len>0){
			length=len;
			ptr=new double[length];
			for (int i=0;i<length;i++) ptr[i]=iniVal;
		}else{
			throw invalid_argument("Array size must be positive");
		}
	}
	~Array(){ if(length>0) delete [] ptr;cout<<"Memory released"<<endl;}
	//
	int getLength()const {return length;}
	void print() const{
		for(int i=0;i<length;i++) cout<<ptr[i]<<"\t";
		cout<<endl;
	}
	//[] with subscript checking
	double& operator[](int ind) const{
		if(ind<0 || ind>length)
			throw out_of_range("Index out of range");
		return ptr[ind];
	}
	//== which checks equality of contents
	bool operator==(Array &other)const{
		for(int i=0;i<length;i++){
			if(this->ptr[i]!=other[i]){
				return false;
			}
		}
		return true;
	}
private:
	double *ptr;
	int length;
};
//+ : multiplying the second signal with the first->result is the first
void operator*=(Array &r1,Array &r2){
	if(r1.getLength()==r2.getLength()){
		for(int i=0;i<r1.getLength();i++)
			r1[i]*=r2[i];
	}else{
		cout<<"Signals have different size, operation not performed";
	}
}
//+ : adding the second signal on the first
void operator+=(Array &r1,Array &r2){
	if(r1.getLength()==r2.getLength()){
		for(int i=0;i<r1.getLength();i++)
			r1[i]+=r2[i];
	}else{
		cout<<"Signals have different size, operation not performed";
	}
}
//writing array to output file
ofstream &operator<<(ofstream &outputFile,Array &r){
	for(int i=0;i<r.getLength();i++)
		outputFile<<r[i]<<endl;
	return outputFile;
}
//reading array from file until filling all its elements
ifstream &operator>>(ifstream &inputFile,Array &r){
	for(int i=0;i<r.getLength();i++)
		inputFile>>r[i];
	return inputFile;
}
//reading from a file
void textread(const string& filename,Array& r){
	ifstream inFile1;inFile1.open(filename.c_str());
	inFile1>>r;inFile1.close();
}
//writing to a file
void textwrite(const string& filename,Array& r){
	ofstream outFile;outFile.open(filename.c_str());
	outFile<<r;outFile.close();
}
#endif /* ARRAY_H_ */
