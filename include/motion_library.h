#pragma systemFile

int inchesToEncoder(int inches)
{
	int ticks;
	ticks = ((inches/(PI*WHEEL_SIZE))*ENCODER_RESOLUTION)/RATIO;
	return ticks;
}

void pause()
{
	wait10Msec(50);
}

void stopRobot()
{
	leftSpeed(0);
	rightSpeed(0);
}

void straight(int power, float inches)
{
	int encoder = inchesToEncoder(inches);
	int currentPower = 0;

	initalizeEncoders();

	while (distanceNotTraveled(encoder))
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
	}
	rightSpeed(0);
	leftSpeed(0);
}

void straight(int power)
{
	int currentPower = 0;

	initalizeEncoders();

		while(abs(currentPower) < abs(power))
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
		  rightSpeed(currentPower);
		  leftSpeed(currentPower);
		}
}

void turnLeft(int power, int encoder)
{
	int currentPower = 0;

	initalizeEncoders();

	encoder = encoder * 2 /3;
	encoder = encoder * RATIO;

	while (distanceNotTraveled(encoder))
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
	}
	rightSpeed(0);
	leftSpeed(0);
}

void turnRight(int power, int encoder)
{
	int currentPower = 0;

	encoder = encoder * 2 /3;

	initalizeEncoders();
	while (distanceNotTraveled(encoder))
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
		leftSpeed(-currentPower);
	}
	rightSpeed(0);
	leftSpeed(0);
}
