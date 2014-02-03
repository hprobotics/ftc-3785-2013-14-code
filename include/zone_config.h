ZoneBoundaries lZones;
ZoneBoundaries rZones;

void configZones()
{
	lZones.size=3;
	int lBorders[4] = {125,  190, 215, 233};
	int lValues[3]  = {        1,   2,   3};
	lZones.border=&lBorders;
	lZones.value=&lValues;

	rZones.size=3;
	int rBorders[4] = {125,  190, 215, 233};
	int rValues[3]  = {        1,   2,   3};
	rZones.border=&rBorders;
	rZones.value=&rValues;
}
