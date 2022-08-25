/*
 * lifo.c
 *
 *  Created on: Sep 23, 2021
 *      Author: Ahmed Nasser
 */

#include "lifo.h"


// Initialization LIFO
LIFO_Status_t LIFO_init(LIFO_BUF_t* lifo_buf , data_type* buf , uint32 length){

	if( buf == NULL ){
		printf("initialization LIFO ..........>>>Failed \n");
		printf("===============================================\n");
		return LIFO_null;
	}
	lifo_buf->length = length;
	lifo_buf->base = buf;
	lifo_buf->head = buf;
	lifo_buf->count = 0;

	printf("initialization LIFO ..........>>>Done successfully \n");
	printf("===============================================\n");
	return LIFO_no_error;
}

// check LIFO is Full or not
LIFO_Status_t LIFO_is_full(LIFO_BUF_t* lifo_buf ){
	uint32 length = lifo_buf->length;
	if(lifo_buf->head == (lifo_buf->base + length * sizeof(data_type)) )
		return LIFO_full;
	return LIFO_not_full;

}

// check LIFO is Empty or not
LIFO_Status_t LIFO_is_empty(LIFO_BUF_t* lifo_buf ){

	if(lifo_buf->head == lifo_buf->base )
		return LIFO_empty;
	return LIFO_not_empty;

}

// push element to LIFO
LIFO_Status_t LIFO_push(LIFO_BUF_t* lifo_buf , data_type item){

	if( !lifo_buf->base || !lifo_buf->head ){
		printf("PUSH into LIFO ....->Failed not valid LIFO \n");
		printf("===============================================\n");
		return LIFO_null;
	}
	if((LIFO_is_full(lifo_buf)) == LIFO_full){
		printf("PUSH into LIFO ..........>>>Failed Full LIFO \n");
		printf("===============================================\n");
		return LIFO_full;
	}

	*(lifo_buf->head) = item;
	lifo_buf->head++;
	lifo_buf->count++;

	printf("PUSH into LIFO ..........>>>success \n");
	printf("===============================================\n");
	return LIFO_no_error;
}

// get the last entered element and delete it from LIFO
LIFO_Status_t LIFO_pop(LIFO_BUF_t* lifo_buf , data_type* item ){

	if( !lifo_buf->base || !lifo_buf->head ){
		printf("POP from LIFO ....->Failed not valid LIFO \n");
		printf("===============================================\n");
		return LIFO_null;
	}
	if((LIFO_is_empty(lifo_buf )) == LIFO_empty){
		printf("POP from LIFO ..........>>>Failed Empty LIFO \n");
		printf("===============================================\n");
		return LIFO_empty;
	}

	lifo_buf->head--;
	*item = *(lifo_buf->head) ;
	lifo_buf->count--;

	printf("POP from LIFO ..........>>>success \n");
	printf("===============================================\n");
	return LIFO_no_error;
}

// get the last element without deleting it
LIFO_Status_t LIFO_read(LIFO_BUF_t* lifo_buf , data_type* item){

	if( !lifo_buf->base || !lifo_buf->head ){
		printf("READ from LIFO ....->Failed not valid LIFO \n");
		printf("===============================================\n");
		return LIFO_null;
	}
	if((LIFO_is_empty(lifo_buf )) == LIFO_empty){
		printf("READ from LIFO ..........>>>Failed Empty LIFO \n");
		printf("===============================================\n");
		return LIFO_empty;
	}

	*item = *(lifo_buf->head - 1) ;

	printf("READ from LIFO ..........>>>success \n");
	printf("===============================================\n");
	return LIFO_no_error;
}

// delete the last element without getting it
LIFO_Status_t LIFO_delete(LIFO_BUF_t* lifo_buf){

	if( !lifo_buf->base || !lifo_buf->head ){
		printf("DELETE from LIFO ....->Failed not valid LIFO \n");
		printf("===============================================\n");
		return LIFO_null;
	}
	if((LIFO_is_empty(lifo_buf )) == LIFO_empty){
		printf("DELETE from LIFO ..........>>>Failed Empty LIFO \n");
		printf("===============================================\n");
		return LIFO_empty;
	}

	lifo_buf->head--;
	lifo_buf->count--;

	printf("DELETE from LIFO ..........>>>success \n");
	printf("===============================================\n");
	return LIFO_no_error;
}

// delete all elements
LIFO_Status_t LIFO_clear(LIFO_BUF_t* lifo_buf){

	if( !lifo_buf->base || !lifo_buf->head ){
		printf("CLEAR LIFO ....->Failed not valid LIFO \n");
		printf("===============================================\n");
		return LIFO_null;
	}
	if((LIFO_is_empty(lifo_buf)) == LIFO_empty){
		printf("CLEAR LIFO ..........>>>Failed Empty LIFO \n");
		printf("===============================================\n");
		return LIFO_empty;
	}

	lifo_buf->head = lifo_buf->base;
	lifo_buf->count = 0;

	printf("CLEAR LIFO ..........>>>success \n");
	printf("===============================================\n");
	return LIFO_no_error;
}

// print all elements
LIFO_Status_t LIFO_print(LIFO_BUF_t* lifo_buf){

	data_type* temp_ptr = lifo_buf->head;

	if( !lifo_buf->base || !lifo_buf->head ){
		printf("PRINT LIFO ....->Failed not valid LIFO \n");
		printf("===============================================\n");
		return LIFO_null;
	}
	if((LIFO_is_empty(lifo_buf)) == LIFO_empty){
		printf("PRINT LIFO ..........>>>Failed Empty LIFO \n");
		printf("===============================================\n");
		return LIFO_empty;
	}

	while((temp_ptr) > (lifo_buf->base)){
		temp_ptr--;
		printf(data_symbol ,*(temp_ptr));
	}
	printf("LIFO is printed successfully!!\n");
	printf("===============================================\n");
	return LIFO_no_error;
}

// fill LIFO randomly
LIFO_Status_t LIFO_rand_fill(LIFO_BUF_t* lifo_buf , uint32 max){

	uint32 i , length = lifo_buf->length;

	if( !lifo_buf->base || !lifo_buf->head ){
		printf("random fill LIFO ....->Failed not valid LIFO \n");
		printf("===============================================\n");
		return LIFO_null;
	}
	if((LIFO_is_full(lifo_buf)) == LIFO_full){
		printf("random fill LIFO ..........>>>Failed Full LIFO \n");
		printf("===============================================\n");
		return LIFO_full;
	}

	for( i = 0; i<length ; i++){

		*(lifo_buf->head) = rand()%(max+1);
		lifo_buf->head++;
	}
	printf("LIFO is filled randomly success!! \n");
	printf("===============================================\n");
	return LIFO_no_error;
}
// push all elements from start data to the end of LIFO incrementally
LIFO_Status_t LIFO_seq_inc_fill(LIFO_BUF_t* lifo_buf , uint32 start){


	uint32 i , length = lifo_buf->length;

	if( !lifo_buf->base || !lifo_buf->head ){
		printf("random fill LIFO ....->Failed not valid LIFO \n");
		printf("===============================================\n");
		return LIFO_null;
	}
	if((LIFO_is_full(lifo_buf)) == LIFO_full){
		printf("random fill LIFO ..........>>>Failed Full LIFO \n");
		printf("===============================================\n");
		return LIFO_full;
	}

	for( i = 0; i<length ; i++){

		*(lifo_buf->head) = start;
		lifo_buf->head++;
		start++;
	}
	printf("LIFO is filled with sequence success!! \n");
	printf("===============================================\n");
	return LIFO_no_error;

}
// push all elements from start data to the end of LIFO decrement
LIFO_Status_t LIFO_seq_dec_fill(LIFO_BUF_t* lifo_buf , uint32 start){


	uint32 i , length = lifo_buf->length;

	if( !lifo_buf->base || !lifo_buf->head ){
		printf("random fill LIFO ....->Failed not valid LIFO \n");
		printf("===============================================\n");
		return LIFO_null;
	}
	if((LIFO_is_full(lifo_buf)) == LIFO_full){
		printf("random fill LIFO ..........>>>Failed Full LIFO \n");
		printf("===============================================\n");
		return LIFO_full;
	}

	for( i = 0; i<length ; i++){

		*(lifo_buf->head) = start;
		lifo_buf->head++;
		start--;
	}
	printf("LIFO is filled with sequence success!! \n");
	printf("===============================================\n");
	return LIFO_no_error;

}

