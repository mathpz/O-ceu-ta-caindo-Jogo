#pragma once
#include "Obstacle.h"
namespace Matheus
{
	class Obstacle_C : public Obstacle
	{
	public:
		Obstacle_C(sf::Vector2f size, sf::Vector2f position, sf::Texture* texture);
		Obstacle_C(sf::Texture* texture, sf::Vector2f position);
		~Obstacle_C();

	};
}
using namespace Matheus;