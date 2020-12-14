#pragma once
#include "graphics.h"
#include "scancodes.h"
#include "airplane.h"
#include "projectile.h"
#include "enemyplane.h"
#include <list> 
#include <iterator>
#include <cmath>

class PlayerPlane : public Airplane
{
protected:
	int lives;
	float lastShot;
public:
	PlayerPlane();
	void draw();
	void update(std::list <Projectile> &projectileList);
	bool borderCheck();
	bool isDestroyed(std::list <Projectile>& projectileList, std::list <EnemyPlane>& enemyList);
	virtual ~PlayerPlane() {}


};
