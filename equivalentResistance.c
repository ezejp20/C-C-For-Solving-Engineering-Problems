/*
 * Equivalent resistance computation - Lec 1
 */

#include <stdio.h>

float series(float R1, float R2){
	return R1+R2;
}
float parallel(float R1, float R2){
	return R1*R2/(R1+R2);
}
float parallel_3(float R1, float R2, float R3){
	float R_temp=parallel(R1,R2);
	return R_temp*R3/(R_temp+R3);
}
int main() {
	float Rab_ex1=series(parallel_3(series(parallel_3(series(1,5), 4, 12),1),6,3),10);
	//float Rab_ex2=series(parallel_3(series(parallel(series(parallel(20,5),1),20),2),9,18),8);

	printf("The equivalent resistance for ex1 is: %3.5f\n",Rab_ex1);
	//printf("The equivalent resistance for ex2 is: %.3f\n",Rab_ex2);
	return 0;
}
