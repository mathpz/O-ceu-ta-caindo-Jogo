#pragma once
#include "Inimigo.h"
#include "Player.h"

namespace Matheus
{
	class Enemy_B : public Inimigo
	{
	private:
		sf::Vector2f initialPos;
	public:
		Enemy_B(sf::Texture* tex);
		Enemy_B(sf::Texture* tex, sf::Vector2f position);
		Enemy_B();
		~Enemy_B();
		void update(float deltaTime);
	};
}
using namespace Matheus;