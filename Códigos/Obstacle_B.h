#pragma once
#include "Obstacle.h"
namespace Matheus
{
	class Obstacle_B : public Obstacle
	{

	public:
		Obstacle_B(sf::Vector2f size, sf::Vector2f position, sf::Texture* texture);
		Obstacle_B(sf::Texture* texture, sf::Vector2f position);
		Obstacle_B();
		~Obstacle_B();


	};
}
using namespace Matheus;