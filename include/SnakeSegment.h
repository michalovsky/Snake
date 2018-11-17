#pragma once

class SnakeSegment
{
public:
	SnakeSegment() : x(0), y(0) {};
	SnakeSegment(int xPosition, int yPosition) :x(xPosition), y(yPosition) {}
	int getX() { return x; }
	int getY() { return y; }
	int & getRefX() { return x; }
	int & getRefY() { return y; }
private:
	int x, y;
};