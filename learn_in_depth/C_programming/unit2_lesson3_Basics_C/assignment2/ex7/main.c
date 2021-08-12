/*
 * ex7.c
 *
 *  Created on: Jul 22, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"

int  main()
{
	int x ,sum=1 ;

	printf("Enter a positive integer : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&x);

	if(x >0 ){
		for(int i=1;i <= x;i++)   sum*=i;
		printf("Factorial = %d ",sum);
	}else if(x<0){
		printf("Error!!! negative number was entered instead of positive");
	}else{
		printf("Factorial = 1");
	}

	return 0;
}
