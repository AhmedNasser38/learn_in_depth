#include"stdio.h"
#include "platform.h"

// REG definition

#define RCC_BASE				  0x40021000
#define GPIOA_BASE	 			  0x40010800
#define RCC_APB2ENR     *((vuint32 *) (RCC_BASE + 0x18))
#define GPIOA_CRH	    *((vuint32 *) (GPIOA_BASE + 0x04))
#define GPIOA_ODR	    *((vuint32 *) (GPIOA_BASE + 0x0c))

#define RCC_IOPAEN (1<<2)  // pin2 in APB2ENR_reg in RCC (iopaen_bit)

typedef union {
	vuint32 PORTA;
	struct{
		vuint32  reserved:13;
		vuint32  A13:1;
	}pin;
}R_ODR_t;

volatile R_ODR_t*   R_ODR =  (volatile R_ODR_t*) (GPIOA_BASE + 0x0c);

int main(void)
{
	vuint32 i;
	RCC_APB2ENR |= RCC_IOPAEN;
	GPIOA_CRH &= 0xFE0FFFFF; // to clear bits from (20 to 24)
	GPIOA_CRH |= 0x00200000;  //(mode=2)bit(20 to 24)

	while(1){
		R_ODR->pin.A13 = 1;
		for(i=0;i<5000;i++);
		R_ODR->pin.A13 = 0;
		for(i=0;i<5000;i++);
	}

}