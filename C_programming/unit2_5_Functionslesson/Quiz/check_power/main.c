/*
 * main.c
 *
 *  Created on: Aug 7, 2021
 *      Author: Ahmed Nasser
 */

#include "stdio.h"

int is_power3(double);
int main(){
	double n;
	printf("Enter a number	");
	fflush(stdout);fflush(stdin);
	scanf("%lf",&n);

	printf("Output  >>>> %d",is_power3(n));

	return 0;
}

int is_power3(double n){
	n/=3.0;
	if(n == 1)
		return 1;
	else if (n == 0)
		return 0;
	else
		is_power3(n);

}
