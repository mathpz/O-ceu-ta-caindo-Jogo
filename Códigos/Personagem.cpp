#include "Personagem.h"
#include <iostream>



Personagem::Personagem(sf::Vector2f size, sf::Texture* tex)
{
	this->tex = tex;
	body.setSize(size);
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(206.0f, 206.0f);
	body.setTexture(tex);
	gotHit = false;
	invencible = false;
}

Personagem::Personagem()
{
}

Personagem::~Personagem()
{
}

sf::RectangleShape& Personagem::getBody()
{
	return body;
}

Collider Personagem::getCollider()
{
	return Collider(body);
}

void Personagem::OnCollision(sf::Vector2f direction)
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
		canJump = true;
		
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top
		velocity.y = 0.0f;
	}
}

void Personagem::OnCollisionWithObstacle(sf::Vector2f direction)
{
	if (direction.y > 0.0f)
	{
		velocity.y *= -1.0f;
		hitPoints--;
	}
}

void Personagem::OnCollisionWithEnemy(sf::Vector2f direction, float dT)
{
	
	if (direction.y < 0.0f )
	{
		velocity.y *= -1;
		gotHit = false;
	}
	if(!invencible && !(direction.y < 0.0f))
	{
		getHit();
		gotHit = true;
		invencible = true;
	}
	else
	{
		gotHit = false;
	}
}

void Personagem::setHp(const int hp)
{
	hitPoints = hp;
}

void Personagem::setSpeed(const float speed)
{
	this->speed = speed;
}

void Personagem::update(float dT)
{
}

sf::Vector2f& Personagem::getVelocity()
{
	return velocity;
}

void Personagem::setVelocity(sf::Vector2f velocity)
{
	this->velocity = velocity;
}

float Personagem::getSpeed()
{
	return speed;
}

float Personagem::getJumpHeight()
{
	return jumpHeight;
}

void Personagem::setJumpHeight(float jumpHeight)
{
	this->jumpHeight = jumpHeight;
}

bool Personagem::getCanJump()
{
	return canJump;
}

void Personagem::setCanJump(bool canJump)
{
	this->canJump = canJump;
}

void Personagem::draw(sf::RenderWindow & window)
{
}

bool Personagem::checkDeath()
{
	if (hitPoints > 0)
		return false;
	else
		return true;
}

bool Personagem::checkHit()
{
	return gotHit;
}

void Personagem::getHit()
{
	hitPoints--;
}


