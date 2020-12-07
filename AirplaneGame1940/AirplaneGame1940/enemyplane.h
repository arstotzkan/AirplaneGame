#pragma once
#include <list>

class EnemyPlane
{
public:
	float x;
	float y;
	float width;
	float height;
	int level;
	int healthPoints;

	EnemyPlane(int lvl);
	void draw();
	void update(std::list <Projectile>& projectileList);
	void borderCheck();
	virtual ~EnemyPlane() {}
};
