#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTMotor,  HTServo,  HTServo,  none)
#pragma config(Sensor, S3,     RightIRSensor,  sensorI2CCustomFastSkipStates)
#pragma config(Sensor, S4,     LeftIRSensor,   sensorI2CCustomFastSkipStates)
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
#pragma config(Servo,  srvo_S2_C3_2,    LeftIRServo,          tServoStandard)
#pragma config(Servo,  srvo_S2_C3_3,    RightIRServo,         tServoStandard)
#pragma config(Servo,  srvo_S2_C3_4,    servo10,              tServoNone)
#pragma config(Servo,  srvo_S2_C3_5,    servo11,              tServoNone)
#pragma config(Servo,  srvo_S2_C3_6,    servo12,              tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#if defined(_Target_Emulator_)
#include "fakeJoystickDriver.c"
#endif

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "3785_constants.h"
#include "3785_motion_functions.h"	//Motion fuctions such as forwards and backwards
#include "autoCubeDump.h"
#include "IRScanner.h"
#include "menu_helper.h"
#include "zone_config.h"
#include "InnerSubRoutines.h"
#include "OuterSubRoutines.h"

void setIntake(int speed)
{
	servo[Intake1]=speed;
	servo[Intake2]=FULL_FORWARD_SERVO-speed;
}

void initializeRobot()
{
	configZones();
	setIntake(STOP_SERVO);
	servo[Winch]=WINCH_UP;
	servo[FlagTwist]=FLAG_ARM_IN;
	servo[LeftIRServo]=128;
	servo[RightIRServo]=128;
	servo[AutoArm]=AUTO_LIFT_INIT;
	servo[AutoWrist]=AUTO_TWIST_INIT;
	return;
}

task main()
{
	initializeRobot();

	bDisplayDiagnostics = false;
	StartTask(runMenu);

	waitForStart(); // Wait for the beginning of autonomous phase.

	StopTask(runMenu);
	bDisplayDiagnostics = true;

	wait1Msec(delay*1000);

	int position = 0;
	ZoneBoundaries zones;
zones = right?rZones:lZones;
position = scanIR(right?RightIRSensor:LeftIRSensor,right?RightIRServo:RightIRSensor, zones);

	switch(position){
	case 0:
		if(right){
			if(inner && !closeGoal) {
				rightInnerCrate1();
				} else if (!closeGoal) {
				rightOuterCrate1();
				} else if (inner && closeGoal) {
				rightOuterCrate4();
				} else {
				rightOuterCrate4();
			}
			} else {
			if(inner && !closeGoal){
				leftInnerCrate4();
				} else if (!closeGoal) {
				leftOuterCrate4();
				} else if (inner && closeGoal) {
				leftOuterCrate1();
				} else {
				leftOuterCrate1();
			}
		}
		break;
	case 1:
		if(right){
			if(inner && !closeGoal) {
				rightInnerCrate1();
				} else if (!closeGoal) {
				rightOuterCrate1();
				} else if (inner && closeGoal) {
				rightOuterCrate4();
				} else {
				rightOuterCrate4();
			}
			} else {
			if(inner){
				leftInnerCrate1();
				} else {
				leftOuterCrate1();
			}
		}
		break;
	case 2:
		if(right){
			if(inner && !closeGoal) {
				rightInnerCrate2();
				} else if (!closeGoal) {
				rightOuterCrate2();
				} else if (inner && closeGoal) {
				rightOuterCrate4();
				} else {
				rightOuterCrate4();
			}
			} else {
			if(inner){
				leftInnerCrate2();
				} else {
				leftOuterCrate2();
			}
		}
	case 3:
		if(right){
			if(inner) {
				rightInnerCrate3();
				} else {
				rightOuterCrate3();
			}
			} else {
			if(inner && !closeGoal){
				leftInnerCrate3();
				} else if (!closeGoal) {
				leftOuterCrate3();
				} else if (inner && closeGoal) {
				leftOuterCrate1();
				} else {
				leftOuterCrate1();
			}
		}
		break;
	case 4:
		if(right){
			if(inner) {
				rightInnerCrate4();
				} else {
				rightOuterCrate4();
			}
			} else {
			if(inner && !closeGoal){
				leftInnerCrate4();
				} else if (!closeGoal) {
				leftOuterCrate4();
				} else if (inner && closeGoal) {
				leftOuterCrate1();
				} else {
				leftOuterCrate1();
			}
		}
		break;
	}
}
