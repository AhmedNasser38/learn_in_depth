/*  startup_cortexM3
	Eng:AhmedNasser
*/

.section .vectors

/*give the cpu the start of the stack when SRAM 0x20001000 @0x08000000*/
.word 0x20001000
/*reset handler @ 0x08000004*/
.word _reset
/*NMI handler @ 0x08000008*/
.word vector_handler     //_NMI_Handler
# remin inturrputs
.word vector_handler     //_H_Fault_Handler
.word vector_handler     //_MM_Fault_Handler
.word vector_handler     //_Bus_Fault_Handler
.word vector_handler     //_Usage_Fault_Handler
.word vector_handler     //_SVCall_Handler
.word vector_handler     //_Debug_MOnitor_Handler
.word vector_handler     //_PendSV_Handler
.word vector_handler     //_SYS_Tick_Handler
.word vector_handler     //_WWDG_Handler
.word vector_handler     //_PVD_Handler
.word vector_handler     //_TAMPER_Handler
.word vector_handler     //_RTC_Handler
.word vector_handler     //_FLASH_Handler
.word vector_handler     //_RCC_Handler
.word vector_handler     //_EXTI0_Handler
.word vector_handler     //_EXTI1_Handler
.word vector_handler     //_EXTI2_Handler

.section .text

_reset:
	bl main
	b .
.thumb_func
vector_handler:
	b _reset