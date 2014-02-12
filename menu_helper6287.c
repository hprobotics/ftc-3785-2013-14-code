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
		*ptr=*ptr+2;
		} else if(btn == PREV_BTN) {
		*ptr=*ptr-2;
	}
}

bool right=false;
bool block=false;
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
			} else if(delay>12){
			delay = 12;
		}

	nxtDisplayString(0,"Side:    %s",right?"right":"left ");
	nxtDisplayString(1,"Variant: %s",block?"block":"cube ");
		nxtDisplayString(2,"Delay:   %2i",delay);

		if(currVar == &right)
		{
			nxtDisplayStringAt(94,63,"*");
			nxtDisplayStringAt(94,55," ");
			nxtDisplayStringAt(94,47," ");
			} else if(currVar == &block){
			nxtDisplayStringAt(94,63," ");
			nxtDisplayStringAt(94,55,"*");
			nxtDisplayStringAt(94,47," ");
			} else {
			nxtDisplayStringAt(94,63," ");
			nxtDisplayStringAt(94,55," ");
			nxtDisplayStringAt(94,47,"*");
		}

		if ( externalBatteryAvg < 0)
        nxtDisplayTextLine(5, "Ext Batt: OFF");       //External battery is off or not connected
      else
        nxtDisplayTextLine(5, "Ext Batt:%4.1f V", externalBatteryAvg / (float) 1000);

      nxtDisplayTextLine(6, "NXT Batt:%4.1f V", nAvgBatteryLevel / (float) 1000);   // Display NXT Battery Voltage

	nxtDisplayTextLine(7,"%s,%s,%i",right?"R":"L",block?"Block":"Cube",delay);
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
				currVar = &block;
				currType = 'b';
				} else if(currVar == &block){
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
	nxtDisplayTextLine(7,"%s,%s,%i",right?"R":"L",block?"Block":"Cube",delay);
}
