/*
 * ex6.c
 *
 *  Created on: Jul 19, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"

int main()
{

	float a , b , temp;

	printf("enter value of a : ");
	fflush(stdout);	fflush(stdin);
	scanf("%f",&a);

	printf("enter value of b : ");
	fflush(stdout);	fflush(stdin);
	scanf("%f",&b);

	temp = a;
	a = b;
	b = temp;

	printf("After swapping value of a : %f \r\n" , a);
	printf("After swapping value of b : %f" , b);

	return 0;
}
