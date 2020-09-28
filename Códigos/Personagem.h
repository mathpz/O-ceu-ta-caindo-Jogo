#pragma once
#include "Entidade.h"
#include "Collider.h"
#include "SFML/Graphics.hpp"
namespace Matheus
{
	class Personagem : public Entidade
	{
	protected:
		sf::RectangleShape body;
		sf::Vector2f velocity;
		float speed;
		bool faceright;
		bool gotHit;
		int hitPoints;
		bool invencible;
	private:
		sf::Texture* tex;
		float jumpHeight;
		bool canJump;

	public:
		Personagem(sf::Vector2f size, sf::Texture* tex);
		Personagem();
		~Personagem();
		sf::RectangleShape& getBody();
		Collider getCollider();
		virtual void update(float dT);
		sf::Vector2f& getVelocity();
		void setVelocity(sf::Vector2f velocity);
		float getSpeed();
		void setJumpHeight(float jumpHeight);
		float getJumpHeight();
		bool getFacingSide() { return faceright; }
		bool getCanJump();
		void setCanJump(bool canJump);
		virtual void draw(sf::RenderWindow& window);
		bool checkDeath();
		bool checkHit();
		virtual void getHit();
		void OnCollision(sf::Vector2f direction);
		void OnCollisionWithObstacle(sf::Vector2f direction);
		void OnCollisionWithEnemy(sf::Vector2f direction, float dT);
		void setHp(const int hp);
		void setSpeed(const float speed);
	};
}
using namespace Matheus;