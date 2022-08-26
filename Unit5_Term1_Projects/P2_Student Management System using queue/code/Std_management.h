/*
 * Std_management.h
 *
 *  Created on: Oct 10, 2021
 *      Author: Ahmed Nasser
 */

#ifndef STD_MANAGEMENT_H_
#define STD_MANAGEMENT_H_

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


/************************* Start of configuration section ************************/
#define num_students 50
#define courses_num  10

	//Courses
#define Physics 		301
#define Maths3 			323
#define Maths4 			211
#define Programming 	441
#define Data_structre   141
#define Organization 	351
#define DSP 			322
#define Electronics 	333
#define Labs 			309
#define Circuits 		208

#define course1 	Physics
#define course2 	Maths3
#define course3		Maths4
#define course4 	Programming
#define course5 	Data_structre
#define course6 	Organization
#define course7 	DSP
#define course8 	Electronics
#define course9 	Labs
#define course10 	Circuits
// >>>>if you add more courses , you need also update total_courses array in Std_management.c file in initialization section (line:18)

/************************* ENF of configuration section ************************/

typedef struct {
 int8 first_name[25];
 int8 last_name[25];

 uint32 roll_num;
 float32 GPA;

 uint32 courses_id[10];


}S_Student;

typedef enum {

	LIST_no_error,
	LIST_full,
	LIST_not_full,
	LIST_empty,
	LIST_not_empty,
	LIST_null,

	unique_roll,
	repeated_roll

}Status_t;



void add_manually();

void add_file();

void find_roll();

void find_name();

int check_course(int32 course_id);
void find_courses();

void total_students();

void delete_student();

void update_roll(S_Student *P_temp);
void update_firstName(S_Student *P_temp);
void update_lastName(S_Student *P_temp);
void update_GPA(S_Student *P_temp);
void update_courses(S_Student *P_temp);
void update_all(S_Student *P_temp);
void update_student();

void display(S_Student *ptr);
void display_all();

/*************************** Extra Functions ************************/
void extract_file();
void switch_pos(S_Student *P_Current , S_Student *P_Next);
void sort_id();
/*
void sort();
void sort_id();
void sort_name();
void sort_grade();
*/


#endif /* STD_MANAGEMENT_H_ */
