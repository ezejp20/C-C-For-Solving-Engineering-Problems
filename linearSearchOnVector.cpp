//Lec 9 example: linear search on vector elements
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
const int NUM_ELEMENTS=10;
//putting in vector random values in range 0-maxVal(exclusive)
void putRandValInVector(vector<int> &v,int maxVal){
	srand(int(time(NULL)));
	for(int i=0;i<v.size();i++) v[i]=rand()%maxVal;
}
//Your code starts here
vector<int> linearRangeSearch(vector<int> &v,int min,int max){
	vector<int> indexes;
	for(int i=0;i<v.size();i++){
		if(min<v[i] && v[i]<max){
			indexes.push_back(i);
		}
	}
	return indexes;
}
//Your code ends here
void printElementsAtIndex(vector<int> &v,vector<int> &ind){
	for(int i=0;i<ind.size();i++){
		cout<<ind[i]<<":"<<v[ind[i]]<<", ";
	}
}
void printVector(vector<int> &v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
int main() {
	vector<int> orgVect(NUM_ELEMENTS);
	putRandValInVector(orgVect,10);printVector(orgVect);
	cout<<"Searching values in range (2,6):"<<endl;
	vector<int> indexes=linearRangeSearch(orgVect,2,6);
	printElementsAtIndex(orgVect,indexes);
	return 0;
}
