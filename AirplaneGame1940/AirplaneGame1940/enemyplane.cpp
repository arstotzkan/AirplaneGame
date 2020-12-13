#include "entity.h"
#include "graphics.h"
#include "scancodes.h"
#include "enemyplane.h"
#include <list> 
#include <iterator> 


EnemyPlane::EnemyPlane(int lvl) : Airplane(lvl)
{
	healthPoints = 2;
}

void EnemyPlane::draw()
{
	graphics::Brush br;

	br.texture = "plane2.png";
	br.outline_width = 0.0f;
	graphics::drawRect(x, y, width, height, br);
}

void EnemyPlane::update(std::list <Projectile>& projectileList)
{
	y += 5;

	borderCheck();
}

bool EnemyPlane::borderCheck()
{
	if (x < 0)
		return true;
	else
		return false;
}

