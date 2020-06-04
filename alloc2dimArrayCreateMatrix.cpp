#include <iostream>
using namespace std;
class Matrix{
public:
	Matrix(int w,int h):width(w),height(h){
		mat=new int*[h];
		for(int i=0;i<h;i++) mat[i]=new int[w];
	}
	~Matrix(){
		for(int i=0;i<height;i++) delete [] mat[i];
		delete [] mat;
	}
	void assignVals(){
		for(int i=0;i<height;i++)
			for(int j=0;j<width;j++)
				mat[i][j]=(i+1)*(j+1);
	}
	void printVals(){
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++)
				cout<<mat[i][j]<<"\t";
			cout<<endl;
		}
	}
	int** mat;//a multi-dim array is an array of array
	int width,height;
};
int main() {
	Matrix m(3,5);
	m.assignVals();
	m.printVals();
	return 0;
}
