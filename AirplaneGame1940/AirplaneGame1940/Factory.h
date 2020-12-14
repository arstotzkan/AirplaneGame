#pragma once

#include <iostream>
#include "enemyplane.h"
#include <list>

class Factory
{
protected:
	int counter;
	//bool firstWave;
public:
	Factory();
	void update(std::list <EnemyPlane>& enemyList);
	virtual ~Factory() {}
};