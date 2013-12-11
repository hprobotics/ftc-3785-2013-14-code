void dropCube();
void lowerCube();
void primeCube();


void crate1()
{
	writeDebugStreamLine("Crate 1");
	straight(50,49); //go forward
	pause();
	turnRight(-50,2000); //turn to face bridge
	primeCube();
	pause();
	straight(50,40); //go and align next to cube
	pause();

	dropCube();
	straight(-50,10);
	lowerCube();
	pause();
}

void crate2()
{
	writeDebugStreamLine("Crate 2");
  straight(50,48); //go forward
	pause();
	turnRight(-50,2000); //turn to face bridge
	pause();
		primeCube();
	straight(50,57); //go and align next to cube
	pause();

	dropCube();
	straight(-50,20);
	lowerCube();
	wait10Msec(300);
}

void crate3()
{
	writeDebugStreamLine("Crate 3");
  straight(50,48); //go forward
	pause();
	turnRight(-50,2000); //turn to face bridge
	pause();
	straight(50,70); //go and align next to cube
	pause();
	primeCube();
	dropCube();
	lowerCube();
	wait10Msec(300);
	straight(-50,33);
}

void crate4()
{
	writeDebugStreamLine("Crate 4");
  straight(50,48); //go forward
	pause();
	turnRight(-50,2000); //turn to face bridge
	pause();
	straight(50,80); //go and align next to cube
	pause();
	primeCube();
	dropCube();
	lowerCube();
	wait10Msec(300);
	straight(-50,39);
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
