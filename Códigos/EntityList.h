#pragma once
#include "Entidade.h"
#include "List.h"
#include "SFML/Graphics.hpp"
class EntityList
{

private:
	List<Entidade*> list;
	
public:
	EntityList();
	~EntityList();
	void push(Entidade* pEnt);
	Entidade* pop(Entidade* pEnt);
	void remove(Entidade* pEnt);
	void update(float dT); 
	void draw(sf::RenderWindow& window); 
};

