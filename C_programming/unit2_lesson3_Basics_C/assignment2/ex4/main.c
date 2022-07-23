/*
 * ex4.c
 *
 *  Created on: Jul 22, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"

int  main()
{
	float x  ;

	printf("Enter a number: ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&x);

	if(x>0){
		printf("%0.3f is Positive",x);
	}else if(x<0){
		printf("%0.3f is negative",x);
	}else{
		printf("You entered Zero");
	}
}
