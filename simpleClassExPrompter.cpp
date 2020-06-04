//Lec 9: simple class example
#include <iostream>
#include <string>
using namespace std;
class Prompter{
public:
	Prompter(string str){setMessage(str);}
	void setMessage(string str){
		message=str;
	}
	string getMessage(){ return message;}
	void displayMessage(){cout<<"Message: "<<message<<endl;}
private:
	string message;
};
int main() {
	Prompter p("Peace for all");
	p.displayMessage();
	return 0;
}
