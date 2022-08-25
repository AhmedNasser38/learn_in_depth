


#include "platform.h"


extern int main(void);



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
// make a stack as apart of bss (256 elem => 4*256=1024byte)
static uint32 stack_top[256];

void (* const g_p_fn_vectors[])() __attribute__((section(".vectors")))=
{
	(void (*)()) ((uint32)stack_top+sizeof(stack_top)),
	(void (*)()) &Reset_Handler,
	(void (*)()) &NMI_Handler,
	(void (*)()) &H_Fault_Handler,
	(void (*)()) &MM_Fault_Handler,
	(void (*)()) &Bus_Fault_Handler,
	(void (*)()) &Usage_Fault_Handler,
	(void (*)()) &SVCall_Handler,
	(void (*)()) &Debug_MOnitor_Handler,
	(void (*)()) &PendSV_Handler,
	(void (*)()) &SYS_Tick_Handler,
	(void (*)()) &WWDG_Handler,
	(void (*)()) &PVD_Handler,
	(void (*)()) &TAMPER_Handler,
	(void (*)()) &RTC_Handler,
	(void (*)()) &FLASH_Handler,
	(void (*)()) &RCC_Handler,
	(void (*)()) &EXTI0_Handler,
	(void (*)()) &EXTI1_Handler,
	(void (*)()) &EXTI2_Handler
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