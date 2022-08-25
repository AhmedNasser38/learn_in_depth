/*
 * main.c
 *
 *  Created on: Sep 23, 2021
 *      Author: Ahmed Nasser
 */

#include "lifo.h"


int main(void){
	uint32 buffer1 [5];
	uint32 buffer2 [5];
	uint32 buffer3 [5];
	uint32 buffer4 [5];
	uint32 buffer5 [5];
	uint32 x = 32 , y,z;

	LIFO_BUF_t test_lifo , test2_lifo , rand_lifo , increment_seq_lifo , decrement_seq_lifo;

	LIFO_init(&test_lifo , buffer1 , 5);

	LIFO_init(&test2_lifo , buffer5 , 5);

	LIFO_init(&rand_lifo  , buffer2 , 5);

	LIFO_init(&increment_seq_lifo  , buffer3 , 5);

	LIFO_init(&decrement_seq_lifo  , buffer4 , 5);



	// fill test_buf
	LIFO_push(&test_lifo , x);
	LIFO_push(&test_lifo , (uint32)62);
	LIFO_push(&test_lifo , (uint32)65);

	LIFO_pop(&test_lifo,&z);

	LIFO_read(&test_lifo , &y);

	// fill test2_buf
	LIFO_push(&test2_lifo , (uint32)30);
	LIFO_push(&test2_lifo , (uint32)31);
	LIFO_push(&test2_lifo , (uint32)32);
	LIFO_push(&test2_lifo , (uint32)33);

	// clear it
	LIFO_clear(&test2_lifo );
	// fill rand_buf
	LIFO_rand_fill( &rand_lifo , 100);
	// fill increment
	LIFO_seq_inc_fill( &increment_seq_lifo , 0);
	// fill decrement
	LIFO_seq_dec_fill( &decrement_seq_lifo , 4);


	// print

	printf("z(last entered data then deleted)=%d\n",z);
	printf("y(last entered data now after deleting z)=%d\n",y);
	printf("all test_lifo after popping z(65)\n");
	LIFO_print(&test_lifo);

	LIFO_print(&test2_lifo);

	LIFO_print(&rand_lifo);

	LIFO_print(&increment_seq_lifo);
	LIFO_delete(&increment_seq_lifo);
	LIFO_print(&increment_seq_lifo);

	LIFO_print(&decrement_seq_lifo);

	return 0;
}
