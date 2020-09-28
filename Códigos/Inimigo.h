#pragma once
#include "Personagem.h"
#include "Animation.h"
#include "Collider.h"
#include "SFML/Graphics.hpp"
#include "Platform.h"
#include <iostream>
namespace Matheus
{
	class Inimigo : public Personagem
	{
	private:
		float speed;
	protected:
		int row;
		Animation animation;
		float distance;

	public:
		Inimigo(sf::Texture* tex, sf::Vector2u imagecount, float switchTime);
		Inimigo();
		~Inimigo();
		void update(float dT);
		void draw(sf::RenderWindow& window);


	};
}
using namespace Matheus;