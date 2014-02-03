#include "hitechnic-irseeker-v2.h"

#define ARRAYSIZE(a) (sizeof(a)/sizeof(maxpos))

typedef struct{
 int *border;
 int *value;
 int size;
} ZoneBoundaries;

int scanIR(tSensors ir, TServoIndex irServo, ZoneBoundaries bounds)
{
	int acS1,acS2,acS3,acS4,acS5;
	int maxpos=0;
	int maxval=0;
	for(int i=bounds.border[0]; i<=255; i+=3)
	{
		servo[irServo]=i;
		wait10Msec(3);
		HTIRS2readAllACStrength(ir,acS1,acS2,acS3,acS4,acS5);
		if(acS3>maxval)
		{
			maxval=acS3;
			maxpos=i;
		}
	}
	writeDebugStreamLine("pos: %i",maxpos);
	if(maxpos<=bounds.border[0])
	{
		return bounds.size+1;
	}

	for(int i=0; i<bounds.size; i++ )
	{
		//writeDebugStreamLine("i: %i",i);
		if(maxpos<bounds.border[i+1])
		{
			return bounds.value[i];
		}
	}
	return 0;
}
