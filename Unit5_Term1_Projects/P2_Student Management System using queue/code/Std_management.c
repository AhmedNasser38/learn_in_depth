/*
 * Std_management.c
 *
 *  Created on: Oct 10, 2021
 *      Author: Ahmed Nasser
 */
#include "Std_management.h"

/*************/
// Initialization
S_Student student[num_students];
S_Student *base = student;
S_Student *head = student;

uint32 length = 0;

uint32 total_courses[courses_num]={course1, course2 , course3 , course4 , course5 , course6 , course7 , course8 , course9 , course10};

/******************/
/********************************************** check Functions  *********************************/
// is_valid
Status_t is_valid(){
	if( !base || !head)
		return LIST_null;

	return LIST_no_error;
}

// check LIST is Full or not
Status_t is_full(){
	if(length == num_students )
		return LIST_full;
	return LIST_not_full;
}

// check LIST is Empty or not
Status_t is_empty(){
	if(length == 0 )
		return LIST_empty;
	return LIST_not_empty;
}
/********************************************** check the roll is unique or repeated  *********************************/
Status_t check_roll(uint32 roll){
	S_Student *temp = base;
	for(uint32 i=0 ; i < length ;i++){
		if((temp->roll_num == roll))
			return repeated_roll;
		temp++;
	}
	return unique_roll;
}

/************/
/********************************************** main Functions  *********************************/
/********************************************** add student info manually one by one  *********************************/
void add_manually(){
	int8 temp[10] , n_courses;
	uint32 course_id;

	if(is_valid() == LIST_null){
		print("\n[ERROR]The database isn't valid..... please Check it again.");
		return;
	}
	if((is_full() == LIST_not_full) && (is_valid() == LIST_no_error )){
		print("\nEnter Student Roll Number : ");
		gets(temp);
		head->roll_num = atoi(temp);

		if((check_roll(head->roll_num) == unique_roll)){
			print("\nEnter Student 1st Name : ");
			gets(head->first_name);

			print("\nEnter Student last Name : ");
			gets(head->last_name);

			print("\nEnter Student GPA:");
			gets(temp);
			head->GPA = atoi(temp);

			print("\nEnter Number of enrolled Courses: ");
			gets(temp);
			n_courses= atoi(temp);
			print("\nEnter Student enrolled Courses_id: ");
			for(int8 i=0; i < n_courses ; i++){
				print("\nCourse%d id: ",i+1);
				gets(temp);
				course_id = (uint32)atoi(temp);
				if (check_course(course_id))
					head->courses_id[i]= course_id;
				else{
					print("\n[ERROR]wrong course_id");
					update_courses(head);
				}

			}
			length++;
			head++;
		}else{
			print("\n[ERROR]This roll_number is Founded , it should be unique");
			add_manually();
		}
		total_students();
	}else{
		print("\n[ERROR]The database is Full.....You Can't add more. please increase the size in configuration section.");
	}
	return;
}
/********************************************** add students using text file *********************************/
void add_file(){

	int i=0;
	if(is_valid() == LIST_null){
		print("\n[ERROR]The database isn't valid..... please Check it again.");
		return;
	}
	if(is_full() == LIST_full){
		print("\n[ERROR]The database is Full.....You Can't add more. please increase the size in configuration section.");
		return;
	}
	FILE *f_ptr;
	f_ptr =fopen("student_database.txt","r");
	if(f_ptr){
		while((!feof(f_ptr)) && (length < num_students))
		{
			fscanf(f_ptr , "%d " ,&head->roll_num);
			if((check_roll(head->roll_num)) == unique_roll){
				fscanf(f_ptr , "%s %s %f" ,
						head->first_name , head->last_name , &head->GPA );
				do{
					fscanf(f_ptr , "%d",&head->courses_id[i]);
					i++;
				}while((getc(f_ptr) != '\n') && (!feof(f_ptr)));

				print("\n[INFO] Roll Number %d Saved Successfully",head->roll_num);

				length++;
				head++;

				i=0;
			}else{
				print("\n[ERROR] Roll Number %d is already taken ... so it was skipped ",head->roll_num);
				// to skip line which contain repeated roll number
				while((getc(f_ptr) != '\n'));
			}

		}

	}else{
		print("\n[ERORR] Can't Read This File");
	}
	fclose(f_ptr);
	display_all();
	total_students();
	return;
}
/********************************************** find student from it's roll_number  *********************************/
void find_roll(){

	if(is_valid() == LIST_null){
		print("\n[ERROR]The database isn't valid..... please Check it again.");
		return;
	}
	if(is_empty() == LIST_empty){
		print("\n[ERROR]The database is Empty.....There is no data to Find.");
		return;
	}

	int8 temp[10];
	uint32 roll;
	uint8 flag =1;
	is_valid();
	is_empty();
	print("\nEnter Student Roll Number You want to Find: ");
	gets(temp);
	roll = atoi(temp);

	S_Student *P_temp = base;
	for(uint32 i=0 ; i < length && flag;i++){
		if(P_temp->roll_num == roll){
			display(P_temp);
			flag = 0;
		}
		P_temp++;
	}
	if(flag){
		print("\n[ERROR]This Roll Number is not founded!!");
		find_roll();
	}

	return;
}
/********************************************** find all students from there first Name  *********************************/
void find_name(){

	if(is_valid() == LIST_null){
		print("\n[ERROR]The database isn't valid..... please Check it again.");
		return;
	}
	if(is_empty() == LIST_empty){
		print("\n[ERROR]The database is Empty.....There is no data to Find.");
		return;
	}

	int8 temp[25];
	uint8 flag =1;
	uint32 n_student=0;
	is_valid();
	is_empty();
	print("\nEnter Student First Name You want to Find: ");
	gets(temp);

	S_Student *P_temp = base;
	for(uint32 i=0 ; i < length  ;i++){
		if(strcmpi(P_temp->first_name , temp) == 0){
			display(P_temp);
			n_student++;
			flag =0;
		}
		P_temp++;
	}
	print("\n\n[INFO]%d Students has %s in their first name\n",n_student,temp);
	if(flag){
		print("\n[ERROR]This Name is not founded!!");
		find_name();
	}


	return;
}
/********************************************** check the id of course is exist or no  *********************************/
int check_course(int32 course_id){
	uint8 flag =0;
	for(uint32 k=0 ; k<courses_num;k++)
		if(course_id == total_courses[k])
			flag = 1;
	return flag;

}
/********************************************** find all students who enrolling in course  *********************************/
void find_courses(){
	if(is_valid() == LIST_null){
		print("\n[ERROR]The database isn't valid..... please Check it again.");
		return;
	}
	if(is_empty() == LIST_empty){
		print("\n[ERROR]The database is Empty.....There is no data to Find.");
		return;
	}
	int8 temp[10];
	uint32 course_id;
	int32 flag ;
	uint32 n_student=0;
	is_valid();
	is_empty();
	print("\nEnter Course id You want to Find Students who enrolling on it: ");
	gets(temp);
	course_id = atoi(temp);
	flag = check_course(course_id);
	if(flag){
		S_Student *P_temp = base;
		for(uint32 i=0 ; i < length;i++){
			for(uint8 j=0 ; j < courses_num ; j++){
				if(P_temp->courses_id[j] == course_id){
					display(P_temp);
					j=10;
					n_student++;
				}
			}
			P_temp++;
		}
		print("\n[INFO]%d rolled in This Course",n_student);
	}else
	{
		print("\n[ERROR]This Course id is not founded!!");
		find_courses();
	}

	return;
}
/********************************************** show the Number of students  *********************************/
void total_students(){
	print("\n-------------------------------------------");
	print("\n[INFO]Total number of students is %d" , length );
	print("\n[INFO]You can add up to %d Students" , num_students);
	print("\n[INFO]You can add %d more Students" , (num_students -length));
	print("\n-------------------------------------------");
	return;
}
/********************************************** Delete Specific  Roll  Number of students  *********************************/

void Delete_Specefic (uint32 Roll){

	    S_Student *P_Current = base;
		S_Student *P_Pre = P_Current++ ;

		if(is_valid() == LIST_null){
			print("\n[ERROR]The database isn't valid..... please Check it again.");
			return;
		}
		if(is_empty() == LIST_empty){
			print("\n[ERROR]The database is Empty.....There is no data to add to the file.");
			return;
		}

		if(P_Pre->roll_num == Roll){

		}else{
		while((P_Current->roll_num != Roll)&&(P_Current <= head)){
			P_Current++;
			P_Pre++;
		}

		P_Current++;
		P_Pre++;}
		if(P_Pre <= head){
		while(P_Current < head){


//			if(P_Current->roll_num < P_Next->roll_num){
				switch_pos(P_Current,P_Pre);
//				P_Current =base;
//				P_Next = P_Current++;}

			P_Pre++;
			P_Current++;

		}
		head--;
		length--;
		print("\n[INFO]Delete Roll %d is done successfully ",Roll);
		}else{
			print("\n[ERROR]Roll %d is not founded ",Roll);
		}
		return;



}

/********************************************** Delete student info *********************************/
void delete_student(){
	int8 temp[10];
	uint32  choice =0 ,Roll = 0;
	if(is_valid() == LIST_null){
		print("\n[ERROR]The database isn't valid..... please Check it again.");
		return;
	}
	if(is_empty() == LIST_empty){
		print("\n[ERROR]The database is Empty.....There is no data to Delete.");
		return;
	}
	print("\nChoice what You want to do");
	print("\n1-Delete Last Student");
	print("\n2-Delete Specific Student by Roll Number\n")
	gets(temp);
	choice = atoi(temp);
	switch(choice){
	case 1 :
		head--;
		length--;
		print("\n[INFO]Delete Done");
		break;
	case 2 :
		print("\nEnter Student Roll Number You want to Delete: ");
		gets(temp);
		Roll = atoi(temp);
		Delete_Specefic(Roll);
		break;
	default :
		print("\n[ERROR]Wrong Choice");
		delete_student();
		break;
	}

	return;
}
/********************************************** update student roll *********************************/
void update_roll(S_Student *P_temp){
	int8 temp[10];
	uint32 roll;
	print("\nEnter New Student Roll Number : ");
	gets(temp);
	roll = atoi(temp);

	if(check_roll(roll) == unique_roll){
		P_temp->roll_num = roll;
	}else{
		print("\n[ERROR]This Roll Number is not Repeated !! Try Again ");
		update_roll(P_temp);
	}
	return;

}
/********************************************** update student first Name *********************************/
void update_firstName(S_Student *P_temp){
	print("\nEnter Student 1st Name : ");
	gets(P_temp->first_name);
	return;
}
/********************************************** update student last Name *********************************/
void update_lastName(S_Student *P_temp){
	print("\nEnter Student last Name : ");
	gets(P_temp->last_name);
	return;
}
/********************************************** update student GPA *********************************/
void update_GPA(S_Student *P_temp){
	int8 temp[10];

	print("\nEnter Student GPA:");
	gets(temp);
	P_temp->GPA = atof(temp);
	return;
}
/********************************************** update student courses *********************************/
void update_courses(S_Student *P_temp){
	int8 temp[10];
	int32 n_courses , course_id;

	print("\nEnter Number of enrolled Courses: ");
	gets(temp);
	n_courses= atoi(temp);
	// init courses array to zero;
	for(uint32 i=0 ; i< courses_num;i++)
		P_temp->courses_id[i] = 0;

	print("\nEnter Student enrolled Courses_id: ");
	for(int8 i=0; i < n_courses ; i++){
		print("\nCourse%d id: ",i+1);
		gets(temp);
		course_id = atoi(temp);
		if (check_course(course_id))
			P_temp->courses_id[i]= course_id;
		else{
			print("\n[ERROR]wrong course_id");
			update_courses(P_temp);
		}

	}
	return;
}
/********************************************** update student all info *********************************/
void update_all(S_Student *P_temp){
	update_roll(P_temp);
	update_firstName(P_temp);
	update_lastName(P_temp);
	update_GPA(P_temp);
	update_courses(P_temp);
	return;
}
/********************************************** update student in the list *********************************/
void update_student(){

	if(is_valid() == LIST_null){
		print("\n[ERROR]The database isn't valid..... please Check it again.");
		return;
	}
	if(is_empty() == LIST_empty){
		print("\n[ERROR]The database is Empty.....There is no data to Update.");
		return;
	}

	int8 temp[10];
	uint32 roll , choice;
	is_valid();
	is_empty();
	uint8 flag = 1;
	print("\nEnter Student Roll Number You want to Update: ");
	gets(temp);
	roll = atoi(temp);

	S_Student *P_temp = base;
	for(uint32 i=0 ; (i < length) && flag ;i++){
		if(P_temp->roll_num == roll){
			flag = 0;
			display(P_temp);

			print("\nChoose which part you need to update");
			print("\n1. all info");
			print("\n2. Roll Number ");
			print("\n3. First Name");
			print("\n4. Last Name");
			print("\n5. GPA");
			print("\n6. Enrolled Courses");
			print("\n\nEnter Your choice");
			gets(temp);
			choice = atoi(temp);
			switch(choice){
			case 1:
				update_all(P_temp);
				break;
			case 2:
				update_roll(P_temp);
				break;
			case 3:
				update_firstName(P_temp);
				break;
			case 4:
				update_lastName(P_temp);
				break;
			case 5:
				update_GPA(P_temp);
				break;
			case 6:
				update_courses(P_temp);
				break;
			default :
				print("\n[ERROR]Wrong choice!!");
				break;
			}
		}
		P_temp++;
	}
	if(flag){
		print("\n[ERROR]The Roll number is not founded! ");
		update_student();
	}
	return;
}
/********************************************** show one student *********************************/
void display(S_Student *ptr){

	uint32 i=0;
	print("\nRoll Number : %d",ptr->roll_num);
	print("\nFirst Name : %s",ptr->first_name);
	print("\nLast Name : %s",ptr->last_name);
	print("\nGPA : %0.2f",ptr->GPA);
	print("\nEnrolled Courses id : ");

	while(ptr->courses_id[i] != 0){
		print("\t%d",ptr->courses_id[i]);
		i++;
	}

	return;
}
/********************************************** show all students in the list *********************************/
void display_all(){

	if(is_valid() == LIST_null){
		print("\n[ERROR]The database isn't valid..... please Check it again.");
		return;
	}
	if(is_empty() == LIST_empty){
		print("\n[ERROR]The database is Empty.....There is no data to show.");
		return;
	}
	S_Student *currentStudent = base;
	for(uint32 i=0;i<length;i++){
		display(currentStudent);
		currentStudent++;
	}
	return;
}
/********************************************** add students using text file *********************************/
void extract_file(){
	S_Student *P_temp = base;
	int32 i=0 , counter =0;

	if(is_valid() == LIST_null){
		print("\n[ERROR]The database isn't valid..... please Check it again.");
		return;
	}
	if(is_empty() == LIST_empty){
		print("\n[ERROR]The database is Empty.....There is no data to add to the file.");
		return;
	}

	FILE *f_ptr;
	f_ptr =fopen("student_database_extracted.txt","w+");
	if(f_ptr){
		while(P_temp < head)
		{

			fprintf(f_ptr , "%d %s %s %0.2f" ,
					P_temp->roll_num , P_temp->first_name , P_temp->last_name , P_temp->GPA );
			while((i < courses_num) && (P_temp->courses_id[i] != 0)){
				fprintf(f_ptr , " %d",P_temp->courses_id[i]);
				i++;
			}

			counter++;
			// to add a new line and avoid add an empty line in the end of the file
			if(counter < length)
				fputc('\n',f_ptr);

			P_temp++;

			i=0;
		}
		print("\n[INFO] Writing on File Successfully");
	}else{
		print("\n[ERORR] Can't Write on This File");
	}
	fclose(f_ptr);
	return;
}
/********************************************** sort students by id *********************************/
void sort_id(){
	S_Student *P_Current = base;
	S_Student *P_Next = P_Current++;

	if(is_valid() == LIST_null){
		print("\n[ERROR]The database isn't valid..... please Check it again.");
		return;
	}
	if(is_empty() == LIST_empty){
		print("\n[ERROR]The database is Empty.....There is no data to add to the file.");
		return;
	}

	while(P_Current < head){

		if(P_Current->roll_num < P_Next->roll_num){
			switch_pos(P_Current,P_Next);
			P_Current =base;
			P_Next = P_Current++;
		}

		P_Next++;
		P_Current++;

	}
	print("\n[INFO]Sort done successfully ");
	return;
}

void switch_pos(S_Student *P_Current , S_Student *P_Next){
	S_Student P_temp;

	P_temp.roll_num = P_Current->roll_num;
	for(uint8 i=0 ; i<25;i++){
		P_temp.first_name[i] = P_Current->first_name[i];
		P_temp.last_name[i] = P_Current->last_name[i];
	}
	P_temp.GPA = P_Current->GPA;
	for(uint8 i=0; i < courses_num ; i++ )
		P_temp.courses_id[i] = P_Current->courses_id[i];


	P_Current->roll_num = P_Next->roll_num;
	for(uint8 i=0 ; i<25;i++){
		P_Current->first_name[i] = P_Next->first_name[i];
		P_Current->last_name[i] = P_Next->last_name[i];
	}
	P_Current->GPA = P_Next->GPA;
	for(uint8 i=0; i < courses_num ; i++ )
		P_Current->courses_id[i] = P_Next->courses_id[i];

	P_Next->roll_num = P_temp.roll_num;
	for(uint8 i=0 ; i<25;i++){
		P_Next->first_name[i] = P_temp.first_name[i];
		P_Next->last_name[i] = P_temp.last_name[i];
	}
	P_Next->GPA = P_temp.GPA;
	for(uint8 i=0; i < courses_num ; i++ )
		P_Next->courses_id[i] = P_temp.courses_id[i];


	return;
}

