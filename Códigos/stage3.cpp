#include "stage3.h"



stage3::stage3(sf::RenderWindow& window, Player* P1, Player* P2) : Stage()
{
	sf::Texture* back = new sf::Texture;
	back->loadFromFile("backgroundStageThree.png");
	TexList.push_back(back);

	background.setSize(sf::Vector2f(512.0f, 512.0f));
	background.setTexture(back);

	sf::Texture* gro = new sf::Texture;
	gro->loadFromFile("Platform.jpeg");
	TexList.push_back(gro);

	Platform* ground = new Platform(gro, sf::Vector2f(512.0f, 50.0f), sf::Vector2f(0.0f, 540.0f));
	
	sf::Texture* BossTex = new sf::Texture;
	BossTex->loadFromFile("BossTex.png");
	TexList.push_back(BossTex);

	Enemy_Boss* boss = new Enemy_Boss(BossTex);
	list.push(boss);
	vEnemies.push_back(boss);

	vPlatforms.push_back(ground);
	list.push(ground);

	P1->getBody().setPosition(-230, 200.0f);
	list.push(P1);
	
	if (P2 != nullptr)
	{
		P2->getBody().setPosition(-220.0f, 200.0f);
		list.push(P2);
	}
}


stage3::~stage3()
{
}
