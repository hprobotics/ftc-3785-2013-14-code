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
