/*
 * main.c
 *
 *  Created on: Jul 31, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"
void print_array(int arr[]);
void convert(int arr[]);
int main(){
	int ascii_arr[]={30,31,32,33,34,35,36,37,38,39};

	printf("ASCII Code :");
	print_array(ascii_arr);

	convert(ascii_arr);
	printf("\nDecimal numbers :");
	print_array(ascii_arr);

	return 0;
}


void print_array(int arr[]){
	int size = 10;
	for(int i=0;i<size;i++) printf("%d  ",arr[i]);
}
void convert(int arr[]){
	//
	int size=10;
	for(int i=0;i<size;i++)
		if(arr[i]>=30 && arr[i]<=39)
			arr[i]=arr[i] % 30;
}
