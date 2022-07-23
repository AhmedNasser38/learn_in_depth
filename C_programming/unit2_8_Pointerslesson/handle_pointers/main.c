/*
 * main.c
 *
 *  Created on: Aug 23, 2021
 *      Author: Ahmed Nasser
 */

#include "stdio.h"

int main(){
	int m ,*ab=NULL;

	m=29;
	printf("address of m : %p",&m);
	printf("\nvalue of m : %d",m);
	printf("\n\n");

	ab=&m;
	printf("Now ab is assigned with the address of m.");
	printf("\naddress of pointer ab : %p",ab);
	printf("\nvalue of pointer ab : %d ",*ab);
	printf("\n\n");

	m=34;
	printf("the value of m assigned to 34.");
	printf("\naddress of pointer ab : %p ",ab);
	printf("\nvalue of pointer ab : %d ",*ab);
	printf("\n\n");

	*ab=7;
	printf("the pointer variable ab is assigned with the value 7 now.");
	printf("\naddress of m : %p",&m);
	printf("\nvalue of m : %d",m);
	printf("\n\n");

	return 0;
}
