/*
 * main.c
 *
 *  Created on: Aug 16, 2021
 *      Author: Ahmed Nasser
 */

#include "stdio.h"

struct complex{
	float real;
	float img;
};
int main(){

	struct complex n1,n2;

	printf("for 1st complex : \n");
	printf("Enter Real and imaginary respectively : ");
	fflush(stdout);fflush(stdin);
	scanf("%f %f",&n1.real,&n1.img);

	printf("for 2nd complex : \n");
	printf("Enter Real and imaginary respectively : ");
	fflush(stdout);fflush(stdin);
	scanf("%f %f",&n2.real,&n2.img);

	printf("sum = %0.2f + %0.2fi",(n1.real+n2.real),(n1.img+n2.img));
	return 0;
}
