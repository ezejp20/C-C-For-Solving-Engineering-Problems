//Lec 5: Union example
#include <stdio.h>
#include <stdlib.h>
typedef union{
    int numSingleUnits;
    int numPacks;
    float weight;
} Package;
typedef struct{
	int typeInd;
	Package pack;
} PackageU;
void setnumSingleUnits(PackageU *p,int numSingleUnits){
	p->pack.numSingleUnits=numSingleUnits;p->typeInd=0;
}
void setNumPacks(PackageU *p,int numPacks){
	p->pack.numPacks=numPacks;p->typeInd=1;
}
void setWeight(PackageU *p,float weight){
	p->pack.weight=weight;p->typeInd=2;
}
void printPack(PackageU *p){
	switch(p->typeInd){
	case 0: printf("%d single items in package\n",p->pack.numSingleUnits);break;
	case 1: printf("%d packages in package\n",p->pack.numPacks);break;
	case 2: printf("%2.2f kilograms in package\n",p->pack.weight);break;
	default: printf("Unexpected index, check your data");break;
	}
}

int main() {

    PackageU myPack;
    setnumSingleUnits(&myPack,5);
    printPack(&myPack);
    setNumPacks(&myPack,10);
    printPack(&myPack);
    setWeight(&myPack,2.3);
    printPack(&myPack);
    return 0;
}
