#include "Enemy_Boss.h"



Enemy_Boss::Enemy_Boss(sf::Texture* tex) : Inimigo(tex, sf::Vector2u(6, 1), 0.12f)
{
	body.setPosition(250.0f, 450.0f);
	yDistance = 0;
	velocity.x = -50.0f;
	velocity.y = -40.0f;
	faceright = true;
	goingUp = true;
	row = 0;
}

Matheus::Enemy_Boss::Enemy_Boss()
{
}


Enemy_Boss::~Enemy_Boss()
{
}

void Enemy_Boss::update(float dT)
{
	
	if (distance > 460.0f) 
	{
		distance = 0;
		if (!faceright)
		{
			faceright = true;
			velocity.x = -50.0f;
		}
		else
		{
			faceright = false;
			velocity.x = 50.0f;
		}
	}

	if (yDistance > 200.0f)
	{
		yDistance = 0;
		if (goingUp)
		{
			velocity.y = 40.0f;
			goingUp = false;
		}
		else
		{
			velocity.y = -40.0f;
			goingUp = true;
		}
	}
	
	distance += abs(velocity.x * dT);
	yDistance += abs(velocity.y * dT);

	animation.update(row, 6, dT, faceright);
	body.setTextureRect(animation.uvRect);
	getBody().move(velocity * dT);
}

