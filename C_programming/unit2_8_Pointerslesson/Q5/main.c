/*
 * main.c
 *
 *  Created on: Aug 23, 2021
 *      Author: Ahmed Nasser
 */

#include "stdio.h"

struct SEmployee{
	char *Name;
	int ID;
};
int main(){
	static struct SEmployee emp1= {"Ahmed",1000},emp2= {"Ali",1001},emp3= {"Alex",1002},emp4= {"Kero",1003},emp5= {"mohamed",1004};

	struct SEmployee (*arr[]) ={&emp1,&emp2,&emp3,&emp4,&emp5};
	struct SEmployee (*(*ptr)[5]) = &arr;

	printf("Employees Data Base \n\n\n");
	for(int i=0;i<5;i++){
	printf("Employee Name : %s\n",(**(*ptr+i)).Name);
	printf("Employee ID : %d\n\n\n",(**(*ptr+i)).ID);
	}

	return 0;
}
