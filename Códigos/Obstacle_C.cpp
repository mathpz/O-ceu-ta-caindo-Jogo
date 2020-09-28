#include "Obstacle_C.h"



Obstacle_C::Obstacle_C(sf::Vector2f size, sf::Vector2f position, sf::Texture* texture) :Obstacle(size, position, texture)
{
	setId(3);
}

Obstacle_C::Obstacle_C(sf::Texture * texture, sf::Vector2f position) : Obstacle(sf::Vector2f(50.0f, 60.0f), texture)
{
	body.setPosition(position);
	setId(3);
}



Obstacle_C::~Obstacle_C()
{
}



