#include "Stage2.h"



Stage2::Stage2(sf::RenderWindow& window, Player* P1, Player* P2) :Stage()
{
	sf::Texture* back = new sf::Texture;
	back->loadFromFile("backgroundStageTwo.png");
	TexList.push_back(back);

	background.setSize(sf::Vector2f(512.0f, 512.0f));
	background.setTexture(back);

	sf::Texture* gro = new sf::Texture;
	gro->loadFromFile("ground.jpeg");
	TexList.push_back(gro);

	Platform* ground = new Platform(gro, sf::Vector2f(5000.0f, 50.0f), sf::Vector2f(0.0f, 540.0f));


	vPlatforms.push_back(ground);
	list.push(ground);

	P1->getBody().setPosition(-2480, 200.0f);

	randomPlatformCreation();
	randomEnemyCreation(ground->getSize());
	randomObstacleCreation(ground->getSize());

	list.push(P1);
	if (P2 != nullptr)
	{
		P2->getBody().setPosition(-2460.0f, 200.0f);
		list.push(P2);
	}


}


Stage2::~Stage2()
{

}
