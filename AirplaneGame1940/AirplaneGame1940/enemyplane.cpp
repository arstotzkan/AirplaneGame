#include "entity.h"
#include "graphics.h"
#include "scancodes.h"
#include "enemyplane.h"
#include <list> 
#include <iterator> 


EnemyPlane::EnemyPlane(int lvl) : Airplane(lvl)
{

}

void EnemyPlane::draw()
{

}

void EnemyPlane::update(std::list <Projectile>& projectileList)
{

}

bool EnemyPlane::borderCheck()
{
	if (x < 0)
		return true;
	else
		return false;
}

