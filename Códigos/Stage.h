#pragma once
#include "Platform.h"
#include  "Animation.h"
#include "Player.h"
#include "Inimigo.h"
#include "Entidade.h"
#include "SFML/Graphics.hpp"
#include "EntityList.h"
#include "Obstacle.h"
#include "Obstacle_A.h"
#include "Obstacle_B.h"
#include "Obstacle_C.h"
#include "Enemy_A.h"
#include "Enemy_B.h"
#include "Enemy_Boss.h"
#include "MenuPausa.h"
#include <iostream>
#include <random>
#include <chrono>
#include <list>
namespace Matheus
{

	class Stage
	{
	protected:
		EntityList list;
		sf::RectangleShape background;
		std::list<sf::Texture*> TexList;
		std::vector<Inimigo*> vEnemies;
		std::vector<Platform*> vPlatforms;
		std::vector<Obstacle*> vObstacles;
	private:
		MenuPausa* pause;

	public:
		Stage();
		void manageCollisions(Player* P1, Player* P2, float dT);
		void manageView(Player* P1, Player* P2, sf::View& view, sf::RenderWindow& window);
		void checkDeaths(Player* P1, Player* P2);
		void exec(sf::RenderWindow& window, Player* P1, Player* P2);
		int RandomPosition(int left, int right);
		void randomPlatformCreation();
		void randomEnemyCreation(sf::Vector2f groundSize);
		void randomObstacleCreation(sf::Vector2f groundSize);
		~Stage();


	};

}
using namespace Matheus;