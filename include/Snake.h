#pragma once
#include <string>
#include "SnakeSegment.h"
#include "Map.h"

class Snake
{
public:
	Snake(int dX,int dY,bool walls);
	~Snake();
	enum arrays{c_up=72, c_down=80, c_right=77 ,c_left=75 };
	void moveByKey(int key);
	void moveByDirectionNum();
	void addTail();
	int getDirectionNum() const { return directionNum; }
	const int getHeadX() const { return headX; }
	const int getHeadY() const { return headY; }
	const int getBodySize() const { return bodySize; }
	SnakeSegment* getBody() const { return body; }
	void toMap(Map & c);
private:
	int headX, headY;
	SnakeSegment *body;
	int bodySize,maxBody;
	int prevHeadX, prevHeadY;
	int mapDimX, mapDimY;
	int directionNum; // from enum arrays
	bool wallsExist;
	void setPrevious();
	void followHead();
	void reallocationMemory();
};
