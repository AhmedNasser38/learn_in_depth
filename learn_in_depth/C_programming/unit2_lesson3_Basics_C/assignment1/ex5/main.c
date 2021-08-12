/*
 * ex5.c
 *
 *  Created on: Jul 19, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"

int  main()
{

	char ch;

	printf("Enter a Character: ");
	fflush(stdout);	fflush(stdin);
	scanf("%c",&ch);

	printf("ASCII Code of %c  = %d ",ch,ch);

	return 0;
}
