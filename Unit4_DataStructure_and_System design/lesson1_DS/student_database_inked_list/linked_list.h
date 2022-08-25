/*
 * linked_list.h
 *
 *  Created on: Sep 25, 2021
 *      Author: Ahmed Nasser
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "platform.h"
#include"stdio.h"
#include"stdlib.h"
#include"conio.h"
#include"string.h"

#define print(...) {    fflush(stdout); \
						fflush(stdin); \
						printf(__VA_ARGS__); \
						fflush(stdout); \
						fflush(stdin);}

struct S_data{
	uint32 ID;
	int8 name[50];
	float32 height;
	uint8 grade;
};

struct S_student{
	struct S_data student;
	struct S_student* PNextStudent;
};

/*************** linked_list_baisc ***************/

void fill_record(struct S_student* next_student);

void add_student();

void delete_student();

void display_students();

void delete_all();

/*************** linked_list_advanced ***************/

void get_node_from_begin(uint32 node);

void get_node_from_end(uint32 node); // still

void mid();

void get_node(); // still

int length();

// stopped here

int detect_loop();

//

void reverse();

//

void sort_id();

void sort_grade();

void sort_name();

void sort();

void search();

#endif /* LINKED_LIST_H_ */

//void sort(struct S_student* PFirstStudent){
//
//	int temp , i , flag;
//
//	struct S_student* PCurrentStudent ;
//	struct S_student* PTemp = NULL;
//	do{
//		flag =0 ;
//		PCurrentStudent = PFirstStudent;
//		while(PCurrentStudent->PNextStudent != PTemp){
//			if((PCurrentStudent->student.ID) > (PCurrentStudent->PNextStudent->student.ID)){
//				// swap two values
//				temp = PCurrentStudent->student.ID;
//				PCurrentStudent->student.ID = PCurrentStudent->PNextStudent->student.ID;
//				PCurrentStudent->PNextStudent->student.ID = temp;
//
//				flag =1;
//			}
//			PCurrentStudent = PCurrentStudent->PNextStudent;
//		}
//		PTemp = PCurrentStudent;
//	}while(flag);
//}
