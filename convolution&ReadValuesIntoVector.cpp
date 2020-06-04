//Lec 13: simple convolution implementation.
//	Warning: Time domain convolution is highly time-consuming,
//		you will need to wait for long to see the outputs
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
//convolution using vectors
void convolve(vector<double>& x, vector<double>& h, vector<double>& y){
	y.resize((x.size()+h.size()-1));
	for (long n=0; n<y.size(); n++) {
		y[n]=0;
		for (long k=0; k<x.size(); k++) {
			if((n-k)>=0 && (n-k)<=h.size()){
				y[n]=y[n]+x[k]*h[n-k];
			}
		}
	}
}
//convolution using arrays -> content of vectors copied to arrays
void convolve2(vector<double>& x, vector<double>& h, vector<double>& y){
	y.resize((x.size()+h.size()-1));
	//copying into arrays to speed up data access
	//memory allocation
	double* X=new double[x.size()];double* H=new double[h.size()];
	for(int i=0;i<x.size();i++) X[i]=x[i];
	for(int i=0;i<h.size();i++) H[i]=h[i];

	double* Y=new double[y.size()];
	cout<<"Convolution started....will take some time\n";
	for (long n=0; n<y.size(); n++) {
		Y[n]=0;
		for (long k=0; k<x.size(); k++) {
			if((n-k)>=0 && (n-k)<=h.size()){
				Y[n]=Y[n]+X[k]*H[n-k];
			}
		}
	}
	cout<<"Convolution finished\n";
	for(int i=0;i<y.size();i++) y[i]=Y[i];
	//memory de-allocation
	delete [] X;delete [] H;delete [] Y;
}
void readValuesFromFile(vector<double>& x,const char* filename){
	ifstream inFile;inFile.open(filename);double temp;
	while(inFile){
		inFile>>temp;x.push_back(temp);
	}
	inFile.close();
}
void print2File(vector<double>& x,const char* filename){
	ofstream outFile;outFile.open(filename);
	if(outFile){
		for(int i=0;i<x.size();i++) outFile<<x[i]<<"\n";
	}
	outFile.close();
}
int main() {
	vector<double> x;
	vector<double> h;
	vector<double> y;
	//Application 1: filtering
	//reading noisy signal and the filter coefficients
	//readValuesFromFile(x,"WaltzPlusSine.txt");
	//readValuesFromFile(h,"filterCoeff.txt");

	//Application 2: adding reverb to a sound signal
	//reading noisy signal and the filter coefficients
	readValuesFromFile(x,"guitarRecording_11025.txt");
	readValuesFromFile(h,"impulse_cathedral_11025.txt");

	//performing filtering via convolution
	convolve2(x,h,y);
	//writing output to file
	print2File(y,"out.txt");
	cout<<"Finished!";
	return 0;
}
