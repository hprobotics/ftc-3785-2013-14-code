#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTMotor,  HTServo,  HTServo,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     MUX,            sensorI2CCustomFastSkipStates)
#pragma config(Sensor, S4,     IRSensor,       sensorI2CCustomFastSkipStates9V)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, reversed, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop, reversed, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     RightBack,     tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     LeftBack,      tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     Arm1,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Arm2,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     CubeLift,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     Flag,          tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S2_C1_1,     RightFront,    tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S2_C1_2,     LeftFront,     tmotorTetrix, PIDControl, encoder)
#pragma config(Servo,  srvo_S2_C2_1,    Intake1,              tServoContinuousRotation)
#pragma config(Servo,  srvo_S2_C2_2,    Intake2,              tServoContinuousRotation)
#pragma config(Servo,  srvo_S2_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C2_4,    AutoArm,              tServoStandard)
#pragma config(Servo,  srvo_S2_C2_5,    AutoWrist,            tServoStandard)
#pragma config(Servo,  srvo_S2_C2_6,    FlagTwist,            tServoStandard)
#pragma config(Servo,  srvo_S2_C3_1,    Winch,                tServoStandard)
#pragma config(Servo,  srvo_S2_C3_2,    IRServo,              tServoStandard)
#pragma config(Servo,  srvo_S2_C3_3,    servo9,               tServoNone)
#pragma config(Servo,  srvo_S2_C3_4,    servo10,              tServoNone)
#pragma config(Servo,  srvo_S2_C3_5,    servo11,              tServoNone)
#pragma config(Servo,  srvo_S2_C3_6,    servo12,              tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "3785_motion_functions.h"	//Motion fuctions such as forwards and backwards
#include "IRScanner.h"
#include "InnerSubRoutines.h"

const int FLAG_ARM_OUT = 85;
const int FLAG_ARM_IN = 195;
const int FULL_POWER_FORWARD = 100;
const int HALF_POWER_FORWARD = 50;
const int NO_POWER = 0;
const int HALF_POWER_REVERSE = -50;
const int FULL_POWER_REVERSE = -100;
const int FULL_FORWARD_SERVO = 255;
const int FULL_REVERSE_SERVO = 0;
const int STOP_SERVO=128;
const int SLOW_PRIME_POWER = 10;
const int LIFTER_ENCODER_THRESHOLD = 100;
const int JOY_THRESHOLD = 10;
const int WINCH_UP=134;
const int WINCH_DOWN=217;

void setIntake(int speed)
{
	servo[Intake1]=speed;
	servo[Intake2]=FULL_FORWARD_SERVO-speed;
}

void initializeRobot()
{
	setIntake(STOP_SERVO);
	servo[Winch]=WINCH_UP;
	servo[FlagTwist]=FLAG_ARM_IN;
	servo[IRServo]=255;
	servo[AutoArm]=AUTO_LIFT_INIT;
	servo[AutoWrist]=AUTO_TWIST_INIT;
  return;
}

ZoneBoundaries zones;

task main()
{
  initializeRobot();

  waitForStart(); // Wait for the beginning of autonomous phase.

  writeDebugStreamLine("Crate 1");
	straight(-75,53); //go forward
	pause();
	turnRight(50,2200); //turn to face bridge
	primeCube();
	pause();
	straight(-75,34); //go and align next to cube
	pause();

	dropCube();
	lowerCube();
	pause();



}
