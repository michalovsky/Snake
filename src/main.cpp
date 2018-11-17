#include <iostream>
#include "Snake.h"
#include "Map.h"
#include "Food.h"
#include "Gameplay.h"
#include <string>

int main()
{
	int height,width;
	std::string answer;
	bool gameMode;
	std::cout << "Insert height of map (recommended 10-25)"<<std::endl;
	std::cin >> height;
	std::cout << "Insert width of map (recommended 20-40)" << std::endl;
	std::cin >> width;
	std::cout << "Do you want to walk through walls? yes/no"<<std::endl;
	std::cin >> answer;
	gameMode = (answer == "no") ? true : false;
	Gameplay game(width,height,gameMode);
	game.start();
	
	system("pause");
	return 0;
}
	