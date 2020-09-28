#pragma once
#include "SFML/Graphics.hpp"
#include "Collider.h"
#include "Entidade.h"
namespace Matheus
{
	class Platform : public Entidade
	{
	private:
		sf::RectangleShape body;

	public:
		Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
		Platform();
		~Platform();
		void update(float dT);
		void draw(sf::RenderWindow& window);
		Collider getCollider();
		sf::Vector2f getSize();

	};
}
using namespace Matheus;