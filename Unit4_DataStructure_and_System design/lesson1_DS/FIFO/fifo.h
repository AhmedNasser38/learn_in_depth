/*
 * fifo.h
 *
 *  Created on: Sep 24, 2021
 *      Author: Ahmed Nasser
 */

#ifndef FIFO_H_
#define FIFO_H_


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
	data_type* tail;

}FIFO_BUF_t;

typedef enum {

	FIFO_no_error,
	FIFO_full,
	FIFO_not_full,
	FIFO_empty,
	FIFO_not_empty,
	FIFO_null

}FIFO_Status_t;

	// Initialization FIFO
FIFO_Status_t FIFO_init(FIFO_BUF_t* fifo_buf , data_type* buf , uint32 length);
	// push element to FIFO
FIFO_Status_t FIFO_push(FIFO_BUF_t* fifo_buf , data_type item);
	// get the last entered element and delete it from FIFO
FIFO_Status_t FIFO_pop(FIFO_BUF_t* fifo_buf , data_type* item );
	// get the last element without deleting it
FIFO_Status_t FIFO_read(FIFO_BUF_t* fifo_buf , data_type* item);
	// delete the last element without getting it
FIFO_Status_t FIFO_delete(FIFO_BUF_t* fifo_buf );
	// delete all elements
FIFO_Status_t FIFO_clear(FIFO_BUF_t* fifo_buf );
// fill FIFO randomly
FIFO_Status_t FIFO_rand_fill(FIFO_BUF_t* fifo_buf , uint32 max);
// fill elements
FIFO_Status_t FIFO_seq_inc_fill(FIFO_BUF_t* fifo_buf , uint32 start);
// fill elements
FIFO_Status_t FIFO_seq_dec_fill(FIFO_BUF_t* fifo_buf , uint32 start);

FIFO_Status_t FIFO_print(FIFO_BUF_t* fifo_buf);

	// check FIFO is Full or not
FIFO_Status_t FIFO_is_full(FIFO_BUF_t* fifo_buf );
	// check FIFO is Empty or not
FIFO_Status_t FIFO_is_empty(FIFO_BUF_t* fifo_buf );




#endif /* FIFO_H_ */
