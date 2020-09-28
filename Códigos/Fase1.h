#pragma once
#include "Stage.h"
namespace Matheus
{
	class Fase1 :public Stage
	{



	public:
		Fase1(sf::RenderWindow& window, Player* P1, Player* P2);
		Fase1();
		~Fase1();


	};
}
using namespace Matheus;