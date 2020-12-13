#include "Factory.h"
#include "graphics.h"
#include "entity.h"
#include "enemyplane.h"
#include <iostream>
#include <list>

Factory::Factory()
{
	counter = 0;
}

void Factory::update(std::list <EnemyPlane> &enemyList)
{
	if (counter % 10000 == 1500)
	{
		EnemyPlane* a1 = new EnemyPlane(1, 100, 100);
		EnemyPlane* a2 = new EnemyPlane(1, 250, 100);
		EnemyPlane* a3 = new EnemyPlane(1, 400, 100);
		enemyList.push_back(*a1);
		enemyList.push_back(*a2);
		enemyList.push_back(*a3);
		delete a1;
		delete a2;
		delete a3;
	}
	counter++;
}


