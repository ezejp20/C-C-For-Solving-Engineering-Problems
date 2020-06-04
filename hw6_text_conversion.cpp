// main.cpp
//  hw5EllenZehra
//
//  Created by Ellen Punter on 24/03/16.
//  Copyright © 2016 Ellen Punter. All rights reserved.
//
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <locale.h>

using namespace std;
int contains(char *ref,int len,char ch){
    int result=0;
    for(int i=0;i<len;i++){
        if(ch==ref[i]){
            return 1;
        }
    }
    return result;
}

int main(){
    
    
        // initialise file names & file stream objects
    string inFileName = "/Users/jalepunter/Documents/workspace/FightClub_TR.srt";
    string outFileName = "/Users/jalepunter/Documents/workspace/FightClub_edited.srt";
    ifstream inFile;
    ofstream outFile;
    
    // open input file
    inFile.open(inFileName.c_str());
    if (!inFile.is_open()){
        cout << "Error opening input file." << endl;
        exit(EXIT_FAILURE);
    }
    //open output file and print error to console if there is one
    outFile.open(outFileName.c_str());
    if (!outFile.is_open()){
        cout << "Error opening output file." << endl;
        exit(EXIT_FAILURE);
    }
    
    //stream strings from input file check each character, replace if necessary, write to output file
    string tempLine2S;
    string tempLineS;
//    char y[] = "ý";
//    char s[] = "þ";
//    char g[] = "ð";
//    char I[] = "Ý";
    char chars2exchRef[]="ýþðÝþ";
    

    int i;
    //while not at the end of the file
    while(!inFile.eof()){
        getline(inFile,tempLineS);
        tempLine2S=tempLineS;
        for(i=0;i<tempLineS.length();i++){
            char tempLine[tempLineS.length()];
            tempLine[i]=tempLineS[i];
            char tempLine2[tempLine2S.length()];
            tempLine2[i]=tempLine2S[i];
        }
        
        for(i=0;i<tempLineS.length();i++){
            if(tempLineS[i]==chars2exchRef[0]){
                tempLine2S[i]='i';
            }
            if(tempLineS[i]==chars2exchRef[1]){
                tempLine2S[i]='s';
            }
            if(tempLineS[i]==chars2exchRef[2]){
                tempLine2S[i]='g';
            }
            if(tempLineS[i]==chars2exchRef[3]){
                tempLine2S[i]='I';
            }
//            if((int)tempLine[i]==-10){
//            tempLine2[i]='o';
//            }
//            if((int)tempLine[i]==-42){
//                tempLine2[i]='O';
//            }
//            if((int)tempLine[i]==-4){
//                tempLine2[i]='u';
//            }
//            if((int)tempLine[i]==-36){
//                tempLine2[i]='U';
//            }
//            if((int)tempLine[i]==-25){
//                tempLine2[i]='c';
//            }
//            if((int)tempLine[i]==-57){
//                tempLine2[i]='C';
//            }
//            if((int)tempLine[i]==g[0]){
//                tempLine2[i]='g';
//            }
//            if((int)tempLine[i]==y[0]){
//                tempLine2[i]='i';
//            }
//            if((int)tempLine[i]==I[0]){
//                tempLine2[i]='I';
//            }
//            if((int)tempLine[i]==s[0]){
//                tempLine2[i]='s';
//            }
//            if((int)tempLine[i]==-34){
//                tempLine2[i]='S';
//            }

            else{
                tempLine2S[i]=tempLineS[i];
            }
            cout<<tempLine2S<<endl;
            
//            int code1=(int)y[0];
//            cout<<code1;
//            string h="ı";
//            cout<<(int)h[i];
            outFile.put(tempLine2);

            
            
        
    };
    };

    inFile.close();
    outFile.close();
    
    };
