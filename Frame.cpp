#include "Frame.h"
//initialization of the static variable
int Frame::numFrames=0;
Frame::Frame(int len, int Fs):len(len),Fs(Fs){
    numFrames++;
    data=new double[len];//dynamic memory allocation
}
Frame::~Frame(){
    numFrames--;
    delete []data;//releasing memory allocated
}
void Frame::readFromFile(std::ifstream &inFile){
    double value;int counter=0;
    while (inFile>>value) {
        data[counter++]=value;if(counter==len){break;}
    }
    //if len number of data cannot be read, assign len to number of data read
    if(counter!=getLen()){
        len=counter;
    }
}
void Frame::writeToFile(std::ofstream &outFile){
    for (int i=0; i<len; i++) {
        outFile<<data[i]<<std::endl;
    }
}
