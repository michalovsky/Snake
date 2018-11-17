#include "Food.h"
#include <ctime>
#include <cstdlib>

Food::Food(int dX, int dY, const Snake & s) : mapDimX(dX), mapDimY(dY)
{
	srand(time(NULL));
	randomLocation();

	while ((foodX == s.getHeadX() && foodY == s.getHeadY()))
	{
		randomLocation();
	}
}

bool Food::eaten(const Snake &s)
{
	if (foodX == s.getHeadX() && foodY == s.getHeadY())
		return true;
	return false;
}

void Food::newLocation(const Snake & s)
{
	randomLocation();

	for (int i = 0; i < s.getBodySize(); i++)
	{
		if ((foodY == s.getBody()[i].getY() && foodX == s.getBody()[i].getX())
			|| (foodX == s.getHeadX() && foodY == s.getHeadY()))
		{
			randomLocation();
			i = 0;
		}
	}
}

void Food::randomLocation()
{
	foodX = rand() % (mapDimX - 2) + 1;
	foodY = rand() % (mapDimY - 2) + 1;
}

void Food::toMap(Map & c)
{
	c.getMap()[foodY][foodX] = 177;
}