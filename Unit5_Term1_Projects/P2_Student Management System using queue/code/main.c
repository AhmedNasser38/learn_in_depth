/*
 * main.c
 *
 *  Created on: Oct 10, 2021
 *      Author: Ahmed Nasser
 */

#include "Std_management.h"

int main(){
	int8 temp[10];
	uint32 choice;
	print("Welcome to School Management System\n");
	while(1)
	{
		print("\n--------------------------------------------\n");
		print("Choose The Task that you want to perform\n");
		print("1. Add a Student Manually\n");
		print("2. Add a Student From Text File\n");
		print("3. Find a Student by Roll Number\n");
		print("4. Find a Student by First Name\n");
		print("5. Find a Student by Course ID\n");
		print("6. Find a Total number of Students\n");
		print("7. Delete Student\n");
		print("8. Update Student \n");
		print("9. Extract  Students database to Text File\n");
		print("10. Show all information\n");
		print("11. Sort Students according to roll number\n");
	//	print("12. Total Students Saved\n");
		print("0. Exit\n");
		print(" Enter your choice to perform the task\n");

		gets(temp);
		choice = atoi(temp);
		switch(choice)
		{
		case 1 :
			add_manually();
			break;

		case 2 :
			add_file();
			break;

		case 3 :
			find_roll();
			break;

		case 4 :
			find_name();
			break;

		case 5 :
			find_courses();
			break;
		case 6 :
			total_students();
			break;

		case 7 :
			delete_student();
			break;

		case 8 :
			update_student();
			break;
		case 9 :
			extract_file();
			break;
		case 10 :
			display_all();
			break;
		case 11 :
			sort_id();
			break;
//		case 12 :
//			total_students();
//			break;
		case 0 :
			return 0;
			break;
		default :
			print("Wrong choice\n");
			break;
		}
	}

	return 0;
}
