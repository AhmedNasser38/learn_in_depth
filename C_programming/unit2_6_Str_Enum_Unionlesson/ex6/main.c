/*
 * main.c
 *
 *  Created on: Aug 16, 2021
 *      Author: Ahmed Nasser
 */

#include "stdio.h"

union Ujob{
	char name[32];
	float salary;
	int work_no;
}u;

struct Sjob{
	char name[32];
	float salary;
	int work_no;
}s;
int main(){

	printf("size of union = %d\n",sizeof(u));
	printf("size of structure = %d\n",sizeof(s));

	return 0;
}
