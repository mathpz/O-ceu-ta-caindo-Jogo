#pragma once
#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_FASES 4


class MenuFase
{
public:
	MenuFase(float width, float height);
	~MenuFase();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menuFase[MAX_NUMBER_OF_FASES];
};