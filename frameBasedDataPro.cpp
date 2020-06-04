#include "Frame.h"
#include "Comp230Filters.h"
#include "math.h"
using namespace std;

int main() {
    ifstream inputfile;inputfile.open("ecgSig2.txt");
    ofstream outfile;outfile.open("out.txt");
    int frameSize=1000;
    if(inputfile){
        while (!inputfile.eof()) {
            Frame newFrame(frameSize);
            newFrame.readFromFile(inputfile);
            Comp230Filters::removeOffset(newFrame);
            Comp230Filters::normalize(newFrame,1);
            //Uncomment the following lines to test your code
            //newFrame*=5;//multiplying the Frame object with a constant
            //newFrame+=20;//adding a constant to the Frame object
            //Comp230Filters::movingAveFilt(newFrame,5);//filtering the Frame object using moving average filter
            //Comp230Filters::medianFilter(newFrame,3);//filtering the Frame object using median filter with n=3
            newFrame.writeToFile(outfile);
        }
        inputfile.close();outfile.close();
    }else{
        cout<<"Unable to open file"<<endl;
    }
    return 0;
}
