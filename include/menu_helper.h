TButtons NEXT_BTN = kRightButton;
TButtons PREV_BTN = kLeftButton;
TButtons CAT_BTN = kEnterButton;

void switchBool(bool *ptr, TButtons btn)
{
	if(btn == NEXT_BTN||btn == PREV_BTN)
	{
		*ptr=!*ptr;
	}
}

void switchInt(int *ptr, TButtons btn)
{
	if(btn == NEXT_BTN)
	{
		*ptr=*ptr+1;
		} else if(btn == PREV_BTN) {
		*ptr=*ptr-1;
	}
}

bool right=false;
bool inner=false;
int closeGoal=4;
int delay=0;

task runMenu()
{
	void* currVar;
	char currType;

	currVar = &right;
	currType = 'b';

	while(true){
		if(delay<0){
			delay=0;
			} else if(delay>15){
			delay = 15;
		}

		if(closeGoal<1){
			closeGoal=1;
			} else if(delay>4){
			closeGoal = 4;
		}

	nxtDisplayString(0,"Side:    %s",right?"right":"left ");
	nxtDisplayString(1,"Variant: %s",inner?"inner":"outer");
	nxtDisplayString(2,"Close:   %i",closeGoal);
		nxtDisplayString(3,"Delay:   %2i",delay);

		if(currVar == &right)
		{
			nxtDisplayStringAt(94,63,"*");
			nxtDisplayStringAt(94,55," ");
			nxtDisplayStringAt(94,47," ");
			nxtDisplayStringAt(94,39," ");
			} else if(currVar == &inner){
			nxtDisplayStringAt(94,63," ");
			nxtDisplayStringAt(94,55,"*");
			nxtDisplayStringAt(94,47," ");
			nxtDisplayStringAt(94,39," ");
			} else if(currVar == &closeGoal) {
			nxtDisplayStringAt(94,63," ");
			nxtDisplayStringAt(94,55," ");
			nxtDisplayStringAt(94,47,"*");
			nxtDisplayStringAt(94,39," ");
			} else {
			nxtDisplayStringAt(94,63," ");
			nxtDisplayStringAt(94,55," ");
			nxtDisplayStringAt(94,47," ");
			nxtDisplayStringAt(94,39,"*");
		}

		if ( externalBatteryAvg < 0)
        nxtDisplayTextLine(5, "Ext Batt: OFF");       //External battery is off or not connected
      else
        nxtDisplayTextLine(5, "Ext Batt:%4.1f V", externalBatteryAvg / (float) 1000);

      nxtDisplayTextLine(6, "NXT Batt:%4.1f V", nAvgBatteryLevel / (float) 1000);   // Display NXT Battery Voltage

	nxtDisplayTextLine(7,"%s,%s,%i,%i",right?"R":"L",inner?"In":"Out",closeGoal,delay);
		if(nNxtButtonPressed==NEXT_BTN||nNxtButtonPressed==PREV_BTN){
			if(currType=='b')
			{
				switchBool(currVar,nNxtButtonPressed);
				} else if (currType=='i') {
				switchInt(currVar,nNxtButtonPressed);
			}
			ClearTimer(T1);
			while(nNxtButtonPressed!=kNoButton&&time1[T1]<=400){}
		}

		if(nNxtButtonPressed==CAT_BTN){
			if(currVar == &right)
			{
				currVar = &inner;
				currType = 'b';
				} else if(currVar == &inner){
				currVar = &closeGoal;
				currType = 'i';
				} else if(currVar == &closeGoal) {
				currVar = &delay;
				currType = 'i';
				} else {
				currVar = &right;
				currType = 'b';
			}
			ClearTimer(T1);
			while(nNxtButtonPressed!=kNoButton&&time1[T1]<=400){}
		}


	}
}

void displayAutoType()
{
	nxtDisplayTextLine(7,"%s,%s,%i,%i",right?"R":"L",inner?"In":"Out",closeGoal,delay);
}
