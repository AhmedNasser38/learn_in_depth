/*
 * main.c
 *
 *  Created on: Aug 7, 2021
 *      Author: Ahmed Nasser
 */

#include "stdio.h"

int last_occur(int arr[],int size);

int main(){
	int arr[]={1,2,3,4,5,6,4};
	int size = sizeof(arr)/sizeof(arr[0]);

	for(int i=0;i<size;i++)
		printf("%d",arr[i]);

	printf("\nthe last occurrence is %d ",last_occur(arr,size));

	return 0;
}

int last_occur(int arr[],int size){
	int num;

	printf("\nEnter a number	");
	fflush(stdout);fflush(stdin);
	scanf("%d",&num);
	for(int i=size;i > 0;i--){
		if ( arr[i] == num)
			return i;
	}

	return -1;
}

