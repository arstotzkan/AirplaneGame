#pragma once
#include <list>
#include "airplane.h"
#include "projectile.h"

class EnemyPlane : public Airplane
{
public:

	int healthPoints;

	EnemyPlane(int lvl);
	void draw();
	void update(std::list <Projectile>& projectileList);
	bool borderCheck();
	virtual ~EnemyPlane() {}
};
