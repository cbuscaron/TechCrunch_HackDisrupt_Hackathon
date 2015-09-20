/* ---- System headers ------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <common/i2c-dev.h>
#include "common/header.h"
#include "sensor_iface.h"
#include "PAJ7620.h"
#include "tcs3414cs.h"
#include "Digital_Light_TSL2561.h"

Paj7620 gesture_sensor( I2C0 );

int init_gesture()
{
	return gesture_sensor.initSensor();
}

int read_gesture()
{
	int value = gesture_sensor.readSensor();
	return value;

}

Tcs3414cs color_sensor( I2C0 );

int init_rgb()
{
	return color_sensor.initSensor();

}


int read_rgb(int *r, int *g, int *b)
{
	if (color_sensor.readSensor() == 0 ) {
		//color_sensor.calculateCoordinate();
		*r = color_sensor.red;
		*g = color_sensor.green;
		*b = color_sensor.blue;
		return 0;
	} else {
		return -1;
	}
}

TSL2561_CalculateLux light;

int init_light()
{
	return light.init();
}

long read_lux()
{
	light.readVisibleLux();
}
