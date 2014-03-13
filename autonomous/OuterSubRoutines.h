int leftTargets[4] = {16, 32.5, 78.5, 90.5};

void leftDropAtPos(int idx)//The position in which to drop the cube
{
	servo[LeftIRServo]=170;

	int power = -75;
	int encoder = inchesToEncoder(leftTargets[idx]);
	int currentPower = 0;

	initalizeEncoders();

	bool exit = false;
	int counter = 0;

	while (!exit)
	{
		if(abs(currentPower) < abs(power))
		{
			if(power>0)
			{
				currentPower++;
			}
			if(power<0)
			{
				currentPower--;
			}
			wait1Msec(20);
		}
		rightSpeed(currentPower);
		leftSpeed(currentPower);
		if(!distanceNotTraveled(encoder)){
			int pos = HTIRS2readACDir(LeftIRSensor);
			writeDebugStreamLine("ir: %i",pos);
			if(pos>4&&idx<(closeGoal?1:3)&&counter<3&&(closeGoal?position<3:true)) {
				idx++;
				counter++;
				encoder=inchesToEncoder(leftTargets[idx]);
			} else {
				exit = true;
			}
		}
	}
		writeDebugStreamLine("idx: %i",idx);
	rightSpeed(0);
	leftSpeed(0);

	primeCube();
	dropCube();
	lowerCube();
	straight(75,leftTargets[idx]);//drive forwards at 75% power the same distance it went backwards.
	turnRight(-75,1750);//turn right 90 degrees
	straight(75,62);//go straight
	turnRight(-75,1300);//turn on the ramp
	straight(75,70);//go onto the ramp
}
void leftOuterCrate1()
{
	writeDebugStreamLine("Crate 1");
	leftDropAtPos(0);//the position used for the first crate
}

void leftOuterCrate2()
{
	writeDebugStreamLine("Crate 2");
  leftDropAtPos(1);//the position used for the second crate
}

void leftOuterCrate3()
{
	writeDebugStreamLine("Crate 3");
	leftDropAtPos(2);//the position used for the third crate
}

void leftOuterCrate4()
{
	writeDebugStreamLine("Crate 4");
	leftDropAtPos(3); //the position used for the fourth crate
}

int rightTargets[4] = {105.5, 90, 48.5, 34};

void rightDropAtPos(int idx)//The position in which to drop the cube
{
	servo[LeftIRServo]=128;

	int power = 75;
	int encoder = inchesToEncoder(rightTargets[idx]);
	int currentPower = 0;

	initalizeEncoders();

	bool exit = false;
	int counter = 0;

	while (!exit)
	{
		if(abs(currentPower) < abs(power))
		{
			if(power>0)
			{
				currentPower++;
			}
			if(power<0)
			{
				currentPower--;
			}
			wait1Msec(20);
		}
		rightSpeed(currentPower);
		leftSpeed(currentPower);
		if(!distanceNotTraveled(encoder)){
			int pos = HTIRS2readACDir(LeftIRSensor);
			writeDebugStreamLine("ir: %i",pos);
			if(pos<4&&idx>(closeGoal?2:0)&&counter<3&&(closeGoal?position>3:true)) {
				idx--;
				counter++;
				encoder=inchesToEncoder(rightTargets[idx]);
				writeDebugStreamLine("newTarget: %i",encoder);
			} else {
				exit = true;
			}
		}
	}
		writeDebugStreamLine("idx: %i",idx);
	rightSpeed(0);
	leftSpeed(0);

	primeCube();
	dropCube();
	lowerCube();
	straight(-75,rightTargets[idx]);//drive forwards at 75% power the same distance it went backwards.
	turnRight(75,1600);//turn right 90 degrees
	straight(-75,60);//go straight
	turnRight(75,1300);//turn on the ramp
	straight(-75,60);//go onto the ramp
}

void rightOuterCrate1()
{
	writeDebugStreamLine("Crate 1");
	rightDropAtPos(0);//the position used for the first crate
}

void rightOuterCrate2()
{
	writeDebugStreamLine("Crate 2");
  rightDropAtPos(1);//the position used for the second crate
}

void rightOuterCrate3()
{
	writeDebugStreamLine("Crate 3");
	rightDropAtPos(2);//the position used for the third crate
}

void rightOuterCrate4()
{
	writeDebugStreamLine("Crate 4");
	rightDropAtPos(3); //the position used for the fourth crate
}
