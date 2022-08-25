#include "Pressure_sensor.h"
#include "driver.h"
void Pressure_sensor_init(){

	return;
}
int Pressure_sensor_reading(){
	int read = Get_Pressure_Val();
	return read ;
	
}
