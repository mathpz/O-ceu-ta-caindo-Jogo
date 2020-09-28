
#include "Menu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{

	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width - 175, height / (MAX_NUMBER_OF_ITENS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString("Co-op");
	menu[1].setPosition(sf::Vector2f(width - 175, height / (MAX_NUMBER_OF_ITENS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Black);
	menu[2].setString("ranking");
	menu[2].setPosition(sf::Vector2f(width - 175, height / (MAX_NUMBER_OF_ITENS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::Black);
	menu[3].setString("Exit");
	menu[3].setPosition(sf::Vector2f(width - 175, height / (MAX_NUMBER_OF_ITENS + 1) * 4));

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}
void  Menu::draw(sf::RenderWindow &window)
{
	sf::RectangleShape fundo(sf::Vector2f(900, 600));
	sf::Texture fundoTexture;
	fundoTexture.loadFromFile("menu.jpg");
	fundo.setTexture(&fundoTexture);

	window.draw(fundo);
	for (int i = 0; i < MAX_NUMBER_OF_ITENS; i++)
	{
		
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}
void Menu :: MoveDown()
{
	if (selectedItemIndex + 1 <  MAX_NUMBER_OF_ITENS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}

void Menu::update()
{
}


