#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


#include "app.h"
int PVal;

int main (){

	

	GPIO_INITIALIZATION();
	Pressure_sensor_init();


	while (1)
	{

		PVal = Pressure_sensor_reading();
		High_pressure_detection(PVal);

	}
	return 1;

}
