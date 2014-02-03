bool bDisplayDiagnostics;

void waitForStart(){
	nNxtExitClicks = 2;
	while(nNxtButtonPressed!=kExitButton){}
	return;
}
