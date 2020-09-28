#include "Jogo.h"
#include <string>


Jogo::Jogo():
	window(sf::VideoMode(900, 600), "Ojogo", sf::Style::Close | sf::Style::Resize)
{
	menu = new Menu(900.0f, 600.0f);
	P1 = nullptr;
	P2 = nullptr;

}


Jogo::~Jogo()
{
	delete menu;
	menu = nullptr;
	delete stage;
	stage = nullptr;
	delete P1;
	P1 = nullptr;
	delete P2;
	P2 = nullptr;
}

void Jogo::executarMenu(sf::RenderWindow& window)
{	
	bool twoPlayers = false;

	while (window.isOpen())
	{
		sf::Event evento;
		while (window.pollEvent(evento))
		{
			switch (evento.type)
			{
			case::sf::Event::KeyReleased:
				switch (evento.key.code)
				{
				case sf::Keyboard::Up:
					menu->MoveUp();
					break;
				case sf::Keyboard::Down:
					menu->MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (menu->GetPressedItem())
					{
					case 0:
						cout << "Play precionado" << endl;
						menuFase(window, twoPlayers);
						break;
					case 1:
						cout << "Coop" << endl;
						twoPlayers = true;
						menuFase(window, twoPlayers);
						break;
					case 2:
						cout << "Rank " << endl;
						menuRank(window);
						break;
					case 3:
						cout << "Exit" << endl;
						window.close();
						break;
					}
				}
				break;
			}
		}
		window.clear();
		menu->draw(window);
		window.display();
	}
}

void Jogo::exec()
{
	executarMenu(window);
}

void Jogo::executarJogo(sf::RenderWindow& window, bool twoPlayers, int stageId)
	{
		sf::Texture* playerTexture = new sf::Texture;
		playerTexture->loadFromFile("galinhoAndando.png");

		P1 = new Player(playerTexture, sf::Vector2u(12, 1), 0.12f);
		P1->setId(1);



		if (twoPlayers)
		{
			//sf::Texture playerTexture;
			//playerTexture.loadFromFile("galinhoAndando.png");
			P2 = new Player(playerTexture, sf::Vector2u(12, 1), 0.12f);
			P2->setId(2);
		}

		if (stageId == 0)
		{
			stage = new Fase1(window, P1, P2);
			stage->exec(window, P1, P2);
			stage->~Stage();
			stageId++;
		}
		if (stageId == 1)
		{
			stage = new Stage2(window, P1, P2);
			stage->exec(window, P1, P2);
			stage->~Stage();
			stageId++;
		}
		if (stageId == 2)
		{
			stage = new stage3(window, P1, P2);
			stage->exec(window, P1, P2);
		}
	}

void Jogo::menuFase(sf::RenderWindow &window, bool twoPlayers)
{
	MenuFase menufase(window.getSize().x, window.getSize().y);
	while (window.isOpen())
	{
		sf::Event evento;
		while (window.pollEvent(evento))
		{
			switch (evento.type)
			{
			case::sf::Event::KeyReleased:
				switch (evento.key.code)
				{
				case sf::Keyboard::Up:
					menufase.MoveUp();
					break;
				case sf::Keyboard::Down:
					menufase.MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (menufase.GetPressedItem())
					{
					case 0:
						cout << "Fase 1" << endl;
						executarJogo(window, twoPlayers, 0);
						break;
					case 1:
						cout << "Fase 2" << endl;
						executarJogo(window, twoPlayers, 1);
						break;
					case 2:
						cout << "Fase 3 " << endl;
						executarJogo(window, twoPlayers, 2);
						break;
					case 3:
						cout << "Back " << endl;
						executarMenu(window);
						break;
					}
				}
				break;
			}
		}
		window.clear();
		menufase.draw(window);
		window.display();
	}
}

void Jogo::menuRank(sf::RenderWindow &window)
{
	MenuRank menurank(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event evento;
		while (window.pollEvent(evento))
		{
			switch (evento.type)
			{
			case::sf::Event::KeyReleased:
				switch (evento.key.code)
				{
				case sf::Keyboard::Up:
					menurank.MoveUp();
					break;
				case sf::Keyboard::Down:
					menurank.MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (menurank.GetPressedItem())
					{
					case 0:
						cout << "Play precionado" << endl;
						executarMenu(window);
						break;


					}
				}
				break;
			}
		}
		window.clear();
		menurank.draw(window);
		window.display();
	}
}

