//Lec 13: simple convolution implementation
#include <iostream>
#include <vector>

using namespace std;
void convolve(vector<double>& x, vector<double>& h, vector<double>& y){
    for (long n=0; n<y.size(); n++) {
        y[n]=0;
        for (long k=0; k<x.size(); k++) {
            if((n-k)>=0 && (n-k)<=h.size()){
                y[n]=y[n]+x[k]*h[n-k];
            }
        }
    }
}
void readValues(vector<double>& x){
	for(int i=0;i<x.size();i++) cin>>x[i];
}
void printValues(vector<double>& x){
	for(int i=0;i<x.size();i++) cout<<x[i]<<" ";cout<<endl;
}
int main() {
	int xLen,hLen;
	cout<<"Length of input signal?";cin>>xLen;
	vector<double> x(xLen);readValues(x);
	cout<<"Length of system imp. response?";cin>>hLen;
	vector<double> h(hLen);readValues(h);
	vector<double> y(xLen+hLen-1);
	convolve(x,h,y);printValues(y);
	return 0;
}
