#pragma once
#include "Stage.h"

namespace Matheus
{
	class stage3 :
		public Stage
	{
	public:
		stage3(sf::RenderWindow& window, Player* P1, Player* P2);
		~stage3();
	};
}
using namespace Matheus;