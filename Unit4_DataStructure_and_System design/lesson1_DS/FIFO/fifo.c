/*
 * fifo.c
 *
 *  Created on: Sep 23, 2021
 *      Author: Ahmed Nasser
 */

#include "fifo.h"


// Initialization FIFO
FIFO_Status_t FIFO_init(FIFO_BUF_t* fifo_buf , data_type* buf , uint32 length){

	if( buf == NULL ){
		printf("initialization FIFO ..........>>>Failed \n");
		printf("===============================================\n");
		return FIFO_null;
	}
	fifo_buf->length = length;
	fifo_buf->base = buf;
	fifo_buf->head = buf;
	fifo_buf->tail = buf;
	fifo_buf->count = 0;

	printf("initialization FIFO ..........>>>Done successfully \n");
	printf("===============================================\n");
	return FIFO_no_error;
}

// check FIFO is Full or not
FIFO_Status_t FIFO_is_full(FIFO_BUF_t* fifo_buf ){
	uint32 length = fifo_buf->length;
	if(fifo_buf->head == (fifo_buf->base + length * sizeof(data_type)) )
		return FIFO_full;
	return FIFO_not_full;

}

// check FIFO is Empty or not
FIFO_Status_t FIFO_is_empty(FIFO_BUF_t* fifo_buf ){

	if(fifo_buf->head == fifo_buf->base )
		return FIFO_empty;
	return FIFO_not_empty;

}

// push element to FIFO
FIFO_Status_t FIFO_push(FIFO_BUF_t* fifo_buf , data_type item){

	if( !fifo_buf->base || !fifo_buf->head ){
		printf("PUSH into FIFO ....->Failed not valid FIFO \n");
		printf("===============================================\n");
		return FIFO_null;
	}
	if((FIFO_is_full(fifo_buf)) == FIFO_full){
		printf("PUSH into FIFO ..........>>>Failed Full FIFO \n");
		printf("===============================================\n");
		return FIFO_full;
	}

	*(fifo_buf->head) = item;
	fifo_buf->head++;
	fifo_buf->count++;

	printf("PUSH into FIFO ..........>>>success \n");
	printf("===============================================\n");
	return FIFO_no_error;
}

// get the last entered element and delete it from FIFO
FIFO_Status_t FIFO_pop(FIFO_BUF_t* fifo_buf , data_type* item ){

	if( !fifo_buf->base || !fifo_buf->head ){
		printf("POP from FIFO ....->Failed not valid FIFO \n");
		printf("===============================================\n");
		return FIFO_null;
	}
	if((FIFO_is_empty(fifo_buf )) == FIFO_empty){
		printf("POP from FIFO ..........>>>Failed Empty FIFO \n");
		printf("===============================================\n");
		return FIFO_empty;
	}


	*item = *(fifo_buf->tail) ;
	fifo_buf->tail++;
	fifo_buf->count--; //?>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>??????

	printf("POP from FIFO ..........>>>success \n");
	printf("===============================================\n");
	return FIFO_no_error;
}

// get the last element without deleting it
FIFO_Status_t FIFO_read(FIFO_BUF_t* fifo_buf , data_type* item){

	if( !fifo_buf->base || !fifo_buf->head ){
		printf("READ from FIFO ....->Failed not valid FIFO \n");
		printf("===============================================\n");
		return FIFO_null;
	}
	if((FIFO_is_empty(fifo_buf )) == FIFO_empty){
		printf("READ from FIFO ..........>>>Failed Empty FIFO \n");
		printf("===============================================\n");
		return FIFO_empty;
	}

	*item = *(fifo_buf->tail) ;

	printf("READ from FIFO ..........>>>success \n");
	printf("===============================================\n");
	return FIFO_no_error;
}

// delete the last element without getting it
FIFO_Status_t FIFO_delete(FIFO_BUF_t* fifo_buf){

	if( !fifo_buf->base || !fifo_buf->head ){
		printf("DELETE from FIFO ....->Failed not valid FIFO \n");
		printf("===============================================\n");
		return FIFO_null;
	}
	if((FIFO_is_empty(fifo_buf )) == FIFO_empty){
		printf("DELETE from FIFO ..........>>>Failed Empty FIFO \n");
		printf("===============================================\n");
		return FIFO_empty;
	}

	fifo_buf->head-- ;
	fifo_buf->count--;

	printf("DELETE from FIFO ..........>>>success \n");
	printf("===============================================\n");
	return FIFO_no_error;
}

// delete all elements
FIFO_Status_t FIFO_clear(FIFO_BUF_t* fifo_buf){

	if( !fifo_buf->base || !fifo_buf->head ){
		printf("CLEAR FIFO ....->Failed not valid FIFO \n");
		printf("===============================================\n");
		return FIFO_null;
	}
	if((FIFO_is_empty(fifo_buf)) == FIFO_empty){
		printf("CLEAR FIFO ..........>>>Failed Empty FIFO \n");
		printf("===============================================\n");
		return FIFO_empty;
	}

	fifo_buf->head = fifo_buf->base;
	fifo_buf->tail = fifo_buf->base;
	fifo_buf->count = 0;

	printf("CLEAR FIFO ..........>>>success \n");
	printf("===============================================\n");
	return FIFO_no_error;
}

// print all elements
FIFO_Status_t FIFO_print(FIFO_BUF_t* fifo_buf){

	data_type* temp_ptr = fifo_buf->base;

	if( !fifo_buf->base || !fifo_buf->head ){
		printf("PRINT FIFO ....->Failed not valid FIFO \n");
		printf("===============================================\n");
		return FIFO_null;
	}
	if((FIFO_is_empty(fifo_buf)) == FIFO_empty){
		printf("PRINT FIFO ..........>>>Failed Empty FIFO \n");
		printf("===============================================\n");
		return FIFO_empty;
	}

	while((temp_ptr) < (fifo_buf->head)){

		printf(data_symbol ,*(temp_ptr));
		temp_ptr++;
	}
	printf("FIFO is printed successfully!!\n");
	printf("===============================================\n");
	return FIFO_no_error;
}

// fill FIFO randomly
FIFO_Status_t FIFO_rand_fill(FIFO_BUF_t* fifo_buf , uint32 max){

	uint32 i , length = fifo_buf->length;

	if( !fifo_buf->base || !fifo_buf->head ){
		printf("random fill FIFO ....->Failed not valid FIFO \n");
		printf("===============================================\n");
		return FIFO_null;
	}
	if((FIFO_is_full(fifo_buf)) == FIFO_full){
		printf("random fill FIFO ..........>>>Failed Full FIFO \n");
		printf("===============================================\n");
		return FIFO_full;
	}

	for( i = 0; i<length ; i++){

		*(fifo_buf->head) = rand()%(max+1);
		fifo_buf->head++;
	}
	printf("FIFO is filled randomly success!! \n");
	printf("===============================================\n");
	return FIFO_no_error;
}
// push all elements from start data to the end of FIFO incrementally
FIFO_Status_t FIFO_seq_inc_fill(FIFO_BUF_t* fifo_buf , uint32 start){


	uint32 i , length = fifo_buf->length;

	if( !fifo_buf->base || !fifo_buf->head ){
		printf("random fill FIFO ....->Failed not valid FIFO \n");
		printf("===============================================\n");
		return FIFO_null;
	}
	if((FIFO_is_full(fifo_buf)) == FIFO_full){
		printf("random fill FIFO ..........>>>Failed Full FIFO \n");
		printf("===============================================\n");
		return FIFO_full;
	}

	for( i = 0; i<length ; i++){

		*(fifo_buf->head) = start;
		fifo_buf->head++;
		start++;
	}
	printf("FIFO is filled with sequence success!! \n");
	printf("===============================================\n");
	return FIFO_no_error;

}
// push all elements from start data to the end of FIFO decrement
FIFO_Status_t FIFO_seq_dec_fill(FIFO_BUF_t* fifo_buf , uint32 start){


	uint32 i , length = fifo_buf->length;

	if( !fifo_buf->base || !fifo_buf->head ){
		printf("random fill FIFO ....->Failed not valid FIFO \n");
		printf("===============================================\n");
		return FIFO_null;
	}
	if((FIFO_is_full(fifo_buf)) == FIFO_full){
		printf("random fill FIFO ..........>>>Failed Full FIFO \n");
		printf("===============================================\n");
		return FIFO_full;
	}

	for( i = 0; i<length ; i++){

		*(fifo_buf->head) = start;
		fifo_buf->head++;
		start--;
	}
	printf("FIFO is filled with sequence success!! \n");
	printf("===============================================\n");
	return FIFO_no_error;

}















