/*
 * ex7.c
 *
 *  Created on: Jul 19, 2021
 *      Author: Ahmed Nasser
 */

#include "stdio.h"

int main()
{

	float a , b;

	printf("enter value of a : ");
	fflush(stdout);	fflush(stdin);
	scanf("%f",&a);

	printf("enter value of b : ");
	fflush(stdout);	fflush(stdin);
	scanf("%f",&b);

	//we can replace * with + and / with -
	a = a*b; // new_a = old_a * old_b
	b = a/b; // b = old_a = new_a / old_b
	a = a/b;// a = old_b = new_a / old_a = new_a / new_b

	printf("After swapping value of a : %f \r\n" , a);
	printf("After swapping value of b : %f" , b);

	return 0;
}

