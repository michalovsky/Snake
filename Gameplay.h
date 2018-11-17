#pragma once
#include "Map.h"
#include "Snake.h"
#include "Food.h"

class Gameplay
{
public:
	Gameplay(int dX, int dY, bool walls); // (xdimension, ydimension, if walls exists)
	~Gameplay();
	void start();
private:
	Map map;
	Snake snake;
	Food food;
	int score;
	bool wallsExist; // mode game 0 no walls, 1 walls
	int *bestResultsValues; //from txt
	std::string *bestResultsNames; //from txt
	bool input();
	void basicView();
	bool gameoverCondition();
	void automaticMovement();
	void appleCondition();
	bool gameLoop();
	void getBestResults();
	void setBestResults();
	void delay(unsigned int ms);
};