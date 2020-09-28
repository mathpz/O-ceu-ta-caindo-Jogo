#pragma once
#include "SFML/Graphics.hpp"
namespace Matheus
{


	class Collider
	{
	private:
		sf::RectangleShape& body;

	public:
		Collider(sf::RectangleShape& body);
		Collider();
		~Collider();
		bool checkCollision(Collider& other, sf::Vector2f& direction, float push);  //push (how much each object will be pushed out)
		void move(float dx, float dy);
		sf::Vector2f getPosition();
		sf::Vector2f getHalfSize();
	};
}
using namespace Matheus;