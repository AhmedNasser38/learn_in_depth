/*
 * ex_plus.c
 *
 *  Created on: Jul 22, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"

int  main()
{
	int i , j;

	for( i=0;i <= 10;i++)
	{
		for( j=i;j<10;j++){
			printf("%d",j);
		}
		printf("\n");
	}
	return 0;
}
