
#ifndef __FrameExample__Frame__
#define __FrameExample__Frame__
#include <iostream>
#include <fstream>
#include <stdio.h>

class Frame{
public:
    Frame(int len=100,int Fs=10000);//constructor
    ~Frame();//destructor
    double *data;//will be allocated and used for samples of data
    int getLen(){return len;}
    void setLen(int l){ len=l;}
    int getFs(){return Fs;}
    void readFromFile(std::ifstream &);
    void writeToFile(std::ofstream &);
    static int getNumFrames(){return numFrames;}//accessing static data, so this method also needs to be static
private:
    int len;
    int Fs;
    static int numFrames;//belongs to the class not to specific object, therefore static
};

#endif /* defined(__FrameExample__Frame__) */
