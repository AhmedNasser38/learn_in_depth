/*
 * ex2.c
 *
 *  Created on: Jul 22, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"

int  main()
{
	char ch;

	printf("Enter an alphabet: ");
	fflush(stdout);	fflush(stdin);
	scanf("%c",&ch);

	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u' || ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
		printf("%c is a Vowel",ch);
	}else{
		printf("%c is a consonant",ch);
	}
}
