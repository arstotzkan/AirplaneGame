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

	graphics::setOrientation(0);
	br.outline_opacity = 0.0f;
	br.fill_color[0] = 0.5f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	graphics::drawDisk(x, y, rad, br);
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

