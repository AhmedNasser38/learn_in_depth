/*
 * main.c
 *
 *  Created on: Aug 16, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"

#define pi 3.14
#define area(r) (pi*(r*r))
int main(){
	float r ;
	printf("Enter Radius : ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&r);

	printf("Area = %0.2f",area(r));
	return 0;
}
