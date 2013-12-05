#pragma systemFile

const int ENCODER_RESOLUTION=1440;
const int WHEEL_SIZE=4;	//Diameter of Wheel
const int RATIO=3/2;		//wheel/gear

bool distanceNotTraveled(int encoderTicks)
{
	return (abs(nMotorEncoder[RightBack])<abs(encoderTicks)||abs(nMotorEncoder[LeftBack])<abs(encoderTicks)&&abs(nMotorEncoder[RightFront])<abs(encoderTicks)||abs(nMotorEncoder[LeftFront])<abs(encoderTicks));
}

void rightSpeed(int power)
{
	motor[RightFront]=power;
	motor[RightBack]=power;
	return;
}
void leftSpeed(int power)
{
	motor[LeftFront]=power;
	motor[LeftBack]=power;
	return;
}
void initalizeEncoders()
{
	nMotorEncoder[RightFront]=0;
	nMotorEncoder[RightBack]=0;
	nMotorEncoder[LeftFront]=0;
	nMotorEncoder[LeftBack]=0;
	return;
}

#include "motion_library.h"
