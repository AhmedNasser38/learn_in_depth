/*
 * main.c
 *
 *  Created on: Aug 16, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"

struct distance{
	float inch;
	float feet;
};
int main(){

	struct distance d1,d2;
	float sum , rem_inch;
	printf("Enter information for 1st distance : \n");
	printf("Enter feet : ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&d1.feet);
	printf("Enter Inch : ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&d1.inch);

	printf("Enter information for 2nd distance : \n");
	printf("Enter feet : ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&d2.feet);
	printf("Enter Inch : ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&d2.inch);

	sum= (d1.feet+d2.feet)+(int)(d1.inch+d2.inch)/12 ;
	rem_inch = ((d1.inch+d2.inch))-((int)(d1.inch+d2.inch))+((int)(d1.inch+d2.inch)%12);
	printf("\n sum of distance = %0.2f\'-%0.2f\" ",sum,rem_inch);
	return 0;
}
