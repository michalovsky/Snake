#include <iostream>
#include "Map.h"
#include <Windows.h>

Map::Map() : dimX(20), dimY(20)
{
	map = new char*[20];
	for (int i = 0; i < 20; i++)
	{
		map[i] = new char[20];
	}

}

Map::Map(int dX, int dY) : dimX(dX), dimY(dY)
{
	map = new char*[dY];
	for (int i = 0; i < dY; i++)
	{
		map[i] = new char[dX];
	}
}

Map::~Map()
{
	for (int i = 0; i < dimY; i++)
	{
		delete[] map[i];
	}
	delete[] map;
}

void Map::frame()
{
	for (int i = 0; i < dimY; i++)
	{
		for (int j = 0; j < dimX; j++)
		{
			if (i == 0 && j == 0) map[i][j] = 201;
			else if (i == dimY - 1 && j == 0) map[i][j] = 200;
			else if (i == dimY - 1 && j == dimX - 1) map[i][j] = 188;
			else if (i == 0 && j == dimX - 1) map[i][j] = 187;
			else if (i == 0 || i == (dimY - 1)) map[i][j] = 205;
			else if (j == 0 || j == (dimX - 1)) map[i][j] = 186;
			else map[i][j] = ' ';
		}
	}
}

void Map::display()
{
	for (int i = 0; i < dimY; i++)
	{
		for (int j = 0; j < dimX; j++)
		{
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}

void Map::clear()
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
