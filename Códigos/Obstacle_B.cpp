#include "Obstacle_B.h"



Obstacle_B::Obstacle_B(sf::Vector2f size, sf::Vector2f position, sf::Texture* texture) : Obstacle(size, position, texture)
{
	setId(2);
}

Obstacle_B::Obstacle_B(sf::Texture * texture, sf::Vector2f position) : Obstacle(sf::Vector2f(60.0f, 30.0f), texture)
{
	body.setPosition(position);
	setId(2);
}

Matheus::Obstacle_B::Obstacle_B() :Obstacle()
{
}


Obstacle_B::~Obstacle_B()
{
}




