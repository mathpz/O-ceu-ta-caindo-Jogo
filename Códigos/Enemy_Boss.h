#pragma once
#include "Inimigo.h"

namespace Matheus
{
	class Enemy_Boss : public Inimigo
	{
	private:
		float yDistance;
		bool goingUp;
	public:
		Enemy_Boss(sf::Texture* tex);
		Enemy_Boss();
		~Enemy_Boss();
		void update(float dT);
	};
}
using namespace Matheus;
