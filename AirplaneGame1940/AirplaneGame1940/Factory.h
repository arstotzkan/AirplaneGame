#pragma once

#include <iostream>
#include "enemyplane.h"
#include "PowerUp.h"
#include <list>

class Factory
{
protected:
	int counter;
	float lastSpawn;
	bool onlyOnce;
public:
	Factory();
	void update(std::list <EnemyPlane>& enemyList, std::list <PowerUp>& powerList);
	virtual ~Factory() {}
	int getCounter() { return counter; };
};