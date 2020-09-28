#include "Player.h"
#include <iostream>


Player::Player(sf::Texture* texture, sf::Vector2u imagecount, float switchTime) : Personagem(sf::Vector2f(25.0f, 50.0f), texture),
	animation(texture, imagecount, switchTime)
{
	id = -1;
	setSpeed(200.0f);
	setJumpHeight(200.0f);
	setHp(5);
	row = 0;
	faceright = true;
	invencible = false;
	damageDelay = 0;
}

Matheus::Player::Player():Personagem()
{
}


Player::~Player()
{
}

void Player::update(float deltaTime)
{
	velocity.x *= 0.0f;

	getPlayerInput();
	
	getVelocity().y += 981.0f * deltaTime;

	if (getVelocity().x == 0)
	{		
		row = 0;
	}
	else
	{
		row = 0;
		col = 12;
		if (getVelocity().x > 0.0f)
			faceright = true;
		else
			faceright = false;		
	}

	std::cout << hitPoints << std::endl;

	damageDelay += deltaTime;
	if (invencible && damageDelay > 2.0f)
	{
		damageDelay = 0;
		invencible = false;
	}

		
	animation.update(row, col, deltaTime, faceright);
	getBody().setTextureRect(animation.uvRect);		getBody().move(getVelocity() * deltaTime);
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(getBody());
}

sf::Vector2f Player::getPosition()
{
	return getBody().getPosition();
}

void Player::getPlayerInput()
{
	if (id == 1)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			getVelocity().x -= getSpeed();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			getVelocity().x += getSpeed();

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && getCanJump()))
		{
			setCanJump(false);
			getVelocity().y = -sqrtf(2.0f * 981.0f * getJumpHeight());
		}
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
				getVelocity().x -= getSpeed();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
				getVelocity().x += getSpeed();

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && getCanJump()))
		{
			setCanJump(false);
			getVelocity().y = -sqrtf(2.0f * 981.0f * getJumpHeight());			
		}

	}
}

void Player::setId(int id)
{
	this->id = id;
}




