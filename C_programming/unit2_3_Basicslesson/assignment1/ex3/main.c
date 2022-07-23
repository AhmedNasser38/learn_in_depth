/*
 * ex3.c
 *
 *  Created on: Jul 19, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"

int  main()
{
	int x ,y;
	printf("Enter two integers : ");
	fflush(stdout);fflush(stdin);
	scanf("%d  %d", &x , &y);

	printf("Sum : %d",x+y);
	return 0;
}

