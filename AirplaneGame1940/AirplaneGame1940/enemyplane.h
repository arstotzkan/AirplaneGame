#pragma once
#include <list>
#include "airplane.h"
#include "projectile.h"

class EnemyPlane : public Airplane
{
public:

	int healthPoints;

	EnemyPlane(int lvl, float x , float y);
	void draw();
	void update(std::list <Projectile>& projectileList);
	bool borderCheck();
	bool collisionCheck(std::list <Projectile>& projectileList);
	virtual ~EnemyPlane() {}
};
