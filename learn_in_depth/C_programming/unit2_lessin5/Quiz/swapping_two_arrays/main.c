/*
 * main.c
 *
 *  Created on: Jul 31, 2021
 *      Author: Ahmed Nasser
 */

#include "stdio.h"

#define MAX_SIZE 100

void enter_array(int arr[],int size);
void print_array(int arr[],int size);
void swap_function(int arr1[],int arr2[]);
int main(){
	int source_arr[MAX_SIZE];
	int dest_arr[MAX_SIZE];
	int source_size,dest_size;

	printf("Enter the size of source ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&source_size);

	printf("Enter the size of destination ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&dest_size);

	printf("Enter source array with size %d ",source_size);
	fflush(stdout);fflush(stdin);
	enter_array(source_arr,source_size);

	printf("Enter destination array with size %d ",dest_size);
	fflush(stdout);fflush(stdin);
	enter_array(dest_arr,dest_size);

	printf("The two arrays before swapping : \n");
	printf("\n\nSource array\n");
	print_array(source_arr,source_size);

	printf("\n\nDestination array\n");
	print_array(dest_arr,dest_size);

	swap_function(source_arr,dest_arr);

	printf("\n\nThe two arrays after swapping : \n");
	printf("\n\nSource array\n");
	print_array(source_arr,source_size);

	printf("\n\nDestination array\n");
	print_array(dest_arr,dest_size);


	return 0;
}

void enter_array(int arr[],int size){
	for(int i=0;i<size;i++) scanf("%d",&arr[i]);
}
void print_array(int arr[],int size){
	for(int i=0;i<size;i++) printf("%d  ",arr[i]);
}
void swap_function(int arr1[],int arr2[]){
	//
	for(int i=0;i<MAX_SIZE;i++){
		arr1[i] ^= arr2[i];
		arr2[i] ^= arr1[i];
		arr1[i] ^= arr2[i];
	}
}
