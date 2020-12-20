#pragma once

#include <iostream>
#include "graphics.h"
#include "entity.h"
//#include "enemyplane.h"
//#include "playerplane.h"
#include <list>
#include <iterator>

class Projectile : public Entity
{
protected:
	bool thrownByPlayer;
public:
	Projectile(bool thrownBy, float x, float y);
	void draw();
	void update();
	bool borderCheck();
	bool wasThrownByPlayer();
	//bool isDestroyed(std::list <EnemyPlane>& enemyList, PlayerPlane *pp);
	virtual ~Projectile() {};
};
