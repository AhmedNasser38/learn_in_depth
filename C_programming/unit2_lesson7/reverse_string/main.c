/*
 * main.c
 *
 *  Created on: Aug 23, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"

int main(){
	char str[50],rstr[50];
	int i=0,j=0;

	printf("Enter the sentence :");
	fflush(stdout);fflush(stdin);
	scanf("%s",str);

	char *ptr=(char*) &str;
	while(str[i]){
		ptr++;
		i++;
	}

	rstr[i]='\0';

	for(;i>0;i--){
		ptr--;
		rstr[j]=*ptr;
		j++;
	}
	printf("%s",rstr);

	return 0;
}

