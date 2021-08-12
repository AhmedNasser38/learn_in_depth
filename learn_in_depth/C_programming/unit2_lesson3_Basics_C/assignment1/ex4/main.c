/*
 * ex4.c
 *
 *  Created on: Jul 19, 2021
 *      Author: Ahmed Nasser
 */

#include "stdio.h"

int  main()
{
	float x ,y;

	printf("Enter two numbers : ");
	fflush(stdout);	fflush(stdin);
	scanf("%f  %f", &x , &y);

	printf("Product : %f",x*y);
	return 0;
}

