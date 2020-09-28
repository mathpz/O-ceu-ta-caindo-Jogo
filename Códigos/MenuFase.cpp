#include "MenuFase.h"


MenuFase::MenuFase(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
	}
	int i;
	for (i = 0; i < MAX_NUMBER_OF_FASES; i++)
	{
		menuFase[i].setFont(font);
		menuFase[i].setFillColor(sf::Color::Black);
		menuFase[i].setPosition(sf::Vector2f(width - 200, height / (MAX_NUMBER_OF_FASES + 1) * (i + 1)));
	}
	menuFase[0].setFillColor(sf::Color::Red);
	menuFase[0].setString("Fase 1");
	menuFase[1].setString("Fase 2");
	menuFase[2].setString("Fase 3");
	menuFase[3].setString("Back");

	selectedItemIndex = 0;
}



MenuFase::~MenuFase()
{
}
void  MenuFase::draw(sf::RenderWindow &window)
{
	sf::RectangleShape fundo(sf::Vector2f(900, 600));
	sf::Texture fundoTexture;
	fundoTexture.loadFromFile("menufase.png");
	fundo.setTexture(&fundoTexture);

	window.draw(fundo);
	for (int i = 0; i < MAX_NUMBER_OF_FASES; i++)
	{

		window.draw(menuFase[i]);
	}
}

void MenuFase::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menuFase[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex--;
		menuFase[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}
void MenuFase::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_FASES)
	{
		menuFase[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex++;
		menuFase[selectedItemIndex].setFillColor(sf::Color::Red);

	}
}