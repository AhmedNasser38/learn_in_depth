/*
 * lifo.h
 *
 *  Created on: Sep 23, 2021
 *      Author: Ahmed Nasser
 */

#ifndef LIFO_H_
#define LIFO_H_


#include "platform.h"
#include "stdio.h"
#include "stdlib.h"

//Configuration
	//set data type
		//char
#define data_type  uint32
		//uint32 ->> %i
#define data_symbol  "%i \n"
// end configuration

typedef struct {

	uint32 length;
	uint32 count ;
	data_type* base;
	data_type* head;

}LIFO_BUF_t;

typedef enum {

	LIFO_no_error,
	LIFO_full,
	LIFO_not_full,
	LIFO_empty,
	LIFO_not_empty,
	LIFO_null

}LIFO_Status_t;

	// Initialization LIFO
LIFO_Status_t LIFO_init(LIFO_BUF_t* lifo_buf , data_type* buf , uint32 length);
	// push element to LIFO
LIFO_Status_t LIFO_push(LIFO_BUF_t* lifo_buf , data_type item);
	// get the last entered element and delete it from LIFO
LIFO_Status_t LIFO_pop(LIFO_BUF_t* lifo_buf , data_type* item );
	// get the last element without deleting it
LIFO_Status_t LIFO_read(LIFO_BUF_t* lifo_buf , data_type* item);
	// delete the last element without getting it
LIFO_Status_t LIFO_delete(LIFO_BUF_t* lifo_buf );
	// delete all elements
LIFO_Status_t LIFO_clear(LIFO_BUF_t* lifo_buf );
// fill LIFO randomly
LIFO_Status_t LIFO_rand_fill(LIFO_BUF_t* lifo_buf , uint32 max);
// fill elements
LIFO_Status_t LIFO_seq_inc_fill(LIFO_BUF_t* lifo_buf , uint32 start);
// fill elements
LIFO_Status_t LIFO_seq_dec_fill(LIFO_BUF_t* lifo_buf , uint32 start);

LIFO_Status_t LIFO_print(LIFO_BUF_t* lifo_buf);

	// check LIFO is Full or not
LIFO_Status_t LIFO_is_full(LIFO_BUF_t* lifo_buf );
	// check LIFO is Empty or not
LIFO_Status_t LIFO_is_empty(LIFO_BUF_t* lifo_buf );



#endif /* LIFO_H_ */
