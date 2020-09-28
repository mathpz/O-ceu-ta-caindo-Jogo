#pragma once
#include "Inimigo.h"

namespace Matheus
{
	class Enemy_A : public Inimigo
	{
	private:

	public:
		Enemy_A(sf::Texture* tex, sf::Vector2f pos);
		Enemy_A();
		~Enemy_A();
		void update(float deltaTime);

	};
}
using namespace Matheus;
