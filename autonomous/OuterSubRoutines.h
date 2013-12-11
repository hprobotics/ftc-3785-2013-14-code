void dropCube();
void lowerCube();
void primeCube();

void dropAtPos(int distance)
{
	straight(-75,distance);
	primeCube();
	dropCube();
	lowerCube();
	straight(75,distance);
	turnRight(-75,1750);
	straight(75,46);
	turnRight(-75,1300);
	straight(75,52);
}
void crate1()
{
	writeDebugStreamLine("Crate 1");
	dropAtPos(12);
}

void crate2()
{
	writeDebugStreamLine("Crate 2");
  dropAtPos(24);
}

void crate3()
{
	writeDebugStreamLine("Crate 3");
	dropAtPos(57);
}

void crate4()
{
	writeDebugStreamLine("Crate 4");
	dropAtPos(67);
}

const int AUTO_LIFT_INIT=120;
const int AUTO_TWIST_INIT=0;
const int AUTO_LIFT_DROP=230;
const int AUTO_TWIST_DROP=255;

void primeCube()
{
	servoChangeRate[AutoWrist]=2;
	servo[AutoArm]=AUTO_LIFT_DROP;
	wait10Msec(100);
}

void dropCube()
{

	servo[AutoWrist]=AUTO_TWIST_DROP;
	wait10Msec(200);
}
void lowerCube()
{
		servo[AutoWrist]=AUTO_TWIST_INIT;
		servo[AutoArm]=AUTO_LIFT_INIT;
}
