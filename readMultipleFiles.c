//Lec2 drill - see Lec2.pdf, pp.5 for description
#include <stdio.h>
#include <stdlib.h>
//Your code starts here
//Implement readF0file() method here
void readF0file(char *fileName){
	//for testing purposes we just print the filename
	//your program should perform reading of the file instead
	printf("%s\n",fileName);
}

//Your code ends here
int main() {
	char fileName[50];

	FILE *listFileID;
	listFileID=fopen("list.txt","r");
	if(listFileID==NULL){
		printf("Could not open file");
	}else{
		while(fscanf(listFileID,"%s",fileName)==1){
			readF0file(fileName);
		}
		fclose(listFileID);
	}
	return 0;
}
