#include "EntityList.h"
#include <iostream>


EntityList::EntityList()
{
}


EntityList::~EntityList()
{
}

void EntityList::push(Entidade *pEnt)
{
	list.push(pEnt);
}

Entidade * EntityList::pop(Entidade * pEnt)
{
	return list.pop(pEnt);
}

void EntityList::remove(Entidade * pEnt)
{
	list.remove(pEnt);
}

void EntityList::update(float dT)
{
	for (int i = 0; i < list.getSize(); i++)
	{
			list.getElement(i)->update(dT);
	}
}

void EntityList::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < list.getSize(); i++)
	{
			list.getElement(i)->draw(window);
	}
}





