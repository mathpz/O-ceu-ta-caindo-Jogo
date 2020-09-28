#include "Enemy_A.h"



Enemy_A::Enemy_A(sf::Texture * tex, sf::Vector2f pos) :Inimigo(tex, sf::Vector2u(4, 1), 0.12f)
{
	body.setPosition(pos);
	row = 0;
}

Matheus::Enemy_A::Enemy_A()
{
}

Enemy_A::~Enemy_A()
{
}

void Enemy_A::update(float deltaTime)
{
	getVelocity().x *= 0;


	if (distance >= 150.0f)
	{
		distance = 0;
		if (faceright)
		{
			faceright = false;
		}
		else if (faceright == false)
		{
			faceright = true;
		}
	}

	if (faceright)
	{
		getVelocity().x += 125.0f;
	}
	else
	{
		getVelocity().x -= 125.f;
	}

	getVelocity().y += 981.0f * deltaTime;

	distance += abs(getVelocity().x * deltaTime);
	animation.update(row, 4, deltaTime, faceright);
	body.setTextureRect(animation.uvRect);
	getBody().move(getVelocity() * deltaTime);
}
