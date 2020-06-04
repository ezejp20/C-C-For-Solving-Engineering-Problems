//Lec11-polymorphism example
#include <iostream>
#include <vector>
using namespace std;
class Student{
public:
	//Your code starts here
	Student(int sn=0):studentNumber(sn){}
	virtual void display(){cout<<"Student-"<<studentNumber<<endl;}
	//Your code ends here
	virtual ~Student(){}
	int studentNumber;
};
class TransferStudent:public Student{
public:
	//Your code starts here
	TransferStudent(int sn=0,int sp=0):studentNumber(sn),prevStudentNumber(sp){}
	void display(){cout<<"TStudent-"<<studentNumber<<","<<prevStudentNumber<<endl;}
	//Your code ends here
	~TransferStudent(){}
	int studentNumber, prevStudentNumber;
};
int main() {
	//Your code starts here
	vector<Student*> students;
	for(int i=0;i<5;i++){
		Student* st=new Student(i);
		students.push_back(st);
	}
	for(int i=0;i<5;i++){
		TransferStudent* st=new TransferStudent(i,0);
		students.push_back(st);
	}
	for(int i=0;i<students.size();i++){
		students[i]->display();
		delete students[i];
	}
	//Your code ends here
	return 0;
}
