


#include <stdio.h>
#include "platform.h"
// #define vuint32 volatile unsigned long 
// Regesiters
#define SYSCTL_BASE      0x400FE000
#define GPIO_PORTF_BASE  0x40025000

#define SYSCTL_RCGC2_R     *((vuint32 *)(SYSCTL_BASE + 0x108)) // enable whole port

#define GPIO_PORTF_DIR_R   *((vuint32 *)(GPIO_PORTF_BASE + 0x400)) // direction reg output or input
#define GPIO_PORTF_DEN_R   *((vuint32 *)(GPIO_PORTF_BASE + 0x51C)) // Enable reg  for pins
#define GPIO_PORTF_DATA_R  *((vuint32 *)(GPIO_PORTF_BASE + 0x3FC)) // data reg 

/* first en portF then en pin then give it the the diection and finally put the value
*/
int main(){
	vuint64 i;
	SYSCTL_RCGC2_R = 0x20;
	for(i=0; i < 300; i++);
	GPIO_PORTF_DIR_R |= 1<<3;
	GPIO_PORTF_DEN_R |= 1<<3;
	
	
	while(1){
		GPIO_PORTF_DATA_R |= (1<<3);
		for(i=0 ; i < 300000 ; i++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(i = 0 ; i < 300000 ; i++);
	}
	return 0;
}