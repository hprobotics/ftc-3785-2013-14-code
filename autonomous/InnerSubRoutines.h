void leftInnerCrate1()
{
	writeDebugStreamLine("Crate 1");
	turnRight(-75,1800);
	straight(75,49); //go forward
	pause();
	turnRight(-50,2200); //turn to face bridge
	pause();
	straight(75,42); //go and align next to cube
	pause();
	primeCube();
	dropCube();
	lowerCube();
	pause();
}

void leftInnerCrate2()
{
	writeDebugStreamLine("Crate 2");
	turnRight(-75,1800);
  straight(75,49); //go forward
	pause();
	turnRight(-50,2200); //turn to face bridge
	pause();
	primeCube();
	straight(75,54); //go and align next to cube
	pause();

	dropCube();
	straight(-50,20);
	lowerCube();

	straight(50,5);
}

void leftInnerCrate3()
{
	writeDebugStreamLine("Crate 3");
	turnRight(-75,1800);
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

void leftInnerCrate4()
{
	writeDebugStreamLine("Crate 4");
	turnRight(-75,1800);
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

void rightInnerCrate1()
{
	writeDebugStreamLine("Crate 1");
	turnRight(75,1800);
  straight(-75,51); //go forward
	pause();
	turnRight(50,2200); //turn to face bridge
	pause();
	straight(-75,76); //go and align next to cube
	pause();
	primeCube();
	dropCube();
	lowerCube();
	straight(75,36);
}

void rightInnerCrate2()
{
	writeDebugStreamLine("Crate 2");
	turnRight(75,1800);
  straight(-75,51); //go forward
	pause();
	turnRight(50,2200); //turn to face bridge
	pause();
	straight(-75,61); //go and align next to cube
	pause();
	primeCube();
	straight(50,5);
	dropCube();
	straight(-50,5);
	lowerCube();
	straight(75,24);
	wait10Msec(300);
}

void rightInnerCrate3()
{
	writeDebugStreamLine("Crate 3");
	turnRight(75,1800);
  straight(-75,51); //go forward
	pause();
	turnRight(50,2200); //turn to face bridge
	pause();
	straight(-75,42); //go and align next to cube
	pause();
	primeCube();
	dropCube();
	straight(75,6);
	lowerCube();
	wait10Msec(300);
}

void rightInnerCrate4()
{
	writeDebugStreamLine("Crate 4");
	turnRight(75,1800);
  straight(-75,51); //go forward
	pause();
	turnRight(50,2200); //turn to face bridge
	pause();
	straight(-75,20); //go and align next to cube
	pause();
	primeCube();
	dropCube();
	lowerCube();
	straight(-75,11);
	wait10Msec(300);
}
