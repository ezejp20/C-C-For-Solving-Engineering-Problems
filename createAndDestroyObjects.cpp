//Lec 9 example for constructor-destructor calls
#include <iostream>
using namespace std;
class CreateAndDestroy{
public:
	CreateAndDestroy(int x){
		ID=x;cout<<"Constructor call for "<<ID<<endl;
	}
	~CreateAndDestroy(){cout<<"Destructor call for "<<ID<<endl;}
private:
	int ID;
};
//global variable/object
CreateAndDestroy obj1(1);
void functionExample(){
	CreateAndDestroy obj2(2);
	static CreateAndDestroy obj3(3);
}
int main() {
	CreateAndDestroy obj4(4);
	static CreateAndDestroy obj5(5);
	functionExample();
	CreateAndDestroy obj6(6);
	return 0;
}
