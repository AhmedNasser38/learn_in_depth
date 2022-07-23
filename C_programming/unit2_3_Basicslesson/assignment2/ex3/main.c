/*
 * ex3.c
 *
 *  Created on: Jul 22, 2021
 *      Author: Ahmed Nasser
 */

#include "stdio.h"

int  main()
{
	float x , y , z ;

	printf("Enter three numbers: ");
	fflush(stdout);fflush(stdin);
	scanf("%f %f %f",&x,&y,&z);

	if(x>y ){
		if(x>z ){
		printf("largest number = %f",x);
		}else{
			printf("largest number = %f",z);
		}
	}else{
		if(y>z){
			printf("largest number = %f",y);
		}else{
			printf("largest number = %f",z);
		}
	}
}
