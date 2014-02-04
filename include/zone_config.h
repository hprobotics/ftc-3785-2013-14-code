ZoneBoundaries lZones;
ZoneBoundaries rZones;

	int lBorders[5] = {125,  190, 215, 233, 255};
	int lValues[3]  = {        1,   2,   3};


	int rBorders[5] = {0,   190, 215, 233, 128};
	int rValues[3]  = {        1,  2,  3};

void configZones()
{
	lZones.size=3;
	lZones.border=&lBorders;
	lZones.value=&lValues;

	rZones.size=3;
	rZones.border=&rBorders;
	rZones.value=&rValues;
}
