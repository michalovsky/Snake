#include <iostream>
#include <fstream>
#include "Gameplay.h"
#include <Windows.h>
#include <conio.h>
#include <string>

Gameplay::Gameplay(int dX, int dY, bool walls) : snake(dX, dY, walls), food(dX, dY, snake), map(dX, dY), score(0), wallsExist(walls)
{
	getBestResults();
}

Gameplay::~Gameplay()
{
	delete[] bestResultsNames;
	delete[] bestResultsValues;
}

void Gameplay::start()
{
	system("cls");
	basicView();
	while (gameLoop());
	delay(125);
	std::cout << std::endl << "GAME OVER, SCORE: " << score << std::endl;
	setBestResults();
}

bool Gameplay::gameLoop()
{
	while (true)
	{
		while (!_kbhit())
		{
			automaticMovement();
			if (gameoverCondition()) return false;
			basicView();
			delay(85);
		}
		if (!input()) continue;
		if (gameoverCondition()) return false;
		appleCondition();
		basicView();
		fflush(stdin);
		delay(85);
	}
	return true;
}

bool Gameplay::input()
{
	_getch();
	switch (_getch())
	{
	case Snake::c_up:
		if (snake.getDirectionNum() != Snake::c_down)
		{
			snake.moveByKey(Snake::c_up);
			return true;
		}
		break;
	case Snake::c_down:
		if (snake.getDirectionNum() != Snake::c_up)
		{
			snake.moveByKey(Snake::c_down);
			return true;
		}
		break;
	case Snake::c_left:
		if (snake.getDirectionNum() != Snake::c_right)
		{
			snake.moveByKey(Snake::c_left);
			return true;
		}
		break;
	case Snake::c_right:
		if (snake.getDirectionNum() != Snake::c_left)
		{
			snake.moveByKey(Snake::c_right);
			return true;
		}
		break;
	}
	return false;
}

void Gameplay::basicView()
{
	map.clear();
	map.frame();
	snake.toMap(map);
	food.toMap(map);
	map.display();
	std::cout << "Best result: " << bestResultsNames[0] << " " << bestResultsValues[0] << std::endl;
	std::cout << "Score: " << score << std::endl;
}

void Gameplay::automaticMovement()
{
	if (snake.getDirectionNum() != 0)
	{
		snake.moveByDirectionNum();
		appleCondition();
	}
}

void Gameplay::appleCondition()
{
	if (food.eaten(snake))
	{
		food.newLocation(snake);
		snake.addTail();
		score += 10;
	}
}

bool Gameplay::gameoverCondition()
{
	if (wallsExist) //if walls==1 diffrent gameover condition
	{
		if (snake.getHeadX() == 0 || snake.getHeadX() == map.getDimX() - 1
			|| snake.getHeadY() == 0 || snake.getHeadY() == map.getDimY() - 1)
			return true;
	}

	for (int i = 0; i < snake.getBodySize(); i++)
	{
		if ((snake.getHeadY() == snake.getBody()[i].getY()
			&& snake.getHeadX() == snake.getBody()[i].getX()))
			return true;
	}
	return false;
}

void Gameplay::getBestResults()
{
	std::fstream file;
	std::string line;
	bestResultsValues = new int[10];
	bestResultsNames = new std::string[10];
	file.open("top10.txt", std::ios::in);
	if (file.good())
	{
		for (int i = 0; i < 10; i++)
		{
			getline(file, line);
			bestResultsNames[i] = line;
			getline(file, line);
			if (line != "")
			{
				bestResultsValues[i] = strtol(line.c_str(), NULL, 10);
			}
			else bestResultsValues[i] = 0;
		}
	}
	file.close();
}

void Gameplay::setBestResults()
{
	std::fstream file;
	std::string line, name;
	file.open("top10.txt", std::ios::out);

	for (int i = 0; i < 10; i++)
	{
		if (score > bestResultsValues[i])
		{
			std::cout << "You got into TOP" << i + 1 << " best results!" << std::endl;
			std::cout << "Insert yout name" << std::endl;
			std::cin >> name;

			for (int j = 9; j > i; --j)
			{
				bestResultsValues[j] = bestResultsValues[j - 1];
				bestResultsNames[j] = bestResultsNames[j - 1];
			}

			bestResultsValues[i] = score;
			bestResultsNames[i] = name;
			break;
		}
	}

	if (file.good())
	{
		for (int i = 0; i <= 9; i++)
		{
			file << bestResultsNames[i] << std::endl;
			file << bestResultsValues[i] << std::endl;
		}
	}
	file.close();
}

void Gameplay::delay(unsigned int ms)
{
	Sleep(ms);
}