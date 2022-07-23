/*
 * main.c
 *
 *  Created on: Aug 23, 2021
 *      Author: Ahmed Nasser
 */

#include "stdio.h"

int main(){
	char ch[26];
	char *ptr=(char*)&ch;

	for(int i=0;i<26;i++){
		*ptr='A'+i;
		ptr++;
	}
	ptr =ch;
	printf("Alphabets are : \n");

	for(int i=0;i<26;i++){
			printf("%c  ",*ptr);
			ptr++;
		}

	return 0;
}
