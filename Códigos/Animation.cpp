#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;
	
	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::update(int row, int col, float deltaTime, bool faceright)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= col)
		{
			currentImage.x = 0;
		}
	}
	
	uvRect.top = currentImage.y * uvRect.height;

	if (faceright)
	{
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}

}

void Animation::switchTex(sf::Texture * tex, sf::Vector2u imageCount, float switchTime)
{
	this->switchTime = switchTime;
	this->imageCount = imageCount;

	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = tex->getSize().x / float(imageCount.x);
	uvRect.height = tex->getSize().y / float(imageCount.y);
}
