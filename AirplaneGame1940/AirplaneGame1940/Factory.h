#pragma once

#include <iostream>
#include "graphics.h"
#include "entity.h"
#include "enemyplane.h"

class Factory : public EnemyPlane
{
public:
	Factory f = new EnemyPlane();

	void draw();
	void update(std::list <Projectile>& projectileList);
	bool borderCheck();
	virtual ~Factory() {}
};