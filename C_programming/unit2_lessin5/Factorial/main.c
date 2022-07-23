/*
 * main.c
 *
 *  Created on: Jul 29, 2021
 *      Author: Ahmed Nasser
 */

#include "stdio.h"

int fact(int x);

int main(){
	int num;

	printf("Enter an positive integer:");
	fflush(stdout);fflush(stdin);
	scanf("%d",&num);

	printf("Factorial of %d = %d",num,fact(num));

	return 0;
}
int fact(int x){
	if(x>1)
		return fact(x-1) * x ;
}

