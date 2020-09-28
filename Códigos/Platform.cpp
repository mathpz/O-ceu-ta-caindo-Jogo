#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
}

Platform::Platform()
{
}

Platform::~Platform()
{
}

void Platform::update(float dT)
{
}

void Platform::draw(sf::RenderWindow& window)
{
	window.draw(body);
}
Collider Platform::getCollider()
{
	return Collider(body);
}

sf::Vector2f Platform::getSize()
{
	return body.getSize();
}

