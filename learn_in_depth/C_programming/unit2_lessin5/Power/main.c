/*
 * main.c
 *
 *  Created on: Jul 30, 2021
 *      Author: Ahmed Nasser
 */

#include "stdio.h"

int power_func(int base , int power);

int main(){

	int base,power;

	printf("Enter base number:");
	fflush(stdout);fflush(stdin);
	scanf("%d",&base);

	printf("Enter power number(positive number): ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&power);
	printf("Enter power number(positive number): ");
	printf("%d^%d = %d",base,power,power_func(base,power));

	return 0;
}

int power_func(int base , int power){

	if(power != 0 )
		return base * power_func(base,power -1);
	else
		return 1;

}

