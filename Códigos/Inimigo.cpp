#include "Inimigo.h"





Inimigo::Inimigo(sf::Texture* tex, sf::Vector2u imagecount, float switchTime) : Personagem(sf::Vector2f(70.0f, 60.0f), tex),
	animation(tex, imagecount, switchTime)
{
	setHp(1);
	setSpeed(300.0f);
	distance = 0;
	row = 3;
}

Inimigo::Inimigo()
{
}

Inimigo::~Inimigo()
{
}

void Inimigo::update(float deltaTime)
{


}

void Inimigo::draw(sf::RenderWindow& window)
{
	window.draw(body);
}

