#include "enemyplane.h"
#include <string>

EnemyPlane::EnemyPlane(int lvl, float  x , float y ) : Airplane(lvl , 66 , x , y)
{
	healthPoints = 1;
}

void EnemyPlane::draw()
{
	graphics::Brush br;
	if (level == 1 || level == 2 || level == 4)
		graphics::setOrientation(90);
	else if (level == 5)
		graphics::setOrientation(0);

	std::string img = "assets/planes/enemy" + std::to_string(level) + ".png";
	br.texture = img;
	br.outline_opacity = 0.0f;

	graphics::drawRect(x, y, width, height, br);

}

void EnemyPlane::update(std::list <Projectile>& projectileList)
{
	switch (level)
	{
		case 1:
		{
			y += velocity * graphics::getDeltaTime() / 300;
		}
		case 2:
		{
			y += velocity * graphics::getDeltaTime() / 333;
		}
		case 3:
		{
			x += velocity * graphics::getDeltaTime() / 333;
		}
		case 4:
		{
			y += velocity * graphics::getDeltaTime() / 400;
		}
		case 5:
		{
			y -= velocity * graphics::getDeltaTime() / 500;
		}
	}
	borderCheck();
}

bool EnemyPlane::borderCheck()
{

	switch (level)
	{
		case 1:
		{
			if (y > 1000)
				return true;
			else
				return false;
		}
		case 2:
		{
			if (y > 1000)
				return true;
			else
				return false;
		}
		case 3:
		{
			if (x < 0)
				return true;
			else
				return false;
		}
		case 4:
		{
			if (y > 1000)
				return true;
			else
				return false;
		}
		case 5:
		{
			if (y < 0)
				return true;
			else
				return false;
		}
	}
}

bool EnemyPlane::isDestroyed(std::list <Projectile>& projectileList, std::list <Explosion>& expList, bool vol)
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
			graphics::playSound("assets/sound/explosion.mp3", 0.33f * vol);
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