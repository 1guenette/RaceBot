#include "open_interface.h"
////PART 2

void movement(oi_t *sensor_data, int meters)
{


	int sum = 0;
	if(meters<0)
	{
		oi_setWheels(-500, -500); // move backward; full speed
		while (sum > (meters))
		{
		     oi_update(sensor_data);
			    sum += sensor_data->distance;
		 }
		oi_setWheels(0, 0); // stop

	}
	else
	{
		oi_setWheels(500, 500); // move forward; full speed
		while (sum < meters)
			 {
			     oi_update(sensor_data);
			     sum += sensor_data->distance;
			 }
		oi_setWheels(0, 0); // stop

	}
}


//

//NOTE sensor_data->angle

void turn(oi_t *sensor_data, int degrees)
{
	int sum = 0;
	if(degrees >0) //Counbter-Clockwise(Left)
	{
		oi_update(sensor_data);
		oi_setWheels(150, -150); // move backward; full speed

		while (sum < (degrees))
				{
				     oi_update(sensor_data);
					    sum += sensor_data->angle;
				 }
				oi_setWheels(0, 0); // stop



	}
	if(degrees<0) //Clockwise(Right)
	{
		oi_update(sensor_data);
		oi_setWheels(-150, 150); // move backward; full speed
				while (sum > (degrees))
				{
				     oi_update(sensor_data);
					    sum += sensor_data->angle;
				 }
				oi_setWheels(0, 0); // stop


	}
}




////
//////PART 3
////
void race(oi_t *sensor_data)
{
	int distance= 2000;
	oi_setWheels(500 , 500); // move forward; full speed

	int sum = 0;
	while (sum < distance)
	 {
	     oi_update(sensor_data);
     sum += sensor_data->distance;
	     if (sensor_data->bumpLeft || sensor_data->bumpRight)
	     {

	    	 oi_setWheels(0, 0);
	    	 movement(sensor_data,-150);
	    	 sum -= 150;

	    	 turn(sensor_data,-90);
	    	 movement(sensor_data,250);
	    	 sum-=250;
	    	 turn(sensor_data,90);
	         // Respond to left bumper being pressed
	    	 oi_setWheels(500 , 500); // move forward; full speed
	     }

	 }
	  oi_setWheels(0, 0); // stop
	  oi_free(sensor_data);


}

