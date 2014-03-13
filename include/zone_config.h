ZoneBoundaries lZones;
ZoneBoundaries rZones;

	int lBorders[6] = {125,  170, 215, 233, 255, 255};
	int lValues[4]  = {        1,   2,   3,  4};


	int rBorders[6] = {0,   30, 46, 80, 128, 128};
	int rValues[4]  = {      1,  2,  3,  4};

void configZones()
{
	lZones.size=3;
	lZones.border=&lBorders;
	lZones.value=&lValues;

	rZones.size=4;
	rZones.border=&rBorders;
	rZones.value=&rValues;
}
