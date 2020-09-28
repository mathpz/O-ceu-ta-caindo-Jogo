#include "Stage.h"
#include <iostream> 


Stage::Stage()
{
	pause = nullptr;
}

void Stage::manageCollisions(Player* P1, Player* P2, float dT)
{

	sf::Vector2f direction;

	/*check Platforms x Players/Enemies/Obstacles*/
	for (unsigned int i = 0; i < vPlatforms.size(); i++)
	{
		if (P1 != nullptr)
		{
			Collider c1 = P1->getCollider();
			if (vPlatforms[i]->getCollider().checkCollision(c1, direction, 1.0f))
			{
				P1->OnCollision(direction);
			}
		}
		if (P2 != nullptr)
		{
			Collider c2 = P2->getCollider();
			if (vPlatforms[i]->getCollider().checkCollision(c2, direction, 1.0f))
			{
				P2->OnCollision(direction);
			}
		}
	
		for (unsigned int j = 0; j < vEnemies.size(); j++)
		{
			Collider enemy = vEnemies[j]->getCollider();
			if (vPlatforms[i]->getCollider().checkCollision(enemy, direction, 1.0f))
			{
				vEnemies[j]->OnCollision(direction);
			}
		}

		for (unsigned int j = 0; j < vObstacles.size(); j++)
		{
			Collider obst = vObstacles[j]->getCollider();
			if (vPlatforms[i]->getCollider().checkCollision(obst, direction, 1.0f))
			{
				vObstacles[j]->OnCollison(direction);
			}
		}
	}
	/*check Players x Enemies*/	
	for (unsigned int i = 0; i < vEnemies.size(); i++)
	{
		if (P1 != nullptr)
		{
			Collider c1 = P1->getCollider();
			if (vEnemies[i]->getCollider().checkCollision(c1, direction, 1.0f))
			{
				P1->OnCollisionWithEnemy(direction, dT);
				if (!P1->checkHit())
				{
					vEnemies[i]->getHit();
				}
			}
		}
		if (P2 != nullptr)
			{
			Collider c2 = P2->getCollider();
			if (vEnemies[i]->getCollider().checkCollision(c2, direction, 1.0f))
			{
				P2->OnCollisionWithEnemy(direction, dT);
				if (!P2->checkHit())
				{
					vEnemies[i]->getHit();
				}
			}
		}
	}
	/*Check Obstacles x Players*/
	for (unsigned int i = 0; i < vObstacles.size(); i++)
	{
		
		/* id(1) == box*/
		if (vObstacles[i]->getId() == 1)
		{
			if (P1 != nullptr)
			{
				Collider c1 = P1->getCollider();
				if (vObstacles[i]->getCollider().checkCollision(c1, direction, 0.5f))
				{
					P1->OnCollision(direction);
				}
			}
			if (P2 != nullptr)
			{
				Collider c2 = P2->getCollider();
				if (vObstacles[i]->getCollider().checkCollision(c2, direction, 0.5f))
				{
					P2->OnCollision(direction);
				}
			}
		}
		/*id(2) == spikes*/
		else if (vObstacles[i]->getId() == 2)
		{
			Collider obst = vObstacles[i]->getCollider();
			if (P1 != nullptr)
			{
				Collider c1 = P1->getCollider();
				if (P1->getCollider().checkCollision(obst, direction, 0.0f))
				{
					P1->OnCollisionWithObstacle(direction);
				}
			}
			if (P2 != nullptr)
			{
				Collider c2 = P2->getCollider();
				if (P2->getCollider().checkCollision(obst, direction, 0.0f))
				{
					P2->OnCollisionWithObstacle(direction);
				}
			}
		}
		else if(vObstacles[i]->getId() == 3)
		{
			if (P1 != nullptr)
			{
				Collider c1 = P1->getCollider();
				if (vObstacles[i]->getCollider().checkCollision(c1, direction, 1.0f))
				{
					P1->OnCollision(direction);
				}
			}
			if (P2 != nullptr)
			{
				Collider c2 = P2->getCollider();
				if (vObstacles[i]->getCollider().checkCollision(c2, direction, 1.0f))
				{
					P2->OnCollision(direction);
				}
			}
		}

	}
}

void Stage::manageView(Player* P1, Player * P2, sf::View& view, sf::RenderWindow& window)
{
	if (P2 == nullptr && P1 != nullptr)
	{
		view.setCenter(P1->getPosition());
		if (view.getCenter().x - window.getSize().x / 2.0f < -2500)
		{
			view.setCenter(-2244, P1->getPosition().y);
		}
		else if (view.getCenter().x + window.getSize().x / 2.0f > 2500)
		{
			view.setCenter(2244, P1->getPosition().y);
		}

	}
	else if (P1 == nullptr && P2 != nullptr)
	{
		view.setCenter(P2->getPosition());
		if (view.getCenter().x - window.getSize().x / 2.0f < -2500)
		{
			view.setCenter(-2244, P2->getPosition().y);
		}
		else if (view.getCenter().x + window.getSize().x / 2.0f > 2500)
		{
			view.setCenter(2244, P2->getPosition().y);
		}

	}
	else
	{
		sf::Vector2f viewpos((P2->getPosition().x + P1->getPosition().x) / 2.0f, (P2->getPosition().y + P1->getPosition().y) / 2.0f - 50);
		view.setCenter(viewpos);
		if (view.getCenter().x - window.getSize().x / 2.0f < -2500)
		{
			view.setCenter(-2244, (P1->getPosition().y + P2->getPosition().y) / 2.0f - 50);
		}
		else if (view.getCenter().x + window.getSize().x / 2.0f > 2500)
		{
			view.setCenter(2244, (P2->getPosition().y + P1->getPosition().y) / 2.0f - 50);
		}

	}
}

void Stage::checkDeaths(Player* P1, Player* P2)
{

	if (P1 != nullptr && P1->checkDeath())
	{
		//list.remove(P1);
	}
	if (P2 != nullptr && P2->checkDeath())
	{
		list.remove(P2);
	}

	for (unsigned int i = 0; i < vEnemies.size(); i++)
	{
		if (vEnemies[i]->checkDeath())
		{
			list.remove(vEnemies[i]);
		}
	}
}

void Stage::exec(sf::RenderWindow& window, Player* P1, Player* P2)
{
	
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(512.0f, 512.0f));


	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
		{
			deltaTime = 1.0f / 20.0f;
		}


		sf::Event evento;
		while (window.pollEvent(evento))
		{
			switch (evento.type)
			{
			case sf::Event::Closed:

				window.close();
				break;
			}
		}


		list.update(deltaTime);
		
		manageCollisions(P1, P2, deltaTime);
		manageView(P1, P2, view, window);
		//checkDeaths(P1, P2);


		background.setPosition(view.getCenter().x - background.getSize().x / 2.0f,
		view.getCenter().y - background.getSize().y / 2.0f);
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			pause = new MenuPausa(window.getSize().x, window.getSize().y);
			pause->execPause((*pause), window, view);
		}
		
		window.clear(sf::Color(150, 150, 150));
		window.setView(view);
		window.draw(background);
		list.draw(window);
		window.display();

		if (P1 != nullptr && P1->getPosition().x > 2244.0f ||
			P2 != nullptr && P2->getPosition().x > 2244.0f)
		{
			return;
		}
	}

}

int Matheus::Stage::RandomPosition(int left, int right)
{

	unsigned seed = static_cast<int> (std::chrono::system_clock::now().time_since_epoch().count());
	std::mt19937 generator(seed);
	
	std::uniform_int_distribution<int> distribution(left, right);
	int number = distribution(generator);

	
	return number;
}

void Matheus::Stage::randomPlatformCreation()
{
	int numberOfPlatforms = 50 + (rand() % 26);
	int Pdone = 0;

	sf::Texture* Ptex = new sf::Texture;
	Ptex->loadFromFile("Platform.jpeg");
	TexList.push_back(Ptex);


	while(Pdone < numberOfPlatforms)
	{

		sf::Vector2f position;
		position.x = (float) RandomPosition(-2000, 2000);
		position.y = (float) RandomPosition(200, 460);

		sf::Texture* PTex = new sf::Texture;
		PTex->loadFromFile("Platform.jpeg");
		TexList.push_back(PTex);

		Platform* Plat = new Platform(PTex, sf::Vector2f(200.0f, 50.0f), position);
		
		for (unsigned int i = 0; i < vPlatforms.size(); i++)
		{
			Collider cP = Plat->getCollider();
			sf::Vector2f direction;
			if (vPlatforms[i]->getCollider().checkCollision(cP, direction, 1.0f))
			{
				Pdone--;
				break;
			}
			else
			{
				Pdone++;
			}

		}
		
		if (Plat != nullptr)
		{
			list.push(Plat);
			vPlatforms.push_back(Plat);
		}
	}




}

void Stage::randomEnemyCreation(sf::Vector2f groundSize)
{
	int EnemyANumber = (rand() % 5) + 5;
	int EnemyBNumber = (rand() % 2) + 5;
	
	sf::Texture* EnemyATex = new sf::Texture;
	sf::Texture* EnemyBTex = new sf::Texture;
	
	EnemyATex->loadFromFile("ini1.png");
	EnemyBTex->loadFromFile("ini2.png");

	TexList.push_back(EnemyATex);
	TexList.push_back(EnemyBTex);

	sf::Vector2f pos;
	
	for (int i = 0; i < EnemyANumber; i++)
	{
		pos.x = (float) RandomPosition(-2200, 2200);
		Enemy_A* En = new Enemy_A(EnemyATex, pos);
		list.push(En);
		vEnemies.push_back(En);
	}

	for (int i = 0; i < EnemyBNumber; i++)
	{
		pos.x = (float) RandomPosition(-2200, 2200);
		Enemy_B* En = new Enemy_B(EnemyBTex, pos);
		list.push(En);
		vEnemies.push_back(En);
	}

}

void Stage::randomObstacleCreation(sf::Vector2f groundSize)
{
	int ObstANumber = (rand() % 5) + 5;
	int ObstBNumber = (rand() % 5) + 5;
	int ObstCNumber = (rand() % 5) + 5;

	sf::Texture* ObATex= new sf::Texture;
	sf::Texture* ObBTex = new sf::Texture;
	sf::Texture* ObCTex = new sf::Texture;

	ObATex->loadFromFile("box.jpeg");
	ObBTex->loadFromFile("spikes.png");
	ObCTex->loadFromFile("trashCan.png");

	TexList.push_back(ObATex);
	TexList.push_back(ObBTex);
	TexList.push_back(ObCTex);

	sf::Vector2f pos;

	for (int i = 0; i < ObstANumber; i++)
	{
		pos.x = (float) RandomPosition(-2200, 2200);
		Obstacle_A* ob = new Obstacle_A(ObATex, pos);
		list.push(ob);
		vObstacles.push_back(ob);
	}
	for (int i = 0; i < ObstBNumber; i++)
	{
		pos.x = (float)RandomPosition(-2200, 2200);
		Obstacle_B* ob = new Obstacle_B(ObBTex, pos);
		list.push(ob);
		vObstacles.push_back(ob);
	}
	for (int i = 0; i < ObstCNumber; i++)
	{
		pos.x = (float) RandomPosition(-2200, 2200);
		Obstacle_C* ob = new Obstacle_C(ObCTex, pos);
		list.push(ob);
		vObstacles.push_back(ob);
	}


}
	
Stage::~Stage()
{
	list.~EntityList();
	TexList.clear();
	vEnemies.clear();
	vObstacles.clear();
	vPlatforms.clear();

}

