#include "Obstacle.h"



Obstacle::Obstacle(sf::Vector2f size, sf::Vector2f position, sf::Texture* texture)
{
	body.setSize(size);
	body.setOrigin(body.getSize() / 2.0f);
	//body.setPosition(position);
	body.setTexture(texture);

}

Obstacle::Obstacle(sf::Vector2f size, sf::Texture * texture)
{
	body.setSize(size);
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(texture);
}

Obstacle::Obstacle()
{
}


Obstacle::~Obstacle()
{

}

void Obstacle::update(float dT)
{
	velocity.y += 981.0f * dT;
	
	body.move(velocity * dT);
}

void Obstacle::draw(sf::RenderWindow& window)
{
	window.draw(body);
}

Collider Obstacle::getCollider()
{
	return Collider(body);
}

void Obstacle::OnCollison(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//collision on the left
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right
		velocity.x = 0.0f;
	}

	if (direction.y < 0.0f)
	{
		//Colision on the bottom
		velocity.y = 0.0f;

	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top
		velocity.y = 0.0f;
	}
}

