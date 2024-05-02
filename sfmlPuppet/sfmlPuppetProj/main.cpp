#include <iostream>
#include "GameLoop.h"


using namespace sf;
using namespace std;

int main()
{
	GameLoop game;

	//game loop
	while (game.getWindowIsOpen()) 
	{
		//update
		game.Update();
		//render
		game.Render();
	}


	return 0;
}
