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
	char ch;
	int i , counter=0;

	printf("Enter a string :");
	fflush(stdout);fflush(stdin);
	gets(str);

	printf("Enter a character to find frequency :");
	fflush(stdout);fflush(stdin);
	scanf("%c",&ch);

	for(i=0 ; str[i] != '\0'  ; i++){
		if(str[i] == ch) counter +=1 ;
	}

	printf("frequency of %c = %d",ch,counter);

	return 0;
}
