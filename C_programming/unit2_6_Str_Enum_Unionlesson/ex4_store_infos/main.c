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

	struct student student[3];
	int size =sizeof(student)/sizeof(student[0]);

	printf("Enter information of students : \n");
	for(int i=0;i<size;i++){
		printf("For Roll Number  %d\n",i+1);
		printf("Enter Name : ");
		fflush(stdout);fflush(stdin);
		scanf("%s",&student[i].name);

		printf("Enter Marks : ");
		fflush(stdout);fflush(stdin);
		scanf("%f",&student[i].marks);
	}
	printf("\n\nDisplaying Information :\n");
	for(int i=0;i<size;i++){
	printf("\nInformation for Roll : %d \nName : %s \nMarks : %f ",
			i+1,
			student[i].name,
			student[i].marks  );
	printf("\n________________________________________\n");
	}
	return 0;
}
