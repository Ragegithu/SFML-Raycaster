#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class raycast
{

public:

	void createRay();

	float raylength, rayRot, fov;

	sf::Vector2f origin, endpoint;

	sf::RectangleShape rayShape;

public:

	raycast();
	virtual ~raycast();
};

