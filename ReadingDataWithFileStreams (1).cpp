#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MAX_LEN=1000;
int main() {
    double data[MAX_LEN];string filename;
    ifstream infile;
    cout<<"Input File:"; cin>>filename;
    infile.open(filename.c_str());
    if (infile) {
        double value;long counter=0;
        while (infile>>value && counter<MAX_LEN) {
            data[counter++]=value;
        }
        infile.close();
        cout<<counter<<" data read"<<endl;
    }else{
        cout<<"Unable to open that file"<<endl;
    }
    return 0;
}