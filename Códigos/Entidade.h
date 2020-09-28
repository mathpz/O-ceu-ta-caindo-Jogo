#pragma once
#include "SFML/Graphics.hpp"


namespace Matheus
{
	class Entidade
	{

	public:
		Entidade();
		~Entidade();
		virtual void update(float dT) = 0;
		virtual void draw(sf::RenderWindow& window) = 0;

	};
}
using namespace Matheus;
