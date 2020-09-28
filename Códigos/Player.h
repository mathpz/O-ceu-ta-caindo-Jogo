#pragma once
#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "Collider.h"
#include "Personagem.h"
#include "MenuPausa.h"

namespace Matheus
{
	class Player : public Personagem
	{
	private:
		Animation animation;
		unsigned int row;
		unsigned int col;
		int id;
		float damageDelay;
	public:
		Player(sf::Texture* texture, sf::Vector2u imagecount, float switchTime);
		Player();
		~Player();
		void update(float deltaTime);
		void draw(sf::RenderWindow& window);
		sf::Vector2f getPosition();
		void getPlayerInput();
		void setId(int id);
		bool getInvencible() { return invencible; }
	};
}
