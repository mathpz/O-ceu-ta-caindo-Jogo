#include "Enemy_B.h"



Enemy_B::Enemy_B(sf::Texture* tex) : Inimigo(tex, sf::Vector2u(6, 1), 0.24f)
	
{
	body.setPosition(sf::Vector2f(400.0f, 290.0f));
	faceright = false;
	
}

Enemy_B::Enemy_B(sf::Texture * tex, sf::Vector2f position) : Inimigo(tex, sf::Vector2u(6, 1), 0.12f)
{
	initialPos = position;
	body.setPosition(position);
	faceright = false;
	velocity.x = -250.0f;
	row = 0;
}

Matheus::Enemy_B::Enemy_B()
{
}


Enemy_B::~Enemy_B()
{
}

void Enemy_B::update(float deltaTime)
{

	if (distance > 400.0f)
	{
		distance = 0;
		body.setPosition(initialPos.x, 0.0f);
		setCanJump(false);
	}

	getVelocity().y += 981.0f * deltaTime;
	
	if (getCanJump())
	{
		velocity.x = -250.0f;
		distance += abs(getVelocity().x * deltaTime);
	}
	else
		velocity.x = 0;

	animation.update(row, 6, deltaTime, faceright);
	body.setTextureRect(animation.uvRect);
	getBody().move(getVelocity() * deltaTime);

}
