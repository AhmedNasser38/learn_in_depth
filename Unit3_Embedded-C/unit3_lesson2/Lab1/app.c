#include "uart.h"

unsigned char string[]="learn-in-depth : Ahmed Nasser ";
unsigned char const string2[]="Test rodata section ";
char x;// to see bss section

void main(void){
	uart_send_string(string);
}