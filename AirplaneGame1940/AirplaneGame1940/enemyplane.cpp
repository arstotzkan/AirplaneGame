#include "entity.h"
#include "graphics.h"
#include "scancodes.h"
#include "enemyplane.h"
#include <list> 
#include <iterator> 


EnemyPlane::EnemyPlane(int lvl, float  x , float y ) : Airplane(lvl , x , y)
{
	healthPoints = 2;
}

void EnemyPlane::draw()
{
	graphics::Brush br;
	graphics::setOrientation(0);

	br.texture = "plane2.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(x, y, width, height, br);
}

void EnemyPlane::update(std::list <Projectile>& projectileList)
{
	y += 5;

	borderCheck();
}

bool EnemyPlane::borderCheck()
{
	if (x > 900)
		return true;
	else
		return false;
}

bool EnemyPlane::collisionCheck(std::list <Projectile>& projectileList)
{
	std::list <Projectile> ::iterator iter;
	for (iter = projectileList.begin(); iter != projectileList.end(); ++iter)
	{
		float min_distance = iter->distanceToCorner() + distanceToCorner();
		float distance = std::pow(iter->getX() - x, 2);
		distance += std::pow(iter->getY() - y, 2);
		distance = std::pow(distance, 0.5);
		if (!(iter->wasThrownByPlayer()) && min_distance > distance)
		{
			healthPoints = healthPoints - 1;
			if (healthPoints == 0)
				return true;
		}
	}

	return false;
}