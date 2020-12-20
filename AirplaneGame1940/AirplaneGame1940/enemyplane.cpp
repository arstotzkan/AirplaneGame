#include "enemyplane.h"
#include <string>

EnemyPlane::EnemyPlane(int lvl, float  x , float y ) : Airplane(lvl , 66 , x , y)
{
	healthPoints = 1;
}

void EnemyPlane::draw()
{
	graphics::Brush br;
	graphics::setOrientation(0);

	std::string img = "assets/plane" + std::to_string(level) + ".png";
	br.texture = img;
	br.outline_opacity = 0.0f;
	graphics::drawRect(x, y, width, height, br);

}

void EnemyPlane::update(std::list <Projectile>& projectileList)
{
	y += velocity * graphics::getDeltaTime() / 333;

	borderCheck();
}

bool EnemyPlane::borderCheck()
{
	if (x > 1000)
		return true;
	else
		return false;
}

bool EnemyPlane::isDestroyed(std::list <Projectile>& projectileList, std::list <Explosion>& expList)
{
	std::list <Projectile> ::iterator iter;
	for (iter = projectileList.begin(); iter != projectileList.end(); ++iter)
	{
		float min_distance = iter->distanceToCorner() + distanceToCorner();
		float distance = std::pow(iter->getX() - x, 2);
		distance += std::pow(iter->getY() - y, 2);
		distance = std::pow(distance, 0.5);
		if (iter->wasThrownByPlayer() && min_distance > distance && y >= 100 )
		{
			Explosion* temp = new Explosion(x, y);
			expList.push_back(*temp);
			delete temp;
			temp = nullptr;

			projectileList.erase(iter);
			healthPoints = healthPoints - 1;
			if (healthPoints == 0)
				return true;
		}
	}

	return false;
}