#pragma once
#include "graphics.h"
#include "scancodes.h"
#include "airplane.h"
#include "projectile.h"
#include "enemyplane.h"
#include "Explosion.h"
#include "PowerUp.h"
#include <list> 
#include <iterator>
#include <cmath>

class PlayerPlane : public Airplane
{

public:
	PlayerPlane();
	PlayerPlane(float x, float y);
	void draw();
	void update(std::list <Projectile> &projectileList, bool vol, float time);
	bool borderCheck();
	bool isDestroyed(std::list <Projectile>& projectileList, std::list <EnemyPlane>& enemyList, std::list <Explosion>& expList , bool vol);
	bool upgrade(std::list <PowerUp> & upgradeList, bool vol);

	void powerUp() { level++; };

	virtual ~PlayerPlane() {}


};
