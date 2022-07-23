/*
 * main.c
 *
 *  Created on: Aug 23, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"

#define MAX_SIZE 15
int main(){
	int arr[MAX_SIZE];
	int n;

	printf("Enter the number of elements to store in the array (max 15) : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&n);

	printf("Enter 5 number of elements in the array :\n");
	for(int i=0;i<n;i++){
		printf("element-%d : ",i+1);
		fflush(stdout);fflush(stdin);
		scanf("%d",&arr[i]);
	}

	printf("The elements of array in reverse order are :");
	for(int i=n-1;i>=0;i--){
			printf("\nelement-%d : %d",i+1,arr[i]);
		}
	return 0;
}


