/*
 * ex6.c
 *
 *  Created on: Jul 22, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"

int  main()
{
	int x ,sum=0 ;

	printf("Enter an integer : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&x);

	for(int i=0;i <= x;i++)   sum+=i;

	printf("sum = %d ",sum);
	return 0;
}
