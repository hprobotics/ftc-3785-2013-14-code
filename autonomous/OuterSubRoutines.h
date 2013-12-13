void dropCube();
void lowerCube();
void primeCube();

void dropAtPos(int distance)//The position in which to drop the cube
{
	straight(-75,distance);//drive backwards at 75% power
	primeCube();
	dropCube();
	lowerCube();
	straight(75,distance);//drive forwards at 75% power the same distance it went backwards.
	turnRight(-75,1750);//turn right 90 degrees
	straight(75,46);//go straight
	turnRight(-75,1300);//turn on the ramp
	straight(75,52);//go onto the ramp
}
void crate1()
{
	writeDebugStreamLine("Crate 1");
	dropAtPos(12);//the position used for the first crate
}

void crate2()
{
	writeDebugStreamLine("Crate 2");
  dropAtPos(24);//the position used for the second crate
}

void crate3()
{
	writeDebugStreamLine("Crate 3");
	dropAtPos(58);//the position used for the third crate
}

void crate4()
{
	writeDebugStreamLine("Crate 4");
	dropAtPos(67); //the position used for the fourth crate
}

const int AUTO_LIFT_INIT=120;
const int AUTO_TWIST_INIT=0;
const int AUTO_LIFT_DROP=230;
const int AUTO_TWIST_DROP=255;

void primeCube()//how we raise the arm.
{
	servoChangeRate[AutoWrist]=2;
	servo[AutoArm]=AUTO_LIFT_DROP;
	wait10Msec(100);
}

void dropCube()//how we drop the cube
{

	servo[AutoWrist]=AUTO_TWIST_DROP;
	wait10Msec(200);
}
void lowerCube()//how we lower the arm.
{
		servo[AutoWrist]=AUTO_TWIST_INIT;
		servo[AutoArm]=AUTO_LIFT_INIT;
		wait10Msec(30);
}
