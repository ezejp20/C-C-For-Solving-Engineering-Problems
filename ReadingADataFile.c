//
//  Example for file reading
//
//  Lec2 example
//

#include <stdio.h>

int main() {
    char fileName[]="/Users/barisbozkurt/Documents/MATLAB/data.txt";
    float xf;
    int cnt=0;
    
    FILE *fp1;
    fp1=fopen(fileName,"r");
    if(fp1!=NULL){
        while(fscanf(fp1, "%f",&xf)==1){
            cnt++;
            printf("%dth data=%3.5f\n",cnt,xf);
        }
        fclose(fp1);
    }else{
        printf("File %s could not be opened\n", fileName);
    }
    return 0;
}
