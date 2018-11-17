#pragma once

class Map
{
public:
	Map();
	Map(int dX, int dY);
	~Map();
	void display();
	void frame();
	void clear();
	int getDimX() const { return dimX; }
	int getDimY() const { return dimY; }
	char ** getMap() { return map; }
private:
	int dimX, dimY;
	char **map;
};
