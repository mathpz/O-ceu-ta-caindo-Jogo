#pragma once
#include "entidade.h"
#include "Collider.h"
namespace Matheus
{
	class Obstacle : public Entidade
	{
	protected:
		sf::RectangleShape body;
		sf::Vector2f velocity;
		int id;

	public:
		Obstacle(sf::Vector2f size, sf::Vector2f position, sf::Texture* texture);
		Obstacle(sf::Vector2f size, sf::Texture* texture);
		Obstacle();
		~Obstacle();
		virtual void update(float dT);
		virtual void draw(sf::RenderWindow& window);
		virtual void OnCollison(sf::Vector2f direction);
		Collider getCollider();
		const int getId() const { return id; }
		void setId(const int id) { this->id = id; }
	};
}
using namespace Matheus;