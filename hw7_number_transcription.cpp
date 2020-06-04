//
//  main.cpp
//  hw7EllenZehra
//
//  Created by Ellen Punter on 31/03/16.
//  Copyright © 2016 Ellen Punter. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
    //ask the user to input a number between 0 and 999999999
    cout<<"Specify a value in range 0-999,999,999: ";
    //assign this input to a string called "numberInput"
    string number;
    cin>>number;
    int i;
    if(number[i]=='0'){
        cout<<"BYE"<<endl;};

    
    
    
    //while the input is not 0:
    while(number.length()!=0 && number[0]!='0'){
                //if the number is in the millions:
        if(number.length()>6){
            //if the number is in the hundred millions:
            if(number.length()==9){
                //print the number of hundred millions:
                if(number[0]=='1'){
                    cout<<"one";}
                if(number[0]=='2'){
                    cout<<"two";}
                if(number[0]=='3'){
                    cout<<"three";}
                if(number[0]=='4'){
                    cout<<"four";}
                if(number[0]=='5'){
                    cout<<"five";}
                if(number[0]=='6'){
                    cout<<"six";}
                if(number[0]=='7'){
                    cout<<"seven";}
                if(number[0]=='8'){
                    cout<<"eight";}
                if(number[0]=='9'){
                    cout<<"nine";}
                cout<<" hundred and ";
                
                //print the number of 10-millions
                if(number[1]=='1'){
                    if(number[2]=='0'){
                        cout<<"ten ";}
                    if(number[2]=='1'){
                        cout<<"eleven ";}
                    if(number[2]=='2'){
                        cout<<"twelve ";}
                    if(number[2]=='3'){
                        cout<<"thirteen ";}
                    if(number[2]=='4'){
                        cout<<"fourteen ";}
                    if(number[2]=='5'){
                        cout<<"fifteen ";}
                    if(number[2]=='6'){
                        cout<<"sixteen ";}
                    if(number[2]=='7'){
                        cout<<"seventeen ";}
                    if(number[2]=='8'){
                        cout<<"eighteen ";}
                    if(number[2]=='9'){
                        cout<<"nineteen ";}
                    
                }else{
                    if(number[1]=='2'){
                        cout<<"twenty ";}
                    if(number[1]=='3'){
                        cout<<"thirty ";}
                    if(number[1]=='4'){
                        cout<<"forty ";}
                    if(number[1]=='5'){
                        cout<<"fifty ";}
                    if(number[1]=='6'){
                        cout<<"sixty ";}
                    if(number[1]=='7'){
                        cout<<"seventy ";}
                    if(number[1]=='8'){
                        cout<<"eighty ";}
                    if(number[1]=='9'){
                        cout<<"ninety ";}
                    //print the number of unit millions
                    if(number[2]=='1'){
                        cout<<"one ";}
                    if(number[2]=='2'){
                        cout<<"two ";}
                    if(number[2]=='3'){
                        cout<<"three ";}
                    if(number[2]=='4'){
                        cout<<"four ";}
                    if(number[2]=='5'){
                        cout<<"five ";}
                    if(number[2]=='6'){
                        cout<<"six ";}
                    if(number[2]=='7'){
                        cout<<"seven ";}
                    if(number[2]=='8'){
                        cout<<"eight ";}
                    if(number[2]=='9'){
                        cout<<"nine ";};};
                cout<<"million, ";
                
                if(number[3]=='1'){
                    cout<<"one";}
                if(number[3]=='2'){
                    cout<<"two";}
                if(number[3]=='3'){
                    cout<<"three";}
                if(number[3]=='4'){
                    cout<<"four";}
                if(number[3]=='5'){
                    cout<<"five";}
                if(number[3]=='6'){
                    cout<<"six";}
                if(number[3]=='7'){
                    cout<<"seven";}
                if(number[3]=='8'){
                    cout<<"eight";}
                if(number[3]=='9'){
                    cout<<"nine";}
                if(number[3]!='0'){
                    cout<<" hundred and ";};
                //print the number of 10-thousands
                if(number[4]=='1'){
                    if(number[5]=='0'){
                        cout<<"ten ";}
                    if(number[5]=='1'){
                        cout<<"eleven ";}
                    if(number[5]=='2'){
                        cout<<"twelve ";}
                    if(number[5]=='3'){
                        cout<<"thirteen ";}
                    if(number[5]=='4'){
                        cout<<"fourteen ";}
                    if(number[5]=='5'){
                        cout<<"fifteen ";}
                    if(number[5]=='6'){
                        cout<<"sixteen ";}
                    if(number[5]=='7'){
                        cout<<"seventeen ";}
                    if(number[5]=='8'){
                        cout<<"eighteen ";}
                    if(number[5]=='9'){
                        cout<<"nineteen ";}
                    
                }else{
                    if(number[4]=='2'){
                        cout<<"twenty ";}
                    if(number[4]=='3'){
                        cout<<"thirty ";}
                    if(number[4]=='4'){
                        cout<<"forty ";}
                    if(number[4]=='5'){
                        cout<<"fifty ";}
                    if(number[4]=='6'){
                        cout<<"sixty ";}
                    if(number[4]=='7'){
                        cout<<"seventy ";}
                    if(number[4]=='8'){
                        cout<<"eighty ";}
                    if(number[4]=='9'){
                        cout<<"ninety ";}
                    //print the number of unit thousands
                    if(number[5]=='1'){
                        cout<<"one ";}
                    if(number[5]=='2'){
                        cout<<"two ";}
                    if(number[5]=='3'){
                        cout<<"three ";}
                    if(number[5]=='4'){
                        cout<<"four ";}
                    if(number[5]=='5'){
                        cout<<"five ";}
                    if(number[5]=='6'){
                        cout<<"six ";}
                    if(number[5]=='7'){
                        cout<<"seven ";}
                    if(number[5]=='8'){
                        cout<<"eight ";}
                    if(number[5]=='9'){
                        cout<<"nine ";};};
                cout<<"thousand, ";
                //print number of hundreds:
                if(number[6]=='1'){
                    cout<<"one";}
                if(number[6]=='2'){
                    cout<<"two";}
                if(number[6]=='3'){
                    cout<<"three";}
                if(number[6]=='4'){
                    cout<<"four";}
                if(number[6]=='5'){
                    cout<<"five";}
                if(number[6]=='6'){
                    cout<<"six";}
                if(number[6]=='7'){
                    cout<<"seven";}
                if(number[6]=='8'){
                    cout<<"eight";}
                if(number[6]=='9'){
                    cout<<"nine";}
                if(number[6]!='0'){
                    cout<<" hundred";};
                //print number of tens:
                if(number[7]=='1'){
                    if(number[8]=='0'){
                        cout<<" and ten ";}
                    if(number[8]=='1'){
                        cout<<" and eleven ";}
                    if(number[8]=='2'){
                        cout<<" and twelve ";}
                    if(number[8]=='3'){
                        cout<<" and thirteen ";}
                    if(number[8]=='4'){
                        cout<<" and fourteen ";}
                    if(number[8]=='5'){
                        cout<<" and fifteen ";}
                    if(number[8]=='6'){
                        cout<<" and sixteen ";}
                    if(number[8]=='7'){
                        cout<<" and seventeen ";}
                    if(number[8]=='8'){
                        cout<<" and eighteen ";}
                    if(number[8]=='9'){
                        cout<<" and nineteen ";}
                    
                }else{
                    if(number[7]=='2'){
                        cout<<" and twenty ";}
                    if(number[7]=='3'){
                        cout<<" and thirty ";}
                    if(number[7]=='4'){
                        cout<<" and forty ";}
                    if(number[7]=='5'){
                        cout<<" and fifty ";}
                    if(number[7]=='6'){
                        cout<<" and sixty ";}
                    if(number[7]=='7'){
                        cout<<" and seventy ";}
                    if(number[7]=='8'){
                        cout<<" and eighty ";}
                    if(number[7]=='9'){
                        cout<<" and ninety ";}
                    
                    
                    //print number of units
                    if(number[8]=='1'){
                        cout<<" one ";}
                    if(number[8]=='2'){
                        cout<<" two ";}
                    if(number[8]=='3'){
                        cout<<" three ";}
                    if(number[8]=='4'){
                        cout<<" four ";}
                    if(number[8]=='5'){
                        cout<<" five ";}
                    if(number[8]=='6'){
                        cout<<" six ";}
                    if(number[8]=='7'){
                        cout<<" seven ";}
                    if(number[8]=='8'){
                        cout<<" eight ";}
                    if(number[8]=='9'){
                        cout<<" nine ";}
                    cout<<endl;
                };
            };
            
            //if the number is in the ten-millions
            if(number.length()==8){
                //print the number of 10-millions
                if(number[0]=='1'){
                    if(number[1]=='0'){
                        cout<<"ten ";}
                    if(number[1]=='1'){
                        cout<<"eleven ";}
                    if(number[1]=='2'){
                        cout<<"twelve ";}
                    if(number[1]=='3'){
                        cout<<"thirteen ";}
                    if(number[1]=='4'){
                        cout<<"fourteen ";}
                    if(number[1]=='5'){
                        cout<<"fifteen ";}
                    if(number[1]=='6'){
                        cout<<"sixteen ";}
                    if(number[1]=='7'){
                        cout<<"seventeen ";}
                    if(number[1]=='8'){
                        cout<<"eighteen ";}
                    if(number[1]=='9'){
                        cout<<"nineteen ";}
                }else{
                    if(number[0]=='2'){
                        cout<<"twenty ";}
                    if(number[0]=='3'){
                        cout<<"thirty ";}
                    if(number[0]=='4'){
                        cout<<"forty ";}
                    if(number[0]=='5'){
                        cout<<"fifty ";}
                    if(number[0]=='6'){
                        cout<<"sixty ";}
                    if(number[0]=='7'){
                        cout<<"seventy ";}
                    if(number[0]=='8'){
                        cout<<"eighty ";}
                    if(number[0]=='9'){
                        cout<<"ninety ";}
                    //print the number of unit millions
                    if(number[2]=='1'){
                        cout<<"one ";}
                    if(number[2]=='2'){
                        cout<<"two ";}
                    if(number[2]=='3'){
                        cout<<"three ";}
                    if(number[2]=='4'){
                        cout<<"four ";}
                    if(number[2]=='5'){
                        cout<<"five ";}
                    if(number[2]=='6'){
                        cout<<"six ";}
                    if(number[2]=='7'){
                        cout<<"seven ";}
                    if(number[2]=='8'){
                        cout<<"eight ";}
                    if(number[2]=='9'){
                        cout<<"nine ";};};
                cout<<"million, ";
            };
            
            //if the number is in the unit millions:
            //print the number of unit millions
            
            if(number.length()==7){
                if(number[0]=='1'){
                    cout<<"one ";}
                if(number[0]=='2'){
                    cout<<"two ";}
                if(number[0]=='3'){
                    cout<<"three ";}
                if(number[0]=='4'){
                    cout<<"four ";}
                if(number[0]=='5'){
                    cout<<"five ";}
                if(number[0]=='6'){
                    cout<<"six ";}
                if(number[0]=='7'){
                    cout<<"seven ";}
                if(number[0]=='8'){
                    cout<<"eight ";}
                if(number[0]=='9'){
                    cout<<"nine ";};
            cout<<"million, ";
            if(number[1]=='1'){
                cout<<"one";}
            if(number[1]=='2'){
                cout<<"two";}
            if(number[1]=='3'){
                cout<<"three";}
            if(number[1]=='4'){
                cout<<"four";}
            if(number[1]=='5'){
                cout<<"five";}
            if(number[1]=='6'){
                cout<<"six";}
            if(number[1]=='7'){
                cout<<"seven";}
            if(number[1]=='8'){
                cout<<"eight";}
            if(number[1]=='9'){
                cout<<"nine";}
            if(number[1]!='0'){
                cout<<" hundred and ";};
            //print the number of 10-thousands
            if(number[2]=='1'){
                if(number[3]=='0'){
                    cout<<"ten ";}
                if(number[3]=='1'){
                    cout<<"eleven ";}
                if(number[3]=='2'){
                    cout<<"twelve ";}
                if(number[3]=='3'){
                    cout<<"thirteen ";}
                if(number[3]=='4'){
                    cout<<"fourteen ";}
                if(number[3]=='5'){
                    cout<<"fifteen ";}
                if(number[3]=='6'){
                    cout<<"sixteen ";}
                if(number[3]=='7'){
                    cout<<"seventeen ";}
                if(number[3]=='8'){
                    cout<<"eighteen ";}
                if(number[3]=='9'){
                    cout<<"nineteen ";}
                
            }else{
                if(number[2]=='2'){
                    cout<<"twenty ";}
                if(number[2]=='3'){
                    cout<<"thirty ";}
                if(number[2]=='4'){
                    cout<<"forty ";}
                if(number[2]=='5'){
                    cout<<"fifty ";}
                if(number[2]=='6'){
                    cout<<"sixty ";}
                if(number[2]=='7'){
                    cout<<"seventy ";}
                if(number[2]=='8'){
                    cout<<"eighty ";}
                if(number[2]=='9'){
                    cout<<"ninety ";}
                //print the number of unit thousands
                if(number[3]=='1'){
                    cout<<"one ";}
                if(number[3]=='2'){
                    cout<<"two ";}
                if(number[3]=='3'){
                    cout<<"three ";}
                if(number[3]=='4'){
                    cout<<"four ";}
                if(number[3]=='5'){
                    cout<<"five ";}
                if(number[3]=='6'){
                    cout<<"six ";}
                if(number[3]=='7'){
                    cout<<"seven ";}
                if(number[3]=='8'){
                    cout<<"eight ";}
                if(number[3]=='9'){
                    cout<<"nine ";};};
            if(number[1]!='0'){
                cout<<"thousand, ";};
            //print number of hundreds:
            if(number[4]=='1'){
                cout<<"one";}
            if(number[4]=='2'){
                cout<<"two";}
            if(number[4]=='3'){
                cout<<"three";}
            if(number[4]=='4'){
                cout<<"four";}
            if(number[4]=='5'){
                cout<<"five";}
            if(number[4]=='6'){
                cout<<"six";}
            if(number[4]=='7'){
                cout<<"seven";}
            if(number[4]=='8'){
                cout<<"eight";}
            if(number[4]=='9'){
                cout<<"nine";}
            if(number[4]!='0'){
                cout<<" hundred";};
            //print number of tens:
            if(number[5]=='1'){
                if(number[6]=='0'){
                    cout<<" and ten ";}
                if(number[6]=='1'){
                    cout<<" and eleven ";}
                if(number[6]=='2'){
                    cout<<" and twelve ";}
                if(number[6]=='3'){
                    cout<<" and thirteen ";}
                if(number[6]=='4'){
                    cout<<" and fourteen ";}
                if(number[6]=='5'){
                    cout<<" and fifteen ";}
                if(number[6]=='6'){
                    cout<<" and sixteen ";}
                if(number[6]=='7'){
                    cout<<" and seventeen ";}
                if(number[6]=='8'){
                    cout<<" and eighteen ";}
                if(number[6]=='9'){
                    cout<<" and nineteen ";}
                
            }else{
                if(number[5]=='2'){
                    cout<<" and twenty ";}
                if(number[5]=='3'){
                    cout<<" and thirty ";}
                if(number[5]=='4'){
                    cout<<" and forty ";}
                if(number[5]=='5'){
                    cout<<" and fifty ";}
                if(number[5]=='6'){
                    cout<<" and sixty ";}
                if(number[5]=='7'){
                    cout<<" and seventy ";}
                if(number[5]=='8'){
                    cout<<" and eighty ";}
                if(number[5]=='9'){
                    cout<<" and ninety ";}
                
                
                //print number of units
                if(number[5]=='0'){
                    cout<<" and ";};
                if(number[6]=='1'){
                    cout<<" one ";}
                if(number[6]=='2'){
                    cout<<" two ";}
                if(number[6]=='3'){
                    cout<<" three ";}
                if(number[6]=='4'){
                    cout<<" four ";}
                if(number[6]=='5'){
                    cout<<" five ";}
                if(number[6]=='6'){
                    cout<<" six ";}
                if(number[6]=='7'){
                    cout<<" seven ";}
                if(number[6]=='8'){
                    cout<<" eight ";}
                if(number[6]=='9'){
                    cout<<" nine ";}
                cout<<endl;

            };};};
        
    
    //if the number is in the thousands:
    if(number.length()>3){
        //if the number is in the hundred thousands:
        if(number.length()==6){
            if(number[0]=='1'){
                cout<<"one";}
            if(number[0]=='2'){
                cout<<"two";}
            if(number[0]=='3'){
                cout<<"three";}
            if(number[0]=='4'){
                cout<<"four";}
            if(number[0]=='5'){
                cout<<"five";}
            if(number[0]=='6'){
                cout<<"six";}
            if(number[0]=='7'){
                cout<<"seven";}
            if(number[0]=='8'){
                cout<<"eight";}
            if(number[0]=='9'){
                cout<<"nine";}
            cout<<" hundred and ";
            //print the number of 10-thousands
            if(number[1]=='1'){
                if(number[2]=='0'){
                    cout<<"ten ";}
                if(number[2]=='1'){
                    cout<<"eleven ";}
                if(number[2]=='2'){
                    cout<<"twelve ";}
                if(number[2]=='3'){
                    cout<<"thirteen ";}
                if(number[2]=='4'){
                    cout<<"fourteen ";}
                if(number[2]=='5'){
                    cout<<"fifteen ";}
                if(number[2]=='6'){
                    cout<<"sixteen ";}
                if(number[2]=='7'){
                    cout<<"seventeen ";}
                if(number[2]=='8'){
                    cout<<"eighteen ";}
                if(number[2]=='9'){
                    cout<<"nineteen ";}
                
            }else{
                if(number[1]=='2'){
                    cout<<"twenty ";}
                if(number[1]=='3'){
                    cout<<"thirty ";}
                if(number[1]=='4'){
                    cout<<"forty ";}
                if(number[1]=='5'){
                    cout<<"fifty ";}
                if(number[1]=='6'){
                    cout<<"sixty ";}
                if(number[1]=='7'){
                    cout<<"seventy ";}
                if(number[1]=='8'){
                    cout<<"eighty ";}
                if(number[1]=='9'){
                    cout<<"ninety ";}
                //print the number of unit thousands
                if(number[2]=='1'){
                    cout<<"one ";}
                if(number[2]=='2'){
                    cout<<"two ";}
                if(number[2]=='3'){
                    cout<<"three ";}
                if(number[2]=='4'){
                    cout<<"four ";}
                if(number[2]=='5'){
                    cout<<"five ";}
                if(number[2]=='6'){
                    cout<<"six ";}
                if(number[2]=='7'){
                    cout<<"seven ";}
                if(number[2]=='8'){
                    cout<<"eight ";}
                if(number[2]=='9'){
                    cout<<"nine ";};};
            cout<<"thousand, ";
            //print number of hundreds:
            if(number[3]=='1'){
                cout<<"one";}
            if(number[3]=='2'){
                cout<<"two";}
            if(number[3]=='3'){
                cout<<"three";}
            if(number[3]=='4'){
                cout<<"four";}
            if(number[3]=='5'){
                cout<<"five";}
            if(number[3]=='6'){
                cout<<"six";}
            if(number[3]=='7'){
                cout<<"seven";}
            if(number[3]=='8'){
                cout<<"eight";}
            if(number[3]=='9'){
                cout<<"nine";}
            if(number[3]!='0'){
                cout<<" hundred";};
            //print number of tens:
            if(number[4]=='1'){
                if(number[5]=='0'){
                    cout<<" and ten ";}
                if(number[5]=='1'){
                    cout<<" and eleven ";}
                if(number[5]=='2'){
                    cout<<" and twelve ";}
                if(number[5]=='3'){
                    cout<<" and thirteen ";}
                if(number[5]=='4'){
                    cout<<" and fourteen ";}
                if(number[5]=='5'){
                    cout<<" and fifteen ";}
                if(number[5]=='6'){
                    cout<<" and sixteen ";}
                if(number[5]=='7'){
                    cout<<" and seventeen ";}
                if(number[5]=='8'){
                    cout<<" and eighteen ";}
                if(number[5]=='9'){
                    cout<<" and nineteen ";}
                
            }else{
                if(number[4]=='2'){
                    cout<<" and twenty ";}
                if(number[4]=='3'){
                    cout<<" and thirty ";}
                if(number[4]=='4'){
                    cout<<" and forty ";}
                if(number[4]=='5'){
                    cout<<" and fifty ";}
                if(number[4]=='6'){
                    cout<<" and sixty ";}
                if(number[4]=='7'){
                    cout<<" and seventy ";}
                if(number[4]=='8'){
                    cout<<" and eighty ";}
                if(number[4]=='9'){
                    cout<<" and ninety ";}
                
                
                //print number of units
                if(number[5]=='1'){
                    cout<<" one ";}
                if(number[5]=='2'){
                    cout<<" two ";}
                if(number[5]=='3'){
                    cout<<" three ";}
                if(number[5]=='4'){
                    cout<<" four ";}
                if(number[5]=='5'){
                    cout<<" five ";}
                if(number[5]=='6'){
                    cout<<" six ";}
                if(number[5]=='7'){
                    cout<<" seven ";}
                if(number[5]=='8'){
                    cout<<" eight ";}
                if(number[5]=='9'){
                    cout<<" nine ";}
                cout<<endl;
            };
        };
        //if the number is in the ten thousands:
        if(number.length()==5){
            //print the number of 10-thousands
            if(number[0]=='1'){
                if(number[1]=='0'){
                    cout<<"ten ";}
                if(number[1]=='1'){
                    cout<<"eleven ";}
                if(number[1]=='2'){
                    cout<<"twelve ";}
                if(number[1]=='3'){
                    cout<<"thirteen ";}
                if(number[1]=='4'){
                    cout<<"fourteen ";}
                if(number[1]=='5'){
                    cout<<"fifteen ";}
                if(number[1]=='6'){
                    cout<<"sixteen ";}
                if(number[1]=='7'){
                    cout<<"seventeen ";}
                if(number[1]=='8'){
                    cout<<"eighteen ";}
                if(number[1]=='9'){
                    cout<<"nineteen ";}
                
            }else{
                if(number[0]=='2'){
                    cout<<"twenty ";}
                if(number[0]=='3'){
                    cout<<"thirty ";}
                if(number[0]=='4'){
                    cout<<"forty ";}
                if(number[0]=='5'){
                    cout<<"fifty ";}
                if(number[0]=='6'){
                    cout<<"sixty ";}
                if(number[0]=='7'){
                    cout<<"seventy ";}
                if(number[0]=='8'){
                    cout<<"eighty ";}
                if(number[0]=='9'){
                    cout<<"ninety ";}
                //print the number of unit thousands
                if(number[1]=='1'){
                    cout<<"one ";}
                if(number[1]=='2'){
                    cout<<"two ";}
                if(number[1]=='3'){
                    cout<<"three ";}
                if(number[1]=='4'){
                    cout<<"four ";}
                if(number[1]=='5'){
                    cout<<"five ";}
                if(number[1]=='6'){
                    cout<<"six ";}
                if(number[1]=='7'){
                    cout<<"seven ";}
                if(number[1]=='8'){
                    cout<<"eight ";}
                if(number[1]=='9'){
                    cout<<"nine ";};};
            cout<<"thousand, ";
        };
        //if the number is in the unit thousands
        if(number.length()==4){
            if(number[0]=='1'){
                cout<<"one ";}
            if(number[0]=='2'){
                cout<<"two ";}
            if(number[0]=='3'){
                cout<<"three ";}
            if(number[0]=='4'){
                cout<<"four ";}
            if(number[0]=='5'){
                cout<<"five ";}
            if(number[0]=='6'){
                cout<<"six ";}
            if(number[0]=='7'){
                cout<<"seven ";}
            if(number[0]=='8'){
                cout<<"eight ";}
            if(number[0]=='9'){
                cout<<"nine ";}
            cout<<"thousand,";
            //print number of hundreds:
            if(number[1]=='1'){
                cout<<"one";}
            if(number[1]=='2'){
                cout<<"two";}
            if(number[1]=='3'){
                cout<<"three";}
            if(number[1]=='4'){
                cout<<"four";}
            if(number[1]=='5'){
                cout<<"five";}
            if(number[1]=='6'){
                cout<<"six";}
            if(number[1]=='7'){
                cout<<"seven";}
            if(number[1]=='8'){
                cout<<"eight";}
            if(number[1]=='9'){
                cout<<"nine";}
            if(number[1]!='0'){
                cout<<" hundred";};
            //print number of tens:
            if(number[2]=='1'){
                if(number[3]=='0'){
                    cout<<" and ten ";}
                if(number[3]=='1'){
                    cout<<" and eleven ";}
                if(number[3]=='2'){
                    cout<<" and twelve ";}
                if(number[3]=='3'){
                    cout<<" and thirteen ";}
                if(number[3]=='4'){
                    cout<<" and fourteen ";}
                if(number[3]=='5'){
                    cout<<" and fifteen ";}
                if(number[3]=='6'){
                    cout<<" and sixteen ";}
                if(number[3]=='7'){
                    cout<<" and seventeen ";}
                if(number[3]=='8'){
                    cout<<" and eighteen ";}
                if(number[3]=='9'){
                    cout<<" and nineteen ";}
                
            }else{
                if(number[2]=='2'){
                    cout<<" and twenty ";}
                if(number[2]=='3'){
                    cout<<" and thirty ";}
                if(number[2]=='4'){
                    cout<<" and forty ";}
                if(number[2]=='5'){
                    cout<<" and fifty ";}
                if(number[2]=='6'){
                    cout<<" and sixty ";}
                if(number[2]=='7'){
                    cout<<" and seventy ";}
                if(number[2]=='8'){
                    cout<<" and eighty ";}
                if(number[2]=='9'){
                    cout<<" and ninety ";}
                
                
                //print number of units
                if(number[3]=='1'){
                    cout<<" one ";}
                if(number[3]=='2'){
                    cout<<" two ";}
                if(number[3]=='3'){
                    cout<<" three ";}
                if(number[3]=='4'){
                    cout<<" four ";}
                if(number[3]=='5'){
                    cout<<" five ";}
                if(number[3]=='6'){
                    cout<<" six ";}
                if(number[3]=='7'){
                    cout<<" seven ";}
                if(number[3]=='8'){
                    cout<<" eight ";}
                if(number[3]=='9'){
                    cout<<" nine ";}
                cout<<endl;
            };

        };
    };
    
    //for hundreds and below:
    //if the number is in the hundreds:
    if(number.length()==3){
        //print number of hundreds:
        if(number[0]=='1'){
            cout<<"one";}
        if(number[0]=='2'){
            cout<<"two";}
        if(number[0]=='3'){
            cout<<"three";}
        if(number[0]=='4'){
            cout<<"four";}
        if(number[0]=='5'){
            cout<<"five";}
        if(number[0]=='6'){
            cout<<"six";}
        if(number[0]=='7'){
            cout<<"seven";}
        if(number[0]=='8'){
            cout<<"eight";}
        if(number[0]=='9'){
            cout<<"nine";}
        cout<<" hundred";
        //print number of tens:
        if(number[1]=='1'){
            if(number[2]=='0'){
                cout<<" and ten ";}
            if(number[2]=='1'){
                cout<<" and eleven ";}
            if(number[2]=='2'){
                cout<<" and twelve ";}
            if(number[2]=='3'){
                cout<<" and thirteen ";}
            if(number[2]=='4'){
                cout<<" and fourteen ";}
            if(number[2]=='5'){
                cout<<" and fifteen ";}
            if(number[2]=='6'){
                cout<<" and sixteen ";}
            if(number[2]=='7'){
                cout<<" and seventeen ";}
            if(number[2]=='8'){
                cout<<" and eighteen ";}
            if(number[2]=='9'){
                cout<<" and nineteen ";}
            
        }else{
            if(number[1]=='2'){
                cout<<" and twenty ";}
            if(number[1]=='3'){
                cout<<" and thirty ";}
            if(number[1]=='4'){
                cout<<" and forty ";}
            if(number[1]=='5'){
                cout<<" and fifty ";}
            if(number[1]=='6'){
                cout<<" and sixty ";}
            if(number[1]=='7'){
                cout<<" and seventy ";}
            if(number[1]=='8'){
                cout<<" and eighty ";}
            if(number[1]=='9'){
                cout<<" and ninety ";}
            
            
            //print number of units
            if(number[2]=='1'){
                cout<<" and one ";}
            if(number[2]=='2'){
                cout<<" and two ";}
            if(number[2]=='3'){
                cout<<" and three ";}
            if(number[2]=='4'){
                cout<<" and four ";}
            if(number[2]=='5'){
                cout<<" and five ";}
            if(number[2]=='6'){
                cout<<" and six ";}
            if(number[2]=='7'){
                cout<<" and seven ";}
            if(number[2]=='8'){
                cout<<" and eight ";}
            if(number[2]=='9'){
                cout<<" and nine ";}
            cout<<endl;
        };
    };
    //if number is in tens
    if(number.length()==2){
        if(number[0]=='1'){
            if(number[1]=='0'){
                cout<<"ten ";}
            if(number[1]=='1'){
                cout<<"eleven ";}
            if(number[1]=='2'){
                cout<<"twelve ";}
            if(number[1]=='3'){
                cout<<"thirteen ";}
            if(number[1]=='4'){
                cout<<"fourteen ";}
            if(number[1]=='5'){
                cout<<"fifteen ";}
            if(number[1]=='6'){
                cout<<"sixteen ";}
            if(number[1]=='7'){
                cout<<"seventeen ";}
            if(number[1]=='8'){
                cout<<"eighteen ";}
            if(number[1]=='9'){
                cout<<"nineteen ";}
            
        }else{
            if(number[0]=='2'){
                cout<<"twenty ";}
            if(number[0]=='3'){
                cout<<"thirty ";}
            if(number[0]=='4'){
                cout<<"forty ";}
            if(number[0]=='5'){
                cout<<"fifty ";}
            if(number[0]=='6'){
                cout<<"sixty ";}
            if(number[0]=='7'){
                cout<<"seventy ";}
            if(number[0]=='8'){
                cout<<"eighty ";}
            if(number[0]=='9'){
                cout<<"ninety ";}
            //print number of units
            if(number[1]=='1'){
                cout<<"one ";}
            if(number[1]=='2'){
                cout<<"two ";}
            if(number[1]=='3'){
                cout<<"three ";}
            if(number[1]=='4'){
                cout<<"four ";}
            if(number[1]=='5'){
                cout<<"five ";}
            if(number[1]=='6'){
                cout<<"six ";}
            if(number[1]=='7'){
                cout<<"seven ";}
            if(number[1]=='8'){
                cout<<"eight ";}
            if(number[1]=='9'){
                cout<<"nine ";}
            cout<<endl;
        };
        
    }
    //if number is in units
    if(number.length()==1){
        if(number=="1"){
            cout<<"one ";}
        if(number[0]=='2'){
            cout<<"two ";}
        if(number[0]=='3'){
            cout<<"three ";}
        if(number[0]=='4'){
            cout<<"four ";}
        if(number[0]=='5'){
            cout<<"five ";}
        if(number[0]=='6'){
            cout<<"six ";}
        if(number[0]=='7'){
            cout<<"seven ";}
        if(number[0]=='8'){
            cout<<"eight ";}
        if(number[0]=='9'){
            cout<<"nine ";}
        cout<<endl;
    };
    cout<<"Specify a value in range 0-999,999,999: ";
    cin>>number;
    if(number[i]=='0'){
        cout<<"BYE"<<endl;};
    
};};
