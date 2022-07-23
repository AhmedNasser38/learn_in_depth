/*
 * main.c
 *
 *  Created on: Jul 25, 2021
 *      Author: Ahmed Nasser
 */
#include "stdio.h"

int main()
{
	char str[100];
	int counter;

	printf("Enter a string : ");
	fflush(stdout);fflush(stdin);
	gets(str);

	for(counter=0 ; str[i] != 0 ; counter++);
	printf("Length of string : %d",counter);
	return 0;
}
