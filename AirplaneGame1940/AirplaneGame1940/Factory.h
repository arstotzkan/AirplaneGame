#pragma once

#include <iostream>
#include "graphics.h"
#include "entity.h"
#include "enemyplane.h"

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