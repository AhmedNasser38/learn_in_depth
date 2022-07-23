/*
 * main.c
 *
 *  Created on: Aug 16, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"

struct student{
	char name[20];
	unsigned int roll_number;
	float marks;
};
int main(){

	struct student student1;

	printf("Enter information of students : \n");
	printf("Enter Name : ");
	fflush(stdout);fflush(stdin);
	scanf("%s",&student1.name);
	printf("Enter Roll Number : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&student1.roll_number);
	printf("Enter Marks : ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&student1.marks);

	printf("Displaying Information :\n");
	printf("Name : %s \nRoll : %d \nMarks : %f ",
			student1.name,
			student1.roll_number,
			student1.marks  );
	return 0;
}
