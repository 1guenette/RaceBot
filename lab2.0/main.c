/*
 * main.c
 */
#include "open_interface.h"
#include "movement.h"
int main(void) {

//PART 1
	//	//Initialization
	oi_t *sensor_data = oi_alloc();
	oi_init(sensor_data); // should turn the iRobot Create's "Dirt Detect" LED to blue

//	    oi_setWheels(500, 500); // move self->angleforward; full speed
//	    while (sum < 1000) {
//	        oi_update(sensor_data);
//	        sum += sensor_data->distance;
//	    }
//	    oi_setWheels(0, 0); // stop
//	    lcd_printf("%d", sum);
//	    oi_free(sensor_data);


	//part 2
//	movement(sensor_data, 500);
//	  turn(sensor_data, 90);
//	  movement(sensor_data, 500);
//	  	  turn(sensor_data, 90);
//	  	movement(sensor_data, 500);
//	  		  turn(sensor_data, 90);
//	  		movement(sensor_data, 500);

	race(sensor_data);




	oi_free(sensor_data);






}
