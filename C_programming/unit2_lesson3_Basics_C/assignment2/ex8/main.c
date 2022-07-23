/*
 * ex8.c
 *
 *  Created on: Jul 22, 2021
 *      Author: Ahmed Nasser
 */

#include "stdio.h"

int  main()
{
	char choice ;
	float x , y , sum;
	printf("Enter operator either + or - or * or / : ");
	fflush(stdout);fflush(stdin);
	scanf("%c",&choice);

	printf("Enter two operands : ");
	fflush(stdout);fflush(stdin);
	scanf("%f %f",&x,&y);

	switch(choice){
	case '+' :
		sum = x+y;
		break;

	case '-' :
			sum = x-y;
			break;

	case '*' :
			sum = x*y;
			break;

	case '/' :
			sum = x/y;
			break;

	default :
		printf("Error!! wrong operator");
			break;
	}

	printf("%f %c %f = %f",x,choice,y,sum);
}
