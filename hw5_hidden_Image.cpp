// main.cpp
//  hw5EllenZehra
//
//  Created by Ellen Punter on 24/03/16.
//  Copyright © 2016 Ellen Punter. All rights reserved.
//
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef int val;


int main(){
    //create a structure for RGB content of pixels
    struct Color{
        val red;
        val green;
        val blue;
        
        //for use when printing to output file: converting the integers to strings
        string str(){
            string ss;
            ss = to_string(red) + " " + to_string(green) + " " + to_string(blue) + " ";
            return ss;
        }
    };

    // initialise file names & file stream objects
    string inFileName = "/Users/jalepunter/Documents/workspace/imgFile.txt";
    string outFileName = "/Users/jalepunter/Documents/workspace/resultImgFile.txt";
    ifstream inFile;
    ofstream outFile;
    
    // open input file
    inFile.open(inFileName.c_str());
    if (!inFile.is_open()){
        cout << "Error opening input file." << endl;
        exit(EXIT_FAILURE);
    }
    // read header values
    string buffer;
    int Number_of_layers, Num_rows, Num_cols;
    inFile >> buffer >> Number_of_layers;
    inFile >> buffer >> Num_rows;
    inFile >> buffer >> Num_cols;
    
    // read the data into a matrix of colours
    Color Color_matrix[Num_rows][Num_cols];
    // i = row, j = column
    int i = 0;
    int j = 0;
    int tmp_r;
    int tmp_g=0;
    int tmp_b=0;
    int n=0;
    int m=0;
    
    Color tmp_gray;
    //Only read R lines
    for(m=0;m<Num_rows*3;m++){
        if(m%3==0){
    for(n=0;n<Num_cols;n++){
        Color tmp_c;
        //read 1 value at a time from the stream
        inFile >> tmp_r;
        //create a temporary red value
        tmp_c = {tmp_r,tmp_r,tmp_r};
        //put this into the color matrix
        Color_matrix[i][j]={tmp_r,tmp_g,tmp_b};
        j++;
        if (j>Num_cols){
            j = 0;
            i++;
        }
    }
    }
    //skip lines which are G or B
        else{
            for(n=0;n<Num_cols;n++){
                while(inFile >> tmp_r){
                }
            }
        }}
    //create a matrix for the resultant image
    Color Grey_matrix[Num_rows][Num_cols];
    
    for(int j = 0; j < Num_cols; j++){
        for(int i = 0; i < Num_rows; i++){
            //if the red content of the pixel is even, color is black
            if(Color_matrix[i][j].red % 2 == 0){
                tmp_gray = {64,64,64};
            }
            //if the red content of the pixel is odd, color is white
            else{
                tmp_gray = {0,0,0};
            }
            Grey_matrix[i][j] = tmp_gray;
        }
    }
    
    outFile.open(outFileName.c_str());
    if (!outFile.is_open()){
        cout << "Error opening output file." << endl;
        exit(EXIT_FAILURE);
    }
    
    for(int j = 0; j < Num_cols; j++){
        for(int i = 0; i < Num_rows; i++){
            outFile << Grey_matrix[i][j].str();
        }
    }
    inFile.close();
    outFile.close();
    
}

