#pragma once
#include "Obstacle.h"
namespace Matheus
{
	class Obstacle_A : public Obstacle 
	{

	public:
		Obstacle_A(sf::Vector2f size, sf::Vector2f position, sf::Texture* texture);
		Obstacle_A(sf::Texture* texture, sf::Vector2f position);
		Obstacle_A();
		~Obstacle_A();

	};
}
using namespace Matheus;