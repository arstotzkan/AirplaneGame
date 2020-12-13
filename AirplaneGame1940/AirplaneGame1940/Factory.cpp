#include "Factory.h"
#include "graphics.h"
#include "entity.h"

Factory::Factory()
{
}

void Factory::update(std::list <EnemyPlane> &enemyList, float time)
{
	if (fmod(time, 5000.0f) == 1000.0f)
	{
		EnemyPlane* a1 = new EnemyPlane(1, 100, 0);
		EnemyPlane* a2 = new EnemyPlane(1, 250, 0);
		EnemyPlane* a3 = new EnemyPlane(1, 400, 0);
		enemyList.push_back(*a1);
		enemyList.push_back(*a2);
		enemyList.push_back(*a3);
		delete a1;
		delete a2;
		delete a3;
	}

}


