#include "stdafx.h"
#include "Location.h"

Location::Location()
{
}

Location::Location(int locationX, int locationY)
{
	grid.x = locationX;
	grid.y = locationY;
}

Location::~Location()
{
}

void Location::Move(char tileShift)
{
	char xShift = tileShift / 10;
	char yShift = tileShift % 10;
	grid.x += 1000 * xShift + yShift;
}
