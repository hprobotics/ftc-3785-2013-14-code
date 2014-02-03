
void leftDropAtPos(int distance)//The position in which to drop the cube
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
void leftOuterCrate1()
{
	writeDebugStreamLine("Crate 1");
	leftDropAtPos(12);//the position used for the first crate
}

void leftOuterCrate2()
{
	writeDebugStreamLine("Crate 2");
  leftDropAtPos(24);//the position used for the second crate
}

void leftOuterCrate3()
{
	writeDebugStreamLine("Crate 3");
	leftDropAtPos(58);//the position used for the third crate
}

void leftOuterCrate4()
{
	writeDebugStreamLine("Crate 4");
	leftDropAtPos(67); //the position used for the fourth crate
}

void rightDropAtPos(int distance)//The position in which to drop the cube
{
	straight(75,distance);//drive backwards at 75% power
	primeCube();
	dropCube();
	lowerCube();
	straight(-75,distance);//drive forwards at 75% power the same distance it went backwards.
	turnRight(75,1750);//turn right 90 degrees
	straight(-75,46);//go straight
	turnRight(75,1300);//turn on the ramp
	straight(-75,52);//go onto the ramp
}

void rightOuterCrate1()
{
	writeDebugStreamLine("Crate 1");
	rightDropAtPos(12);//the position used for the first crate
}

void rightOuterCrate2()
{
	writeDebugStreamLine("Crate 2");
  rightDropAtPos(24);//the position used for the second crate
}

void rightOuterCrate3()
{
	writeDebugStreamLine("Crate 3");
	rightDropAtPos(58);//the position used for the third crate
}

void rightOuterCrate4()
{
	writeDebugStreamLine("Crate 4");
	rightDropAtPos(67); //the position used for the fourth crate
}
