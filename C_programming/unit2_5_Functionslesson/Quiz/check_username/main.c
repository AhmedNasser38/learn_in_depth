/*
 * main.c
 *
 *  Created on: Jul 31, 2021
 *      Author: Ahmed Nasser
 */

#include "stdio.h"
#include "string.h"

int is_username(char str[],char username[]);
int main(){
	char str[100];
	char username[]="ahmed nasser";

	printf("Enter your user name :");
	fflush(stdout);fflush(stdin);
	gets(str);

	if(is_username(str,username)) printf("correct user name");
	else printf("wrong user name");

	return 0;
}
int is_username(char str[],char username[]){

	for(int i=0;i<strlen(username);i++){
		if(str[i]==username[i]) continue;
		else return 0;
	}
	return 1;

}
