//Lec 8: example for using string and file streams
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
typedef struct{
	ostringstream noteNames;
	ostringstream durations;
	ostringstream lyrics;
}SymbTr;
void parseLine(const string line,SymbTr &song){
	istringstream lineStream(line);
	string dummy;string temp;
	lineStream>>dummy>>temp;song.noteNames<<(temp+"\t");
	lineStream>>dummy>>temp;song.durations<<(temp+"\t");
	lineStream>>dummy>>temp;song.lyrics<<(temp+"\t");
}
void printSong(SymbTr &song){
	cout<<song.noteNames.str()<<endl;
	cout<<song.durations.str()<<endl;
	cout<<song.lyrics.str()<<endl;
}
int main() {
	char filename[]="huseyni_turku_havada_bulut.txt";
	string line;SymbTr huseyniTurku;
	ifstream inFileStream;inFileStream.open(filename);
	if(inFileStream){//if file opened
		while(getline(inFileStream,line)){
			parseLine(line,huseyniTurku);
		}
		printSong(huseyniTurku);
		inFileStream.close();
	}else{
		cout<<"File could not be opened"<<endl;
	}

	return 0;
}
