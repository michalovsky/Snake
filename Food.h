#pragma once
#include "Snake.h"
#include "Map.h"

class Food
{
public:
	Food(int dX, int dY, const Snake & s);
	bool eaten(const Snake & s);
	void newLocation(const Snake & s);
	void toMap(Map & c);
private:
	int foodX, foodY;
	int mapDimX, mapDimY; //from map 
	void randomLocation();
};