/*
 * ex5.c
 *
 *  Created on: Jul 22, 2021
 *      Author: Ahmed Nasser
 */




#include "stdio.h"

int  main()
{
	char ch ;

	printf("Enter a character: ");
	fflush(stdout);	fflush(stdin);

	scanf("%c",&ch);

	if( (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') ){
		printf("%c is an alphabet",ch);
	}else{
		printf("%c is not an alphabet",ch);
	}

}
