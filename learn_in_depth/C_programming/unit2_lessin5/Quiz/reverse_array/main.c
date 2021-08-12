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
void reverse_function(int arr[],int size);
int main(){
	int input_arr[MAX_SIZE];
	int size;

	printf("Enter the size of array :");
	fflush(stdout);fflush(stdin);
	scanf("%d",&size);

	printf("Input :");
	fflush(stdout);fflush(stdin);
	enter_array(input_arr,size);

	reverse_function(input_arr,size);

	printf("\nOutput :");
	print_array(input_arr,size);

	return 0;
}

void enter_array(int arr[],int size){
	for(int i=0;i<size;i++) scanf("%d",&arr[i]);
}
void print_array(int arr[],int size){
	for(int i=0;i<size;i++) printf("%d  ",arr[i]);
}
void reverse_function(int arr[],int size){
	//
	size=size-1;
	int temp;
	for(int i=0;i<size/2;i++){
		temp = arr[i];
		arr[i] = arr[size-i];
		arr[size-i] = temp;
	}
}
