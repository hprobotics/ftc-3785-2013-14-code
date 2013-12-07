#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTMotor,  HTServo,  HTServo,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     MUX,            sensorI2CCustomFastSkipStates)
#pragma config(Sensor, S4,     ProtoBoard,     sensorI2CCustomFastSkipStates9V)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, reversed, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop, reversed, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     RightBack,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     LeftBack,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     Arm1,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Arm2,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     CubeLift,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     Flag,          tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S2_C1_1,     RightFront,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C1_2,     LeftFront,     tmotorTetrix, openLoop)
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

#include "JoystickDriver.c"

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

int sign(int num)
{
	if(num<0)
	{
		return  -1;
		} else	{
		return 1;
	}
}

#define leftjoy joystick.joy1_y1*joystick.joy1_y1*100.0/(128.0*128.0)*sign(joystick.joy1_y1)
#define rightjoy joystick.joy1_y2*joystick.joy1_y2*100.0/(128.0*128.0)*sign(joystick.joy1_y2)

typedef struct
{
	bool pressed;
	bool run;
} servobuttons;

typedef enum
{
	btn_X=1,
	btn_A=2,
	btn_B=3,
	btn_Y=4,
	btn_LB=5,
	btn_RB=6,
	btn_LT=7,
	btn_RT=8,
	btn_BACK=9,
	btn_START=10
} joybtn;

bool slow=false;


void setArm(int speed)
{
	motor[Arm1]=speed;
	motor[Arm2]=speed;
}

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
	servo[AutoArm]=128;
	servo[AutoWrist]=128;
	return;
}

bool flipped=false;

//raise the flag asynchronously
task raiseFlag()
{
	servo[FlagTwist]=FLAG_ARM_OUT;
	int halt = 0;
	int encOld = 0;
	int encNow = 0;
	nMotorEncoder[Flag]=0;
	motor[Flag]=FULL_POWER_FORWARD;
	wait10Msec(20);
	while(halt<10)
	{
		motor[Flag]=FULL_POWER_FORWARD;
		wait10Msec(10);
		encOld=encNow;
		encNow=nMotorEncoder[Flag];
		writeDebugStreamLine("%i",abs(encNow-encOld));
		if(abs(encNow-encOld)<LIFTER_ENCODER_THRESHOLD) //if the flag is spinning freely, it should go faster than LIFTER_ENCODER_THRESHOLD; otherwise, the flag is at the top
		{
			halt++;
		}
	}
	motor[Flag]=FULL_POWER_REVERSE;
	wait10Msec(15);
	motor[Flag]=NO_POWER;
	servo[FlagTwist]=FLAG_ARM_IN;
}


task main()
{
	servobuttons intake;
	servobuttons flagTurn;
	servobuttons flagLift;
	initializeRobot();
	waitForStart();   // wait for start of tele-op phase
	intake.run=true;
	float mult;
	while (true)
	{

		getJoystickSettings(joystick);

		if(sign(leftjoy)!=sign(rightjoy)){
			mult = .5;
			} else {
			mult = 1;
		}

		if(!slow)
		{
			if (abs(leftjoy)>JOY_THRESHOLD)
			{
				motor[LeftFront]=leftjoy*mult;
				motor[LeftBack]=leftjoy*mult;
			}
			else
			{
				motor[LeftFront]=NO_POWER;
				motor[LeftBack]=NO_POWER;
			}
			if (abs(rightjoy)>JOY_THRESHOLD)
			{
				motor[RightFront]=rightjoy*mult;
				motor[RightBack]=rightjoy*mult;
			}
			else
			{
				motor[RightFront]=NO_POWER;
				motor[RightBack]=NO_POWER;
			}
		}
		//slow
		else
		{
			if (abs(leftjoy)>JOY_THRESHOLD)
			{
				motor[RightFront]=-leftjoy;
				motor[RightBack]=-leftjoy;
			}
			else
			{
				motor[RightFront]=NO_POWER;
				motor[RightBack]=NO_POWER;
			}
			if (abs(rightjoy)>JOY_THRESHOLD)
			{
				motor[LeftFront]=-rightjoy;
				motor[LeftBack]=-rightjoy;
			}
			else
			{
				motor[LeftFront]=NO_POWER;
				motor[LeftBack]=NO_POWER;
			}
		}

		if (joy2Btn(2))
		{
			motor[CubeLift]=FULL_POWER_FORWARD;
			}	else if(joy2Btn(4))	{
			motor[CubeLift]=FULL_POWER_REVERSE;
			} else {
			motor[CubeLift]=NO_POWER;
		}

		if((joy2Btn(1))&&!intake.pressed)
		{
			intake.pressed=true;
			intake.run=!intake.run;
		}
		if(!(joy2Btn(1)))
		{
			intake.pressed=false;
		}


		if (!intake.run)
		{
			setIntake(STOP_SERVO);
		}
		else if (intake.run)
		{
			if(joy2Btn(3))
			{
				setIntake(FULL_REVERSE_SERVO);
				} else {
				setIntake(FULL_FORWARD_SERVO);
			}
		}
		//open the flag raiser and spin it slowly for alignment
		if((joy2Btn(btn_LB))&&!flagLift.pressed)
		{
			flagLift.pressed=true;
			if(servo[FlagTwist]!=FLAG_ARM_OUT)
			{
				flagLift.run=!flagLift.run;
			}
			servo[FlagTwist]=FLAG_ARM_OUT;
			motor[Flag]=SLOW_PRIME_POWER;
		}
		//else if((joy2Btn(btn_START) && (servo[FlagTwist] == FLAG_ARM_OUT)))
		//{
		//	motor[Flag]=-SLOW_PRIME_POWER;
		//}
		//else if(!(joy2Btn(btn_START)) && (flagLift.pressed))
		//{
		//	motor[Flag]=NO_POWER;
		//	flagLift.pressed = false;
		//}
		//stop spinning the flag raiser for alignment
		else if(!(joy2Btn(btn_LB))&&flagLift.pressed)
		{
			motor[Flag]=NO_POWER;
			flagLift.pressed=false;
		}
		//control raising the flag

		if((joy2Btn(btn_LT))&&!flagTurn.pressed)
		{
			flagTurn.pressed=true;
			flagTurn.run=!flagTurn.run;
			if(flagTurn.run)
			{
				if(servo[FlagTwist]==FLAG_ARM_OUT)
				{
					StartTask(raiseFlag);
				}
				} else {
				StopTask(raiseFlag);
				if(servo[FlagTwist]==FLAG_ARM_OUT)
				{
					motor[Flag]=FULL_POWER_REVERSE;
				}
				wait10Msec(15);
				motor[Flag]=NO_POWER;
			}
		}
		else if(!(joy2Btn(btn_LT))&&flagTurn.pressed)
		{
			flagTurn.pressed=false;
		}

		if(joy2Btn(btn_BACK))
		{
			servo[FlagTwist]=FLAG_ARM_IN;
			StopTask(raiseFlag);
			motor[Flag]=NO_POWER;
		}

		if(joy1Btn(btn_RB)){
			setArm(FULL_POWER_FORWARD);
			} else if (joy1Btn(btn_RT)) {
			setArm(FULL_POWER_REVERSE);
			} else if(joy2Btn(btn_RB)){
			setArm(FULL_POWER_FORWARD);
			} else if (joy2Btn(btn_RT)) {
			setArm(FULL_POWER_REVERSE);
			} else {
			setArm(NO_POWER);
		}

		if(joystick.joy2_TopHat==0)
		{
			servo[Winch]=WINCH_UP;
		} else if (joystick.joy2_TopHat==4) {
			servo[Winch]=WINCH_DOWN;
		}
	}
}