/*
 * main.c
 *
 *  Created on: Jul 31, 2021
 *      Author: Ahmed Nasser
 */

/*
 * main.c
 *
 *  Created on: Jul 31, 2021
 *      Author: Ahmed Nasser
 */


#include "stdio.h"
int clear_bit(int n , int bit);
int set_bit(int n , int bit);
int main(){
	int n,bit,new_n,old_n;

	printf("enter number = ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&n);

	printf("enter bit position  : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&bit);

	new_n = clear_bit(n,bit);
	old_n = set_bit(new_n,bit);

	printf("number before clear : %d",n);
	printf("\nnumber after clear : %d",new_n);
	printf("\nnumber after set again : %d",old_n);

	return 0;
}

int clear_bit(int n,int bit){
	return n & ( ~(1 << bit ) );
}
int set_bit(int n,int bit){
	return n | (1<<bit);
}

