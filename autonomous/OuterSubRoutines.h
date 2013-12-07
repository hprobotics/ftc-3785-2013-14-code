void dropCube();
void lowerCube();
void primeCube();

void dropAtPos(int distance)
{
	primeCube();
	straight(-50,distance);
	dropCube();
	straight(50,distance);
	lowerCube();
	turnRight(-50,2000);
	straight(50,36);
	turnRight(-50,2000);
	straight(50,48);
}
void crate1()
{
	writeDebugStreamLine("Crate 1");
	dropAtPos(18);
}

void crate2()
{
	writeDebugStreamLine("Crate 2");
  dropAtPos(28);
}

void crate3()
{
	writeDebugStreamLine("Crate 3");
	dropAtPos(42);
}

void crate4()
{
	writeDebugStreamLine("Crate 4");
	dropAtPos(52);
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
