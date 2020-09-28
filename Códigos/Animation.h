#pragma once
#include "SFML/Graphics.hpp"
namespace Matheus
{
	class Animation
	{
	private:
		sf::Vector2u imageCount;
		sf::Vector2u currentImage;
		float totalTime;
		float switchTime;

	public:
		sf::IntRect uvRect;
	public:
		Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
		Animation();
		~Animation();
		void update(int row, int col, float deltaTime, bool faceright);
		void switchTex(sf::Texture* tex, sf::Vector2u imageCount, float switchTime);


	};
}
using namespace Matheus;