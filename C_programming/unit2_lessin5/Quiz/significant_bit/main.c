/*
 * main.c
 *
 *  Created on: Aug 1, 2021
 *      Author: Ahmed Nasser
 */

#include "stdio.h"

void dec2bin(int n);
int sign_bit(int n);

int main(){
	int n;

	printf("enter  integer ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&n);

	printf("%d in binary is  ",n);
	dec2bin( n );

	printf("\nleast 4th bit is %d",sign_bit(n));


	return 0;
}

void dec2bin(int n)
{
	for(int i=31;i>=0;i--){

		if( (n>>i) & 1)
			printf("1");
		else
			printf("0");
	}

}
int sign_bit(int n){

			if( (n>>3) & 1)
				return 1;
			else
				return 0;
}
