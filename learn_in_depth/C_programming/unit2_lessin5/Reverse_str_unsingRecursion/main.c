/*
 * main.c
 *
 *  Created on: Jul 29, 2021
 *      Author: Ahmed Nasser
 */

#include "stdio.h"

void reverse_str();

int main(){

	printf("Enter a sentence:");
	fflush(stdout);fflush(stdin);

	reverse_str();
	return 0;
}

void reverse_str(){
	char c;
	scanf("%c",&c);
	if(c != '\n'){
		reverse_str();
		printf("%c",c);
	}

}
