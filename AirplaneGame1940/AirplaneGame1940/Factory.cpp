#include "Factory.h"


Factory::Factory()
{
	counter = 0;

}

void Factory::update(std::list <EnemyPlane> &enemyList)
{
	if (counter % 2000 == 1000)
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
		a1 = nullptr;
		a2 = nullptr;
		a3 = nullptr;
	}
	counter++;
}


