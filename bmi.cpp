//Simple class definition example
//Lec10 example
//Resource: https://class.coursera.org/intropoocpp-001
//(slightly modified)

#include <iostream>
using namespace std;

//Your code starts here
class Patient{
public:
    void init(double w,double h,string n){
        weight=w;height=h;name=n;
    }
    void showInfo(){
        cout<<"Patient: "<<name<<", weight:"
        <<weight<<", height:"<<height<<endl;
    }
    double bmi(){
        if (height==0) {
            return 0;
        }
        return weight/(height*height);
    }
private:
    double height,weight;
    string name;
};
//Your code ends here

int main()
{
    Patient patient1;
    double weight, height;
    string name;
    do {
        cout << "Enter name of the patient: ";
        cin >> name;
        cout << "Enter weight (kg) and height(m) : ";
        cin >> weight >> height;
        patient1.init(weight, height,name);
        patient1.showInfo();
        cout << "BMI : " << patient1.bmi() << endl;
    } while (weight * height != 0.0);//stop condition: either weight or height is zero
    return 0;
}
