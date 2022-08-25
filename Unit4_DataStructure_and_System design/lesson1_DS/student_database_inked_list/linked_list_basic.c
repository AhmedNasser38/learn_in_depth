/*
 * linked_list.c
 *
 *  Created on: Sep 25, 2021
 *      Author: Ahmed Nasser
 */
#include"linked_list.h"

struct S_student* GPFirstStudent = NULL;

/*************************************************<<<<<<<<<<<<<<<<<<< fill_record Function >>>>>>>>>>>>>>>***********************************************/

void fill_record(struct S_student* next_student){

	int8 temp[10] ;

	if(next_student){
		print("\nEnter the student ID : ");
		gets(temp);
		next_student->student.ID = atoi(temp);

		print("\nEnter the student Name : ");
		gets(next_student->student.name);

		print("\nEnter the student Height : ");
		gets(temp);
		next_student->student.height = atof(temp);

		print("\nEnter the student Grade : ");
		gets(temp);
		next_student->student.grade = atoi(temp);

	}else{
	print("\nNot valid database ..... please try again!!\n");
	}
}

/*************************************************<<<<<<<<<<<<<<<<<<< add_student Function >>>>>>>>>>>>>>>***********************************************/

void add_student(){
	struct S_student* PNewStudent;
	struct S_student* PLastStudent;
	// check list empty or not
	if(GPFirstStudent == NULL){
		// empty list
		PNewStudent = (struct S_student*) malloc(sizeof(struct S_student));
		GPFirstStudent = PNewStudent;

	}else{ // not empty list
		// navigate until last student
		PLastStudent = GPFirstStudent;
		while(PLastStudent->PNextStudent)
			PLastStudent= PLastStudent->PNextStudent ;

		// create a new student

		PNewStudent = (struct S_student*) malloc(sizeof(struct S_student));
		PLastStudent->PNextStudent =  PNewStudent;

	}

	fill_record(PNewStudent);
	PNewStudent->PNextStudent = NULL;
}


/*************************************************<<<<<<<<<<<<<<<<<<< delete_student Function >>>>>>>>>>>>>>>***********************************************/

void delete_student(){
	int8 temp[10];
	uint8 selected_id;

	print("\nEnter the student ID you want to delete : ");
	gets(temp);
	selected_id = (uint8)atoi(temp);

	if(GPFirstStudent){

		struct S_student* PPreStudent = NULL;
		struct S_student* PSelectedStudent = GPFirstStudent;

		while(PSelectedStudent){

			if(PSelectedStudent->student.ID == selected_id){

				if(PPreStudent){ // selected is not the 1st student

					PPreStudent->PNextStudent = PSelectedStudent->PNextStudent;

				}else{ // selected is the 1st student

					GPFirstStudent = PSelectedStudent->PNextStudent;

				}

				free(PSelectedStudent);
				print("\nStudent who has id = %d is deleted correctly.",selected_id);
				return;

			}

			PPreStudent = PSelectedStudent;
			PSelectedStudent = PSelectedStudent->PNextStudent;
		}
	}

	print("\nCan't find student id .");
	return;
}

/*************************************************<<<<<<<<<<<<<<<<<<< Display_all Function >>>>>>>>>>>>>>>***********************************************/

void display_students(){

	uint32 count =1;
	struct S_student* PCurrentStudent = GPFirstStudent;

	if(GPFirstStudent){
		while(PCurrentStudent){

			print("\n\t\tRecord Number : %d",count);
			print("\nStudent Name : %s",PCurrentStudent->student.name);
			print("\nStudent Id : %d",PCurrentStudent->student.ID);
			print("\nStudent Grade : %d",PCurrentStudent->student.grade);
			print("\nStudent Height : %f",PCurrentStudent->student.height);
			print("\n\t===============================\t");
			PCurrentStudent = PCurrentStudent->PNextStudent;
			count++;

		}
		print("\nList is printed successfully !");
		return;
	}
	print("\nList is Empty!");
	return;

}

/*************************************************<<<<<<<<<<<<<<<<<<< delete_all Function >>>>>>>>>>>>>>>***********************************************/

void delete_all(){

	struct S_student* PCurrentStudent = GPFirstStudent;
	if(GPFirstStudent){

		while(PCurrentStudent){

			struct S_student* PTempStudent = PCurrentStudent;
			PCurrentStudent = PCurrentStudent->PNextStudent;
			free(PTempStudent);

		}
		GPFirstStudent =NULL;

	}else{
		print("\nList is already Empty");
	}
}

/*************************************************<<<<<<<<<<<<<<<<<<< Start of Advanced Function >>>>>>>>>>>>>>>***********************************************/

/*************************************************<<<<<<<<<<<<<<<<<<< Get_node_begin Function >>>>>>>>>>>>>>>***********************************************/
void get_node_from_begin(uint32 node){

	uint32 count = 1;
	int8 temp[10];
	struct S_student* PCurrentStudent = GPFirstStudent;

	if(GPFirstStudent){
		print("\nEnter Node Number : ");
		gets(temp);
		node =atoi(temp);

		while((PCurrentStudent)){
			if(node == count){

				print("\n\t\tRecord Number : %d",count);
				print("\nStudent Name : %s",PCurrentStudent->student.name);
				print("\nStudent Id : %d",PCurrentStudent->student.ID);
				print("\nStudent Grade : %d",PCurrentStudent->student.grade);
				print("\nStudent Height : %f",PCurrentStudent->student.height);
				return;

			}else{

				PCurrentStudent = PCurrentStudent->PNextStudent;
				count++;
			}
		}

		print("\nThis Node over the length of the list \n");

	}else{
		print("\n List is Empty !!");
	}
	return;
}

/*************************************************<<<<<<<<<<<<<<<<<<< Get_node_end Function >>>>>>>>>>>>>>>***********************************************/

void get_node_from_end(uint32 node){

	/*
	   //Method 1
	  if(GPFirstStudent){
	    uint32 len = length();
	    get_node_from_begain(len - node +1);
	    }else{

		print("\n List is Empty !!");

	  }

	 */
	uint8 i;
	int8 temp[10];
	// Method 2
	if(GPFirstStudent){
			print("\nEnter Node Number : ");
			gets(temp);
			node =atoi(temp);
			struct S_student* Pmain = GPFirstStudent;
			struct S_student* Pref = GPFirstStudent;
			for(i = 0 ; i < node ; i++)
				Pref = Pref->PNextStudent;
			while(Pref){
				Pref = Pref->PNextStudent;
				Pmain =Pmain->PNextStudent;
			}

			print("\n\t\tRecord Number from the End: %d",node);
			print("\nStudent Name : %s",Pmain->student.name);
			print("\nStudent Id : %d",Pmain->student.ID);
			print("\nStudent Grade : %d",Pmain->student.grade);
			print("\nStudent Height : %f",Pmain->student.height);

			return;

	}else{

		print("\n List is Empty !!");

	}
	return;
}

/*************************************************<<<<<<<<<<<<<<<<<<< Get_node_middle Function >>>>>>>>>>>>>>>***********************************************/

void mid(){
	/*
				//Method1
			if(GPFirstStudent){
				uint32 mid = length()/2;
				 if(mid%2)
					 get_node_from_begain(mid+1);
				 else
					 get_node_from_begain(mid);
			}else{
				print("\n List is Empty !!");
			}

	  */

		//Method2
	uint32 count =1;
	if(GPFirstStudent){
			struct S_student* PSlow = GPFirstStudent;
			struct S_student* PFast = GPFirstStudent;

			while(PFast){

				PFast = PFast->PNextStudent;

				while(PFast){

					PFast = PFast->PNextStudent;
				    PSlow =PSlow->PNextStudent;
				    count++;

				}
			}

			print("\n\t\tRecord Number : %d",count);
			print("\nStudent Name : %s",PSlow->student.name);
			print("\nStudent Id : %d",PSlow->student.ID);
			print("\nStudent Grade : %d",PSlow->student.grade);
			print("\nStudent Height : %f",PSlow->student.height);

			return;

		}else{

			print("\n List is Empty !!");

		}
	return;
}

/*************************************************<<<<<<<<<<<<<<<<<<< Get_node_general Function >>>>>>>>>>>>>>>***********************************************/

void get_node(uint32 node){
	int8 choice , temp[5];

	print("\n1 : Get node from the beginning ");
	print("\n2 : Get node from the End ");
	print("\n3 : Get the middle Student in list");
	print("\nEnter Your choice : ");
	gets(temp);
	choice =atoi(temp);


	switch(choice){
		case 1 :
			get_node_from_begin(node);
			break;
		case 2 :
			get_node_from_end(node);
			break;
		case 3 :
			mid();
			break;
		default :
			print("\n Wrong choice...");
			break;
	}
}

/*************************************************<<<<<<<<<<<<<<<<<<< length Function >>>>>>>>>>>>>>>***********************************************/

int length(){

	uint32 count=0;
	struct S_student* PCurrentStudent = GPFirstStudent;
	if(GPFirstStudent){

	while(PCurrentStudent){
		PCurrentStudent = PCurrentStudent->PNextStudent;
		count++;
	}

	}
	return count;
}

/*************************************************<<<<<<<<<<<<<<<<<<< detect_loop Function >>>>>>>>>>>>>>>***********************************************/

int detect_loop(){

	if(GPFirstStudent){
		struct S_student* PSlow = GPFirstStudent;
		struct S_student* PFast = GPFirstStudent;

		while(PFast && PSlow){

			PFast = PFast->PNextStudent;
			PSlow =PSlow->PNextStudent;
			PFast = PFast->PNextStudent;
			if(PFast == PSlow){
				print("\nThere's loop in List");
				return 1;
			}

			print("\nThere's no loop in List");
			return 0;
		}
	}else{
		print("\n List is Empty !!");
	}
	return 0;
}

/*************************************************<<<<<<<<<<<<<<<<<<< Sort_id Function >>>>>>>>>>>>>>>***********************************************/

void sort_id(){
	if(GPFirstStudent){
		int flag;

		struct S_student *PCurrentStudent , *PPrevStudent ;
		struct S_student* PTemp = NULL , *PSwap = NULL;
		do{
			flag =0 ;
			PCurrentStudent = GPFirstStudent;
			PPrevStudent    = GPFirstStudent;
			while(PCurrentStudent && (PCurrentStudent->PNextStudent != PTemp)){
				if((PCurrentStudent->student.ID) > (PCurrentStudent->PNextStudent->student.ID)){

					if((PCurrentStudent == GPFirstStudent) ){

						PSwap = PCurrentStudent->PNextStudent->PNextStudent;
						PCurrentStudent->PNextStudent->PNextStudent = PCurrentStudent;
						GPFirstStudent = PCurrentStudent->PNextStudent;
						PCurrentStudent->PNextStudent = PSwap;

						print("this piece work");

					}else if(PCurrentStudent->PNextStudent ){

						PPrevStudent->PNextStudent = PCurrentStudent->PNextStudent;
						PSwap = PCurrentStudent->PNextStudent->PNextStudent;
						PCurrentStudent->PNextStudent->PNextStudent = PCurrentStudent;
						PCurrentStudent->PNextStudent = PSwap;

					}
					flag =1;
				}
				PPrevStudent = PCurrentStudent;
				PCurrentStudent = PCurrentStudent->PNextStudent;
			}
			PTemp = PCurrentStudent;
		}while(flag);

	}else{
		print("\nList is Empty.")
	}

}

/*************************************************<<<<<<<<<<<<<<<<<<< Sort_grade Function >>>>>>>>>>>>>>>***********************************************/

void sort_grade(){
	if(GPFirstStudent){
			int temp , flag;

			struct S_student* PCurrentStudent ;
			struct S_student* PTemp = NULL;
			do{
				flag =0 ;
				PCurrentStudent = GPFirstStudent;
				while(PCurrentStudent->PNextStudent != PTemp){
					if((PCurrentStudent->student.grade) > (PCurrentStudent->PNextStudent->student.grade)){
						// swap two values
						temp = PCurrentStudent->student.grade;
						PCurrentStudent->student.grade = PCurrentStudent->PNextStudent->student.grade;
						PCurrentStudent->PNextStudent->student.grade = temp;

						flag =1;
					}
					PCurrentStudent = PCurrentStudent->PNextStudent;
				}
				PTemp = PCurrentStudent;
			}while(flag);

		}else{
			print("\nList is Empty.")
		}


}

/*************************************************<<<<<<<<<<<<<<<<<<< Sort_names Function >>>>>>>>>>>>>>>***********************************************/

//void sort_name(struct S_student* PFirstStudent){
//
//	if(PFirstStudent){
//				int temp , i , flag;
//
//				struct S_student* PCurrentStudent ;
//				struct S_student* PTemp = NULL;
//				do{
//					flag =0 ;
//					PCurrentStudent = PFirstStudent;
//					while(PCurrentStudent->PNextStudent != PTemp){
//						if((PCurrentStudent->student.name) > (PCurrentStudent->PNextStudent->student.name)){
//							// swap two values
//							temp = PCurrentStudent->student.name;
//							PCurrentStudent->student.name = PCurrentStudent->PNextStudent->student.name;
//							PCurrentStudent->PNextStudent->student.name = temp;
//
//							flag =1;
//						}
//						PCurrentStudent = PCurrentStudent->PNextStudent;
//					}
//					PTemp = PCurrentStudent;
//				}while(flag);
//
//			}else{
//				print("\nList is Empty.")
//			}
//}

/*************************************************<<<<<<<<<<<<<<<<<<< Sort_general Function >>>>>>>>>>>>>>>***********************************************/

void sort(){

	int8 choice , temp[5];

	print("\n1 : Sort By ID");
	print("\n2 : Sort By Grade ");
	//print("\n3 : Sort By Name");
	print("\nEnter Your choice : ");
	gets(temp);
	choice =atoi(temp);

	switch(choice){
	case 1 :
		sort_id();
		break;
	case 2 :
		sort_grade();
		break;
//	case 3 :
//		sort_name();
//		break;
	default :
		print("\n Wrong choice...");
		break;
	}

}

/*************************************************<<<<<<<<<<<<<<<<<<< Reverse Function >>>>>>>>>>>>>>>***********************************************/

void reverse(){
	struct S_student *PCurrentStudent_end = GPFirstStudent , *PPrevStudent = NULL;
	struct S_student *PNave , *PLast;

	while(PCurrentStudent_end->PNextStudent){

		PPrevStudent = PCurrentStudent_end;
		PCurrentStudent_end = PCurrentStudent_end->PNextStudent;

	}

	PLast = PCurrentStudent_end;

	do{

		PNave = GPFirstStudent;

		while((PNave->PNextStudent != PPrevStudent) && (PNave != PPrevStudent))
			PNave = PNave->PNextStudent;

		PCurrentStudent_end->PNextStudent = PPrevStudent;
		PCurrentStudent_end = PPrevStudent;
		PPrevStudent = PNave;

	}while(PPrevStudent != GPFirstStudent);

	PCurrentStudent_end->PNextStudent = PPrevStudent;
	PPrevStudent->PNextStudent = NULL;
	GPFirstStudent = PLast;

	return;
}

/*************************************************<<<<<<<<<<<<<<<<<<< Search Function >>>>>>>>>>>>>>>***********************************************/

void search_student(){
	int8 temp[10];
	uint8 selected_id , count=1;

	print("\nEnter the student ID you want to view : ");
	gets(temp);
	selected_id = (uint8)atoi(temp);

	if(GPFirstStudent){

		struct S_student* PPreStudent = NULL;
		struct S_student* PSelectedStudent = GPFirstStudent;

		while(PSelectedStudent){

			if(PSelectedStudent->student.ID == selected_id){

				print("\n\t\tRecord Number : %d",count);
				print("\nStudent Name : %s",PSelectedStudent->student.name);
				print("\nStudent Id : %d",PSelectedStudent->student.ID);
				print("\nStudent Grade : %d",PSelectedStudent->student.grade);
				print("\nStudent Height : %f",PSelectedStudent->student.height);
				return;

			}

			PPreStudent = PSelectedStudent;
			PSelectedStudent = PSelectedStudent->PNextStudent;
			count++;
		}
	}

	print("\nCan't find student id .");
	return;
}

/*************************************************<<<<<<<<<<<<<<<<<<< Edit Function >>>>>>>>>>>>>>>***********************************************/

void edit_student(){

	struct S_student* PSelectedStudent = GPFirstStudent;

	int8 choice , id , temp[10];


	print("\nEnter student ID  you want to edit: ");
	gets(temp);
	id = atoi(temp);


	print("\n1 : Edit all data");
	print("\n1 : Edit ID");
	print("\n2 : Edit Grade ");
	print("\n3 : Edit Name");
	print("\n4 : Edit Height");
	print("\nEnter Your choice : ");
	gets(temp);
	choice =atoi(temp);


	// get selected id
	while(PSelectedStudent){

		if(PSelectedStudent->student.ID == id){

			switch(choice){
			case 1 :
				Print("\nEnter new name");
				gets(PSelectedStudent->student.name);
				Print("\nEnter new id");
				gets(temp);
				PSelectedStudent->student.ID = atoi(temp);
				Print("\nEnter new grade");
				gets(temp);
				PSelectedStudent->student.grade = atoi(temp);
				Print("\nEnter new height");
				gets(temp);
				PSelectedStudent->student.height = atof(temp);
				break;
			case 2 :
				Print("\nEnter new id");
				gets(temp);
				PSelectedStudent->student.ID = atoi(temp);
				break;
			case 3 :
				Print("\nEnter new grade");
				gets(temp);
				PSelectedStudent->student.grade = atoi(temp);
				break;
			case 4 :
				Print("\nEnter new height");
				gets(temp);
				PSelectedStudent->student.height = atof(temp);
				break;

			default :
				print("\n Wrong choice...");
				break;

			}
			return;
		}

		PSelectedStudent = PSelectedStudent->PNextStudent;
	}
}
