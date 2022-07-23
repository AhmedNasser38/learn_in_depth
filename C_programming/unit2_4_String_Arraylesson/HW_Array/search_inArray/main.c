/*
 * main.c
 *
 *  Created on: Jul 24, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"

int main()
{

	int n, data, i ,x=0 ;

	printf("Enter number of elements: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&n);

	// definition matrixes
	int a[n];

	// take the matrix element
	printf("enter matrix from %d elements :	",n);
	fflush(stdout);fflush(stdin);
	for(i=0 ; i<n ; i++ ){
		scanf("%d",&a[i]);
	}
	// take searched data
	printf("Enter element to be searched: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&data);

	for(i=0 ; i<n ; i++ )
		if(data == a[i]){
			x = i+1;
			if(x)
				printf("Number found at the location = %d\n",x);
			else
				printf("data entered isn't exist");
		}
	return 0;
}
