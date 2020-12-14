#pragma once
#include <list>
#include "airplane.h"
#include "projectile.h"
#include <list> 
#include <iterator> 
#include "graphics.h"

class EnemyPlane : public Airplane
{
protected:
	int healthPoints;
public:
	EnemyPlane(int lvl, float x , float y);
	void draw();
	void update(std::list <Projectile>& projectileList);
	bool borderCheck();
	bool isDestroyed(std::list <Projectile>& projectileList);
	virtual ~EnemyPlane() {}
};
