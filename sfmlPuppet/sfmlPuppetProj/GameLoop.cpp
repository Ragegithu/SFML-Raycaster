#include "GameLoop.h"
#include "raycast.h"
#include <iostream>



raycast ray;
std::vector<sf::RectangleShape> rays;

//private functions
void GameLoop::initVars()
{
	this->window = nullptr;
	this-> enemPosX,enemPosY, enemRot = 0;
	this->speed = 3;
	this->dir = 1;
	this->rotSpeed = 4;
}

void GameLoop::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(640, 480), "Game Window", sf::Style::Titlebar | sf::Style::Close);
	
	this->window->setFramerateLimit(60);
}

//constructors / destructors
GameLoop::GameLoop()
{
	this->initVars();
	this->initWindow();
	this->initEnemies();

}

void GameLoop::initEnemies()
{
	this->enemy.setSize(sf::Vector2f(100.f,100.f));
	this->enemy.setFillColor(sf::Color::Blue);
	this->enemy.setOutlineColor(sf::Color::White);
	this->enemy.setOutlineThickness(1.f);
	this->enemy.setOrigin(50, 50);

	ray.fov = 20;

	ray.rayRot = (-ray.fov/2);

	enemPosX = 400;
	enemPosY = 200;
}

GameLoop::~GameLoop()
{
	delete this->window;
}

//functions
void GameLoop::Update()
{
	this->pollEvents();


	sf::Vector2f movementVector(enemPosX ,enemPosY);
	this->enemy.setPosition(movementVector);
	this->enemy.setRotation(enemRot);


	for (int i = 0; i < ray.fov; i++) {

		rays.push_back(ray.rayShape);
		rays[i].setRotation((ray.rayRot + i ) + enemRot);
		rays[i].setPosition(movementVector);
	}
	dir = enemRot * (3.14159265359f / 180.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		enemPosY -= speed * cos(dir);
		enemPosX += speed * sin(dir);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		enemPosY += speed * cos(dir);
		enemPosX -= speed * sin(dir);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		enemPosX -= speed * cos(dir);
		enemPosY -= speed * sin(dir);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		enemPosX += speed * cos(dir);
		enemPosY += speed * sin(dir);
	}


	//CHANGE DIR WHEN ROTATING
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		//dirX += 1; //dirY -= 1;
		enemRot += rotSpeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		//dirX -= 1; //dirY += 1;
		enemRot -= rotSpeed;
}

const bool GameLoop::getWindowIsOpen() const
{
	return this->window->isOpen();
}

void GameLoop::Render()
{
	this->window->clear();

	//draw game here

	this->window->draw(this->enemy);

	for (const auto& raydraw : rays) {
		this->window->draw(raydraw);
	}



	this->window->display();
}

void GameLoop::pollEvents()
{
	//event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}
