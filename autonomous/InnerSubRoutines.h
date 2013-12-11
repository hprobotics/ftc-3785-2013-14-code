void dropCube();
void lowerCube();
void primeCube();


void crate1()
{
	writeDebugStreamLine("Crate 1");
	straight(75,49); //go forward
	pause();
	turnRight(-50,2200); //turn to face bridge
	primeCube();
	pause();
	straight(75,45); //go and align next to cube
	pause();

	dropCube();
	lowerCube();
	pause();
}

void crate2()
{
	writeDebugStreamLine("Crate 2");
  straight(75,48); //go forward
	pause();
	turnRight(-50,2200); //turn to face bridge
	pause();
		primeCube();
	straight(75,54); //go and align next to cube
	pause();

	dropCube();
	straight(-50,20);
	lowerCube();
	wait10Msec(300);
}

void crate3()
{
	writeDebugStreamLine("Crate 3");
  straight(75,48); //go forward
	pause();
	turnRight(-50,2200); //turn to face bridge
	pause();
	straight(75,70); //go and align next to cube
	pause();
	primeCube();
	dropCube();
	lowerCube();
	wait10Msec(300);
	straight(-50,30);
}

void crate4()
{
	writeDebugStreamLine("Crate 4");
  straight(75,48); //go forward
	pause();
	turnRight(-50,2200); //turn to face bridge
	pause();
	straight(75,84); //go and align next to cube
	pause();
	primeCube();
	dropCube();
	lowerCube();
	straight(-50,42);
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
