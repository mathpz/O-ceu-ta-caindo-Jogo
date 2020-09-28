#include "MenuPausa.h"

MenuPausa::MenuPausa(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
	}
	int i;
	for (i = 0; i < MAX_NUMBER_PAUSE; i++)
	{
		menupausa[i].setFont(font);
		menupausa[i].setFillColor(sf::Color::Black);
		menupausa[i].setPosition(sf::Vector2f(width - 200, height / (MAX_NUMBER_PAUSE + 1) * (1+i)));
	}	
	menupausa[0].setFillColor(sf::Color::Red);
	menupausa[0].setString("Resume");
	menupausa[1].setString("Back to Menu");
	menupausa[2].setString(" Save Game");
	menupausa[3].setString("Exit");
	

	selectedItemIndex = 0;
}

MenuPausa::MenuPausa()
{
}

MenuPausa::~MenuPausa()
{
}
void  MenuPausa::draw(sf::RenderWindow &window)
{
	sf::RectangleShape fundo(sf::Vector2f(900, 600));
	sf::Texture fundoTexture;
	fundoTexture.loadFromFile("backgroundmenu.png");
	fundo.setTexture(&fundoTexture);

	window.draw(fundo);
	for (int i = 0; i < MAX_NUMBER_PAUSE; i++)
	{

		window.draw(menupausa[i]);
	}
}

void MenuPausa::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menupausa[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex--;
		menupausa[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}
void MenuPausa::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_PAUSE)
	{
		menupausa[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex++;
		menupausa[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}
/*/*/
void MenuPausa::salvaJogo(bool doisJog, sf::Vector2f posicao, int score, int vidas, string nome)
{
	ofstream gravaJogo("save 1.dat", ios::out);
	gravaJogo << doisJog << ' '
		<< posicao.x << ' '
		<< posicao.y << ' '
		<< score << ' '
		<< vidas << ' '
		<< nome << endl;

	gravaJogo.close();

}
void MenuPausa::execPause(MenuPausa menupausa, sf::RenderWindow& window,sf::View& view)
{
	view.setSize(900.0f, 600.0f);
	view.setCenter(window.getSize().x / 2, window.getSize().y / 2);
	window.setView(view);
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
					menupausa.MoveUp();
					break;
				case sf::Keyboard::Down:
					menupausa.MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (menupausa.GetPressedItem())
					{
					case 0:
						cout << "Resume pressionado" << endl;
						view.setSize(512.0f, 512.0f);
						return;
						break;
					case 1:
						cout << "back to menu pressionado" << endl;
						//menuprincipal(window); 
						break;
					case 2:
						//salvaJogo( 0 , pegaposicao , socore , vida , nome);
						break;
					case 3:
						cout << "Exit pressionado " << endl;
						window.close();
						break;
					}
					break;
				}
				break;
			}
		}
		window.clear();
		menupausa.draw(window);
		window.display();

	}
}