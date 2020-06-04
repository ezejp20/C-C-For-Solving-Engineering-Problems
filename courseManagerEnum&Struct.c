
#include <stdio.h>
#include <stdlib.h>
#define COURSE_CODE_LEN 7
enum courseType{MUST,FREE_ELECT,TECH_ELECT,UNDEFINED};
typedef struct{
	enum courseType type;
	int numCredits;
	char code[COURSE_CODE_LEN];
}Course;
void readLine(char *str,int strLength){
	int cnt=0;char ch;
	while((ch=getchar())!='\n' && cnt<strLength){
		str[cnt]=ch;cnt++;
	}
	str[cnt]='\0';
}
void readCourseContent(Course* coursesPt,int numCourses){
	int type;
	for(int i=0;i<numCourses;i++){
		printf("Course code:");fflush(stdout);
		scanf("%s",coursesPt[i].code);fflush(stdin);
		printf("Number of credits:");fflush(stdout);
		scanf("%d",&coursesPt[i].numCredits);fflush(stdin);
		printf("Type of course(Must:0,FreeElec:1,TechElec:2):");fflush(stdout);
		scanf("%d",&type);fflush(stdin);
		switch(type){
		case 0:coursesPt[i].type=MUST;break;
		case 1:coursesPt[i].type=FREE_ELECT;break;
		case 2:coursesPt[i].type=TECH_ELECT;break;
		default: coursesPt[i].type=UNDEFINED;break;
		}
		//alternatively: coursesPt[i].type=MUST+type;
	}
}
void printCourses(Course* coursesPt,int numCourses){
	printf("----Your courses:----\n");
	for(int i=0;i<numCourses;i++){
		printf("%s:#credits: %d, type: ",coursesPt[i].code,coursesPt[i].numCredits);
		switch(coursesPt[i].type){
		case MUST:printf("MUST\n");break;
		case FREE_ELECT:printf("FREE_ELECT\n");break;
		case TECH_ELECT:printf("TECH_ELECT\n");break;
		default: printf("UNDEFINED\n");break;
		}
	}
}
int main(void) {
	int numCourses=0;printf("Input number of courses:");
	scanf("%d",&numCourses);
	Course *coursesPt=(Course*)calloc(numCourses, sizeof(Course));
	if(coursesPt!=NULL){
		readCourseContent(coursesPt,numCourses);
		printCourses(coursesPt,numCourses);
		free(coursesPt);
	}
	return 0;
}
