/*
 * ex1.c
 *
 *  Created on: Jul 22, 2021
 *      Author: Ahmed Nasser
 */

#include "stdio.h"

int  main()
{
	int x;

	printf("Enter an integer you want to check: ");
	fflush(stdout);	fflush(stdin);
	scanf("%d",&x);

	if(x % 2){
		printf("%d is odd",x);
	}else{
		printf("%d is even",x);
	}
}
