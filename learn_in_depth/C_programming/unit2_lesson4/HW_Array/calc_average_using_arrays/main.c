/*
 * main.c
 *
 *  Created on: Jul 24, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"

int main()
{
// take n
	int n;
	printf("Enter the numbers of data : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);

// definition of array after taking n number

	float data[n];
	float sum =0;
	for(int i=0; i<n ; i++){
		printf("%d. Enter Number : " ,i+1);
		fflush(stdout);fflush(stdin);
		scanf("%f",&data[i]);

		sum +=data[i];
	}

	printf("Average = %0.2f " ,(sum/n));

	return 0;
}
