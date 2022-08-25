


#include "platform.h"


extern int main(void);

extern uint32 _stack_top ;

extern uint32 _S_data ;
extern uint32 _E_data ;
extern uint32 _S_bss  ;
extern uint32 _E_bss  ;
extern uint32 _E_text ;

void Reset_Handler();

void Default_Handler(){
	Reset_Handler();
}
/*so i can only over write to wanted interepted 
weak:mean can over writed & alias : replaced with other func*/
void NMI_Handler()__attribute__((weak,alias("Default_Handler")));;
void H_Fault_Handler()__attribute__((weak,alias("Default_Handler")));;
void MM_Fault_Handler()__attribute__((weak,alias("Default_Handler")));;
void Bus_Fault_Handler()__attribute__((weak,alias("Default_Handler")));;
void Usage_Fault_Handler()__attribute__((weak,alias("Default_Handler")));;
void SVCall_Handler()__attribute__((weak,alias("Default_Handler")));;
void Debug_MOnitor_Handler()__attribute__((weak,alias("Default_Handler")));;
void PendSV_Handler()__attribute__((weak,alias("Default_Handler")));;
void SYS_Tick_Handler()__attribute__((weak,alias("Default_Handler")));;
void WWDG_Handler()__attribute__((weak,alias("Default_Handler")));;
void PVD_Handler()__attribute__((weak,alias("Default_Handler")));;
void TAMPER_Handler()__attribute__((weak,alias("Default_Handler")));;
void RTC_Handler()__attribute__((weak,alias("Default_Handler")));;
void FLASH_Handler()__attribute__((weak,alias("Default_Handler")));;
void RCC_Handler()__attribute__((weak,alias("Default_Handler")));;
void EXTI0_Handler()__attribute__((weak,alias("Default_Handler")));;
void EXTI1_Handler()__attribute__((weak,alias("Default_Handler")));;
void EXTI2_Handler()__attribute__((weak,alias("Default_Handler")));;


/*idea is that make an arry with first element has 
the address i want to put in SP and then make all vectors
and finally but the array in first of flash (0x080000) by gives it a pargma to put 
in flash in linker it will put it in start of flash*/
uint32 vectors[] __attribute__((section(".vectors")))={

(uint32) &_stack_top,
(uint32) &Reset_Handler,
(uint32) &NMI_Handler,
(uint32) &H_Fault_Handler,
(uint32) &MM_Fault_Handler,
(uint32) &Bus_Fault_Handler,
(uint32) &Usage_Fault_Handler,
(uint32) &SVCall_Handler,
(uint32) &Debug_MOnitor_Handler,
(uint32) &PendSV_Handler,
(uint32) &SYS_Tick_Handler,
(uint32) &WWDG_Handler,
(uint32) &PVD_Handler,
(uint32) &TAMPER_Handler,
(uint32) &RTC_Handler,
(uint32) &FLASH_Handler,
(uint32) &RCC_Handler,
(uint32) &EXTI0_Handler,
(uint32) &EXTI1_Handler,
(uint32) &EXTI2_Handler

};



void Reset_Handler(void){
	uint32 i;
	//copy data section from flash to sram
	uint32 data_size = (uint8*)&_E_data - (uint8*)&_S_data ;
	uint8* p_src = (uint8*)&_E_text ;
	uint8* p_dst = (uint8*)&_S_data ;

	for(i = 0; i < data_size; i++){
		*((uint8*)p_dst++) = *((uint8*)p_src++);
	}
	// init bss section in sram with zeroes
	uint32 bss_size = (uint8*)&_E_bss - (uint8*)&_S_bss ;
	p_dst = (uint8*)&_S_bss ;
	for(i = 0; i < bss_size; i++){
		*((uint8*)p_dst++) = (uint8)0;
	}
	//jump to main
	main();
}