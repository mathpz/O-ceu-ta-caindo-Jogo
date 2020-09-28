#include "Obstacle_A.h"



Obstacle_A::Obstacle_A(sf::Vector2f size, sf::Vector2f position, sf::Texture* texture) : Obstacle(size, position, texture)
{
	setId(1);
}

Obstacle_A::Obstacle_A(sf::Texture * texture, sf::Vector2f position) : Obstacle(sf::Vector2f(25.0f, 25.0f), texture)
{
	body.setPosition(position);
	setId(1);
}

Matheus::Obstacle_A::Obstacle_A() :Obstacle()
{
}


Obstacle_A::~Obstacle_A()
{
}



