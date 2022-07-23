/*
 * main.c
 *
 *  Created on: Jul 25, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"

int main()
{
	char str[100],temp;
	int i=0 , len,j;
	//enter the string
	printf("Enter the string : ");
	fflush(stdout);fflush(stdin);
	gets(str);

	//get the length of string
	for(len=0 ; str[len] != 0; len++);

	//reverse the string
	j = len-1;
	while(i<j){
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		i++;   j--;
	}
	//print reverse string
	printf("Reverse string is : %s ",str);

	return 0;
}
