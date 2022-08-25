
#include "app.h"

void High_pressure_detection(int PVal){
	int i;
	if(PVal > 20){
		Alarm_start();
		Delay(100);
		Alarm_stop();
	}else{
		Alarm_stop();
		Delay(100);

	}
	return;
}