#pragma once

//this class is the game engine

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class GameLoop
{
private: 
	//vars
	float enemPosX,enemPosY,enemRot;
	float speed, rotSpeed, dir;


	//window
	sf::RenderWindow* window;
	sf::Event ev;

	//game objects
	sf::RectangleShape enemy;

	//private functions
	void initVars();
	void initWindow();
	void initEnemies();

public:
	//contructors and destructors
	GameLoop();
	virtual ~GameLoop();

	const bool getWindowIsOpen() const;

	//functions
	void pollEvents();
	void Update();
	void Render();
};

