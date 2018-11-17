#include "Snake.h"

Snake::Snake(int dX, int dY, bool walls) :headX(dX / 2), headY(dY / 2), bodySize(0), mapDimX(dX), mapDimY(dY), prevHeadX(0), prevHeadY(0), directionNum(0), maxBody(10)
{
	body = new SnakeSegment[maxBody];
	wallsExist = walls;
}

Snake::~Snake()
{
	delete[] body;
}

void Snake::moveByKey(int key)
{
	switch (key)
	{
	case c_up:
		directionNum = c_up;
		moveByDirectionNum();
		break;
	case c_down: 
		directionNum = c_down;
		moveByDirectionNum();
		break;
	case c_right:
		directionNum = c_right;
		moveByDirectionNum();
		break;
	case c_left: 
		directionNum = c_left;
		moveByDirectionNum();
		break;
	}
}

void Snake::moveByDirectionNum()
{
	switch (directionNum)
	{
	case c_up: 
		setPrevious();
		--headY;
		if (headY == 0 && !wallsExist) headY = mapDimY-2;  
		followHead();
		break;
	case c_down:
		setPrevious();
		++headY;
		if (headY == mapDimY-1 && !wallsExist) headY = 1; 
		followHead();
		break;
	case c_right:
		setPrevious();
		++headX;
		if (headX == mapDimX-1 && !wallsExist) headX = 1;
		followHead();
		break;
	case c_left:
		setPrevious();
		--headX;
		if (headX == 0 && !wallsExist) headX = mapDimX - 2;
		followHead();
		break;
	}
}

void Snake::followHead()
{
	for (int i = bodySize -1; i>=0; --i)
	{
		if (i == 0)
		{
			body[i].getRefY() = prevHeadY;
			body[i].getRefX() = prevHeadX;
		}
		else
		{
			body[i].getRefY() = body[i - 1].getY();
			body[i].getRefX() = body[i - 1].getX();
		}
	}
}

void Snake::setPrevious()
{
	prevHeadX = headX;
	prevHeadY = headY;
}

void Snake::addTail()
{
	if (bodySize == maxBody) // reallocation memory
	{
		reallocationMemory();
	}

	if (bodySize == 0)
	{
		body[bodySize].getRefY() = prevHeadY;
		body[bodySize].getRefX() = prevHeadX;
		bodySize++;
	}
	else
	{
		body[bodySize].getRefY() = body[bodySize - 1].getY();
		body[bodySize].getRefX() = body[bodySize - 1].getX();
		bodySize++;
	}

}

void Snake::reallocationMemory()
{
	SnakeSegment *temp = new SnakeSegment[maxBody];
	for (int i = 0; i < bodySize; i++)
	{
		temp[i].getRefX() = body[i].getX();
		temp[i].getRefY() = body[i].getY();
	}
	delete[] body;

	maxBody += 10;
	body = new SnakeSegment[maxBody];

	for (int i = 0; i < bodySize; i++)
	{
		body[i].getRefX() = temp[i].getX();
		body[i].getRefY() = temp[i].getY();
	}
	delete[] temp;
}

void Snake::toMap(Map & c)
{	
	c.getMap()[headY][headX] = 219;

	for (int i = 0; i < getBodySize(); i++)
	{
		c.getMap()[body[i].getY()][body[i].getX()] = 219;
	}
}