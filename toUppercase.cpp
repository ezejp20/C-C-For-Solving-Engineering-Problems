//Simple string processing example using <cctype> library
//Lec7 example

#include <iostream>
#include <cctype>
using namespace std;
//Your code starts here
string toUppercase(string str){
    for (int i=0; i<str.length(); i++) {
        str[i]=toupper(str[i]);
    }
    return str;
}
//Your code ends here
int main() {
    string inputText;
    cout<<"Input:";cin>>inputText;
    string outText=toUppercase(inputText);
    cout << outText<<endl;
    return 0;
}
