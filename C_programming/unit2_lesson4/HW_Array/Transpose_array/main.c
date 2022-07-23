/*
 * main.c
 *
 *  Created on: Jul 24, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"

int main()
{
	// take the size of matrix
	int r, c, i , j;
	printf("Enter rows and column of matrix: ");
	fflush(stdout);fflush(stdin);
	scanf("%d %d",&r,&c);

	// definition matrixes
	int a[r][c],t[c][r];
	// take the matrix element
	printf("Enter Elements of matrix: \n");
	fflush(stdout);fflush(stdin);

	for(i=0 ; i<r ; i++ ){
		for(j=0 ; j<c ; j++ ){
			printf("Enter element of a%d%d: ",i,j);
			fflush(stdout);fflush(stdin);
			scanf("%d",&a[i][j]);
		}
	}
	// print entered matrix
	printf("Entered matrix: \n");
	for(i=0 ; i<r ; i++ ){
		for(j=0 ; j<c ; j++ ){
			printf("%d \t",a[i][j]);
		}
		printf("\n");
	}
	//transpose the entered matrix
	for(i=0 ; i<c ; i++ ){
		for(j=0 ; j<r ; j++ ){
			t[i][j] = a[j][i];
		}
	}
	// print entered matrix [c][r]
	printf("Transpose of matrix: \n");
	for(i=0 ; i<c ; i++ ){
		for(j=0 ; j<r ; j++ ){
			printf("%d \t",t[i][j]);
		}
		printf("\n");
	}

	return 0;
}
