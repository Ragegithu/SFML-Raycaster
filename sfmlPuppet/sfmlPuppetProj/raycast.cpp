#include "raycast.h"


void raycast::createRay()
{
	this->raylength = -500.0f;
	this->origin.x = 30.0f;
	this->origin.y = 30.0f;
	this->rayRot = 0.0f;
	this->fov = 0.0f;

	this->rayShape.setSize(sf::Vector2f(1, raylength));
	this->rayShape.setFillColor(sf::Color::Red);
	this->rayShape.setRotation(rayRot);
}

raycast::raycast()
{
	createRay();
}

raycast::~raycast()
{
}
