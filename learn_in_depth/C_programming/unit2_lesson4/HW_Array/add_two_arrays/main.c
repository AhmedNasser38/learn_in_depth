/*
 * main.c
 *
 *  Created on: Jul 24, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"

int main()
{
// variables
	float a[2][2] , b[2][2];
	int r , c ;
	float sum=0;
// enter 1st array
	printf("Enter the elements of 1st matrix : \n");
	fflush(stdin);fflush(stdout);
	for(r=0;r<2;r++){
		for(c=0;c<2;c++){
			printf("Enter a%d%d : ",r+1,c+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&a[r][c]);
		}
	}
// enter 2nd array
	printf("Enter the elements of 2nd matrix : \n");
	fflush(stdin);fflush(stdout);
		for(r=0;r<2;r++){
			for(c=0;c<2;c++){
				printf("Enter b%d%d : ",r+1,c+1);
				fflush(stdin);fflush(stdout);
				scanf("%f",&b[r][c]);
			}
		}
// add two arrays
		printf("Sum of matrix : \n");
		fflush(stdin);fflush(stdout);
				for(r=0;r<2;r++){
					for(c=0;c<2;c++){
						sum = a[r][c] + b[r][c];
						printf("%0.1f \t",sum);
					}
					printf("\n");
				}

	return 0;
}
