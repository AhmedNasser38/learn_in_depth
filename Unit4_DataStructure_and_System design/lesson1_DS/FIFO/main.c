/*
 * main.c
 *
 *  Created on: Sep 24, 2021
 *      Author: Ahmed Nasser
 */

#include "fifo.h"


int main(void){
	uint32 buffer1 [5];
	uint32 buffer2 [5];
	uint32 buffer3 [5];
	uint32 buffer4 [5];
	uint32 buffer5 [5];
	uint32 x = 32 , y,z;

	FIFO_BUF_t test_fifo , test2_fifo , rand_fifo , increment_seq_fifo , decrement_seq_fifo;

	FIFO_init(&test_fifo , buffer1 , 5);

	FIFO_init(&test2_fifo , buffer5 , 5);

	FIFO_init(&rand_fifo  , buffer2 , 5);

	FIFO_init(&increment_seq_fifo  , buffer3 , 5);

	FIFO_init(&decrement_seq_fifo  , buffer4 , 5);



	// fill test_buf
	FIFO_push(&test_fifo , x);
	FIFO_push(&test_fifo , (uint32)62);
	FIFO_push(&test_fifo , (uint32)65);

	FIFO_pop(&test_fifo,&z);

	FIFO_read(&test_fifo , &y);

	// fill test2_buf
	FIFO_push(&test2_fifo , (uint32)30);
	FIFO_push(&test2_fifo , (uint32)31);
	FIFO_push(&test2_fifo , (uint32)32);
	FIFO_push(&test2_fifo , (uint32)33);


	// fill rand_buf
	FIFO_rand_fill( &rand_fifo , 100);
	// fill increment
	FIFO_seq_inc_fill( &increment_seq_fifo , 0);
	// fill decrement
	FIFO_seq_dec_fill( &decrement_seq_fifo , 4);


	// print

	printf("z(last entered data then deleted)=%d\n",z);
	printf("y(last entered data now after deleting z)=%d\n",y);
	printf("all test_fifo after popping z\n");
	FIFO_print(&test_fifo);

	FIFO_print(&test2_fifo);
	// clear it
	FIFO_clear(&test2_fifo );
	FIFO_print(&test2_fifo);

	FIFO_print(&rand_fifo);

	FIFO_print(&increment_seq_fifo);
	FIFO_delete(&increment_seq_fifo);
	FIFO_print(&increment_seq_fifo);

	FIFO_print(&decrement_seq_fifo);

	return 0;
}

