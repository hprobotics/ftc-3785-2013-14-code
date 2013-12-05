#include "hitechnic-irseeker-v2.h"

#define ARRAYSIZE(a) (sizeof(a)/sizeof(maxpos))

typedef struct{
 int *border;
 int *value;
 int size;
} ZoneBoundaries;

int scanIR(tSensors ir, ZoneBoundaries bounds)
{
	int acS1,acS2,acS3,acS4,acS5;
	int maxpos=0;
	int maxval=0;
	for(int i=0; i<=255; i+=5)
	{
		servo[IRServo]=i;
		wait10Msec(5);
		HTIRS2readAllACStrength(ir,acS1,acS2,acS3,acS4,acS5);
		if(acS3>maxval)
		{
			maxval=acS3;
			maxpos=i;
		}
	}
	//writeDebugStreamLine("pos: %i",maxpos);
	for(int i=0; i<bounds.size; i++ )
	{
		writeDebugStreamLine("i: %i",i);
		if(maxpos<bounds.border[i])
		{
			return bounds.value[i];
		}
	}
	return 0;
}
