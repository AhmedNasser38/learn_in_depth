/*
 * main.c
 *
 *  Created on: Jul 29, 2021
 *      Author: Ahmed Nasser
 */

#include "stdio.h"

int prime_numbers(int x);

int main(){
	int arr[20];
	int low,high;

	printf("Enter Two numbers(intervals):");
	fflush(stdout);fflush(stdin);
	scanf("%d %d",&low,&high);

	int j=0;
	for (int i=low;i<=high;i++){
		if(prime_numbers(i)){
			arr[j] = i;
			j++;
		}
	}

	printf("Prime numbers between %d and %d are :",low,high);
	for (int i=0;i<j;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}

int prime_numbers(int x){
	int status=1;
	for(int i=2;i<x/2;i++)
			status =status && (x%i);

	return status;
}
