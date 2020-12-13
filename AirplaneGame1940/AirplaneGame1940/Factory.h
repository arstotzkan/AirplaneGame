#pragma once

#include <iostream>
#include "graphics.h"
#include "entity.h"
#include "enemyplane.h"

class Factory
{
protected:
	int counter;
public:
	Factory();
	void update(std::list <EnemyPlane>& enemyList , float time);
	virtual ~Factory() {}
};