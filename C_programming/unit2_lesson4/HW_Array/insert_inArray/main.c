/*
 * main.c
 *
 *  Created on: Jul 24, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"

int main()
{

	int n, i, data, loc  ;

	printf("Enter number of elements: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&n);

	// definition matrixes
	/*>>>>>>>*/int a[n] , new_arr[n];

	//enter matrix
	printf("enter matrix from %d elements :	",n);
	fflush(stdout);fflush(stdin);

	// take the matrix element
	for(i=0 ; i<n ; i++ ){

		scanf("%d",&a[i]);
	}

	// take the inserted data
	printf("Enter the element to be inserted : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&data);

	// take it's location
	printf("Enter the location : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&loc);

	// insert data
	if(loc < (n+2)){
		for(i=0 ; i<=n ; i++ ){
			new_arr[i] = (loc>(i+1))?a[i]:(loc==(i+1))?data:a[i-1];
			// equivalent code using if
			/*		if(m>(i+1)){
			new_arr[i] = a[i];
		}else if (m == (i+1)){
			new_arr[i] = data;
		}else{
			new_arr[i] = a[i-1];
		}	*/
			printf("%d   ",new_arr[i]);
		}
	}else{
		printf("incorrect location , please enter location between 1 and %d",n+1);
	}
	return 0;
}
