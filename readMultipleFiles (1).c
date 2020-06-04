//Lec2 drill - see Lec2.pdf, pp.5 for description
#include <stdio.h>
#include <stdlib.h>
//Your code starts here
//Implement readF0file() method here
void readF0file(char *fileName){
    float val1,val2;
    float maxVal2=0;
    int cnt=0;
    
    printf("%s\t",fileName);
    FILE *fileID;
    fileID=fopen(fileName,"r");
    
    while(fscanf(fileID,"%f %f",&val1,&val2)>0){
        cnt++;
        if(val2>maxVal2)
            maxVal2=val2;
    }
    printf("%d items\t with max: %5.2f\n",cnt,maxVal2);
    fclose(fileID);
}
//Your code ends here
int main() {
    char fileName[50];
    //next line should be modified if your OS is windows
    system("ls *.yin.txt > list.txt");
    
    FILE *listFileID;
    listFileID=fopen("list.txt","r");
    while(fscanf(listFileID,"%s",fileName)==1){
        readF0file(fileName);
    }
    fclose(listFileID);
    return 0;
}
