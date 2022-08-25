/*
 * main.c
 *
 *  Created on: Sep 25, 2021
 *      Author: Ahmed Nasser
 */

#include"linked_list.h"


int main(){

	int8 temp[10]; // may be need to modified
	uint8 choice ;
	while(1){

		print("\n===============================================");
		print("\n\t Choose one of the following option");
		print("\n 1: Add Student  ");
		print("\n 2: Delete Student  ");
		print("\n 3: View Students  ");
		print("\n 4: Delete all Student  ");
		print("\n 5: Get Node  ");
		print("\n 6: Number of Students  ");
		print("\n 7: Sort  ");
		print("\n 8: Reverse database ");
		print("\n 9: check loop in database ");
		print("\n 0: EXIT");
		print("\n Enter option Number : ");
		gets(temp);
		choice = (uint8) atoi(temp);
		print("\n===============================================");

		switch(choice){
		case 1 :
			add_student();
			break;

		case 2 :
			delete_student();
			break;
		case 3 :
			display_students();
			break;
		case 4 :
			delete_all();
			break;
		case 5 :
			get_node();
			break;
		case 6 :
			print("\nThe number of students is %d" ,length());
			break;
		case 7 :
			sort();
			break;
		case 8 :
			reverse();
			break;
		case 9 :
			detect_loop();
			break;
		case 0 :
			return 0;

		default :
			print("\n Wrong Option");
			break;
		}
	}

	return 0;
}
