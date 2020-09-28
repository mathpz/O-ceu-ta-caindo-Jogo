#pragma once
#include <fstream>
#include <iostream>
#include <SFML\Graphics.hpp>
#include <string>
using namespace std;

#define MAX_NUMBER_PAUSE 4
class MenuPausa 
{
public:
	MenuPausa(float width, float height);
	MenuPausa();
	~MenuPausa();
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	/*/*/
	void execPause(MenuPausa menupausa , sf::RenderWindow& window, sf::View& view);
	void salvaJogo(bool doisJog, sf::Vector2f posicao, int score, int vidas, string nome);
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menupausa[MAX_NUMBER_PAUSE];
};

