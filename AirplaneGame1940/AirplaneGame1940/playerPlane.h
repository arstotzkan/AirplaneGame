#pragma once
#include "graphics.h"
#include "scancodes.h"
#include "airplane.h"
#include "projectile.h"
#include "enemyplane.h"
#include "Explosion.h"
#include <list> 
#include <iterator>
#include <cmath>

class PlayerPlane : public Airplane
{
protected:
	int lifes;
	float lastShot;
public:
	PlayerPlane();
	void draw();
	int getLifes() { return lifes; };
	void removeLife() { lifes--;};
	void update(std::list <Projectile> &projectileList);
	bool borderCheck();
	bool isDestroyed(std::list <Projectile>& projectileList, std::list <EnemyPlane>& enemyList, std::list <Explosion>& expList );
	virtual ~PlayerPlane() {}


};
