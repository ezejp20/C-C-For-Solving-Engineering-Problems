
//Lec 5: Reading a file into an array of structs
#include <stdio.h>
#define MAXLEN 100

typedef struct {
    int index;
    char noteName[5];
    int frequency;
    int duration;
    int lns;
    char lyric[10];
} Symtr;

Symtr readNote(FILE *fptr){
    Symtr note;
    int numRead=fscanf(fptr, "%d",&note.index);
    if (numRead!=1) {
        note.index=-1;return note;
    }
    fscanf(fptr, "%s",&note.noteName[0]);
    fscanf(fptr, "%d",&note.frequency);
    fscanf(fptr, "%d",&note.duration);
    fscanf(fptr, "%d",&note.lns);
    fscanf(fptr, "%s",&note.lyric[0]);
    return note;
}
void printLyrics(Symtr notes[],int len){
    for (int i=0; i<len; i++) {
        printf("%s",notes[i].lyric);
    }
    printf("\n");
}
int main() {
    Symtr notes[MAXLEN];
    FILE *fptr;
    fptr=fopen("/Users/barisbozkurt/Documents/DERSLER/C/data/huseyni_turku_havada_bulut.txt","r");
    int ind=0;
    if(fptr!=NULL){
        while(1){
            Symtr currentNote=readNote(fptr);
            notes[ind]=currentNote;
            if(currentNote.index==-1){
                fclose(fptr);break;
            }
            ind++;
        }
        
    }
    printLyrics(notes,ind);
    return 0;
}
