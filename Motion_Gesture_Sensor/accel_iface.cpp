/* ---- System headers ------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <common/i2c-dev.h>
#include "accel_iface.h"
#include "common/header.h"


/* ---- Local headers ------------------------------------------------------- */

#include "ADXL345.h"

#define LED1    "/sys/class/leds/led1/brightness"
#define LED2    "/sys/class/leds/led2/brightness"
#define LED3    "/sys/class/leds/led3/brightness"
#define BOOT    "/sys/class/leds/boot/brightness"

#define I2C0    "/dev/i2c-0"

void adxl_init( void );

ADXL345 adxl;

int init_adxl345()
{
	return adxl.init( I2C0 );
}

int read_adxl345(int *px, int *py, int *pz)
{


	int x = 20, y = 40, z = 60;
	double xyz[3] = {0};
	double ax = 0, ay = 0, az = 0;

	printf( "Hello World!\n\r" );
	printf( "Vikram 1 !\n\r" );

	int led1_fd = open( LED1, O_WRONLY);
	int led2_fd = open( LED2, O_WRONLY);
	int led3_fd = open( LED3, O_WRONLY);
	int boot_fd = open( BOOT, O_WRONLY);

	printf( "Vikram 2 !\n\r" );

	adxl_init();

		write( led1_fd, "1", 2 );
		write( led2_fd, "0", 2 );
		write( led3_fd, "1", 2 );
		write( boot_fd, "0", 2 );

		usleep( 100 * 1000 );

		write( led1_fd, "0", 2 );
		write( led2_fd, "1", 2 );
		write( led3_fd, "0", 2 );
		write( boot_fd, "1", 2 );

		usleep( 200 * 1000 );

		printf( "Vikram loop !\n\r" );


		//Boring accelerometer stuff
		adxl.readXYZ(&x, &y, &z); //read the accelerometer values and store them in variables  x,y,z
		// Output x,y,z values
		LOGD("ACCL", "Raw values of X = %d, Y = %d, Z = %d", x, y, z);


		adxl.getAcceleration(xyz);

		ax = xyz[0];
		ay = xyz[1];
		az = xyz[2];

    	LOGD("ACCL", "Acceleration of X = %lg, Y = %lg, Z = %lg", ax, ay, az );



		*px=x;
		*py=y;
		*pz=z;

}


void adxl_init( void )
{

	printf( "Vikram adxl_init !\n\r" );

	adxl.powerOn();

	//set activity/ inactivity thresholds (0-255)
	adxl.setActivityThreshold(75); //62.5mg per increment
	adxl.setInactivityThreshold(75); //62.5mg per increment
	adxl.setTimeInactivity(10); // how many seconds of no activity is inactive?

	//look of activity movement on this axes - 1 == on; 0 == off
	adxl.setActivityX(1);
	adxl.setActivityY(1);
	adxl.setActivityZ(1);

	//look of inactivity movement on this axes - 1 == on; 0 == off
	adxl.setInactivityX(1);
	adxl.setInactivityY(1);
	adxl.setInactivityZ(1);

	//look of tap movement on this axes - 1 == on; 0 == off
	adxl.setTapDetectionOnX(0);
	adxl.setTapDetectionOnY(0);
	adxl.setTapDetectionOnZ(1);

	//set values for what is a tap, and what is a double tap (0-255)
	adxl.setTapThreshold(50); //62.5mg per increment
	adxl.setTapDuration(15); //625us per increment
	adxl.setDoubleTapLatency(80); //1.25ms per increment
	adxl.setDoubleTapWindow(200); //1.25ms per increment

	//set values for what is considered freefall (0-255)
	adxl.setFreeFallThreshold(7); //(5 - 9) recommended - 62.5mg per increment
	adxl.setFreeFallDuration(45); //(20 - 70) recommended - 5ms per increment

	//setting all interrupts to take place on int pin 1
	//I had issues with int pin 2, was unable to reset it
	adxl.setInterruptMapping( ADXL345_INT_SINGLE_TAP_BIT,   ADXL345_INT1_PIN );
	adxl.setInterruptMapping( ADXL345_INT_DOUBLE_TAP_BIT,   ADXL345_INT1_PIN );
	adxl.setInterruptMapping( ADXL345_INT_FREE_FALL_BIT,    ADXL345_INT1_PIN );
	adxl.setInterruptMapping( ADXL345_INT_ACTIVITY_BIT,     ADXL345_INT1_PIN );
	adxl.setInterruptMapping( ADXL345_INT_INACTIVITY_BIT,   ADXL345_INT1_PIN );

	//register interrupt actions - 1 == on; 0 == off
	adxl.setInterrupt( ADXL345_INT_SINGLE_TAP_BIT, 1);
	adxl.setInterrupt( ADXL345_INT_DOUBLE_TAP_BIT, 1);
	adxl.setInterrupt( ADXL345_INT_FREE_FALL_BIT,  1);
	adxl.setInterrupt( ADXL345_INT_ACTIVITY_BIT,   1);
	adxl.setInterrupt( ADXL345_INT_INACTIVITY_BIT, 1);
}
