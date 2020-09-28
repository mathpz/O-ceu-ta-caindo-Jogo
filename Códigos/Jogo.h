#pragma once
#include "Entidade.h"
#include "Menu.h"
#include "MenuRank.h"
#include "MenuFase.h"
#include "Ranking.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
#include "Stage.h"
#include "Fase1.h"
#include "Stage2.h"
#include "stage3.h"

using namespace Matheus;
using namespace std;

class Jogo
{
private:
	Menu* menu; //agregaaaar
	sf::RenderWindow window;
	Stage* stage;
	Player* P1;
	Player* P2;

public:
	Jogo();
	~Jogo();
	void executarMenu(sf::RenderWindow& window);
	void exec();
	void executarJogo(sf::RenderWindow& window, bool twoPlayers, int stageID);
	void menuFase(sf::RenderWindow& window, bool twoPlayers);
	void menuRank(sf::RenderWindow& window);
};

