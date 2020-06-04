//Lec 5: Dynamic memory allocation example
#include <stdio.h>
#include <stdlib.h>
#define M(I,J) (*(m+(I)*numCols+(J)))
typedef struct{
    int samplingFreq;
    int numOfChannels;
    int numDataInChannel;
    char dataType[10];
}WavHeader;

void printArray(int *x,int numData){
    for (int i=0; i<numData; i++) {
        printf("%d\t",*(x+i));
    }
    printf("\n");
}

WavHeader readHeader(FILE *fptr){
    WavHeader fileHeader;
    char tag[32],check;
    fscanf(fptr,"%s",&tag[0]);
    fscanf(fptr,"%d",&fileHeader.samplingFreq);
    fscanf(fptr,"%s",&tag[0]);
    fscanf(fptr,"%d",&fileHeader.numOfChannels);
    fscanf(fptr,"%s",&tag[0]);
    fscanf(fptr,"%s",&fileHeader.dataType[0]);//data type
    fscanf(fptr,"%s",&tag[0]);
    fscanf(fptr,"%d",&fileHeader.numDataInChannel);
    //reading text part inbetween two $ signs
    while((check=fgetc(fptr))!='$'){}
    while((check=fgetc(fptr))!='$'){}
    return fileHeader;
}
int *readDataToArray(char inFile[],WavHeader *fh){
    int *intPtr;long numData;
    FILE *fptr;
    fptr=fopen(inFile,"r");
    if(fptr!=NULL){
        *fh=readHeader(fptr);
        
        numData=(fh->numDataInChannel)*(fh->numOfChannels);
        intPtr=malloc(sizeof(int)*numData);
        if(intPtr!=NULL){//check allocation
            for (long i=0; i<numData; i++) {
                fscanf(fptr,"%d",intPtr+i);
            }
        }
        fclose(fptr);
    }else{
        intPtr=NULL;
    }
    printf("Read %lu integers from file\n",numData);
    return intPtr;
}
//converting data with multiple columns (in m) to
//data in a single column by adding data in all columns
int *multipleToMono(int *m,WavHeader *fh){
    int *monoPtr;
    int numCols=fh->numOfChannels;
    long numRows=fh->numDataInChannel;
    monoPtr=malloc(sizeof(int)*numRows);
    if(monoPtr!=NULL){//check allocation
        for (long i=0; i<numRows; i++) {
            *(monoPtr+i)=0;
            for (long j=0; j<numCols; j++) {
                *(monoPtr+i)+=M(i,j);
            }
        }
    }
    printf("Converted data from stereo to mono\n");
    return monoPtr;
}
void writeToFile(char filename[],int *x, WavHeader *fh){
    long len=fh->numDataInChannel;
    FILE *fptr=fopen(filename, "w");
    for(long i=0;i<len;i++){
        fprintf(fptr, "%d\n",*(x+i));
    }
    fclose(fptr);
    printf("Printed %lu integers to file\n",len);
}
int main() {
    char inFile[]="/Users/barisbozkurt/Documents/DERSLER/C/data/stereoSoundExample.txt";
    char outFile[]="/Users/barisbozkurt/Documents/DERSLER/C/data/monoSoundExample.txt";
    WavHeader file1header;
    
    //create array
    int *stereoDataPtr,*monoDataPtr;
    stereoDataPtr=readDataToArray(inFile,&file1header);
    
    monoDataPtr=multipleToMono(stereoDataPtr,&file1header);
    free(stereoDataPtr);
    
    //writing to new file
    writeToFile(outFile,monoDataPtr,&file1header);
    free(monoDataPtr);
    return 0;
}
