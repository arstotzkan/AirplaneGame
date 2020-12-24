#include "enemyplane.h"
#include <string>

float levelToSize(int l)
{
	const float size[5] = { 35, 50, 40 , 75, 100 };
	return size[l - 1];
}


EnemyPlane::EnemyPlane(int lvl, float  x , float y ) : Airplane(lvl , 66 , x , y, levelToSize(lvl))
{
	healthPoints = lvl * 2;
}

void EnemyPlane::draw()
{
	graphics::Brush br;
	if (level == 1 || level == 2 || level == 4)
		graphics::setOrientation(180);
	else if (level == 3)
		graphics::setOrientation(270);

	std::string img = "assets/planes/enemy" + std::to_string(level) + ".png";
	br.texture = img;
	br.outline_opacity = 0.0f;

	graphics::drawRect(x, y, width, height, br);

	graphics::setOrientation(0);

}

void EnemyPlane::update(std::list <Projectile>& projectileList,bool vol)
{
	int r = rand();
	switch (level)
	{
		case 1:
		{
			y += velocity * graphics::getDeltaTime() / 300;
			break;
		}
		case 2:
		{
			y += velocity * graphics::getDeltaTime() / 333;
			if (r % 350 == 1 && (graphics::getGlobalTime() - lastShot > 100.0f))
			{
				graphics::playSound("assets/sound/shot.mp3", 0.33f * vol);
				Projectile* arr = new Projectile(false, x, y + height);
				projectileList.push_back(*arr);
				delete arr;
				arr = nullptr;
				lastShot = graphics::getGlobalTime();
			}
			break;
		}
		case 3:
		{
			x += velocity * graphics::getDeltaTime() / 333;
			break;
		}
		case 4:
		{
			y += velocity * graphics::getDeltaTime() / 400;
			if (r % 250 == 1 && (graphics::getGlobalTime() - lastShot > 150.0f) )
			{
				graphics::playSound("assets/sound/shot.mp3", 0.33f * vol);
				Projectile* arr = new Projectile(false, x, y + height);
				projectileList.push_back(*arr);
				delete arr;
				arr = nullptr;
				lastShot = graphics::getGlobalTime();
			}
			break;
		}
		case 5:
		{
			y -= velocity * graphics::getDeltaTime() / 500;
			if (r % 250 == 1 && (graphics::getGlobalTime() - lastShot > 150.0f) )
			{
				graphics::playSound("assets/sound/shot.mp3", 0.33f * vol);
				Projectile* arr = new Projectile(false, x, y + height);
				Projectile* arr1 = new Projectile(false, x + 20 , y + height);
				Projectile* arr2 = new Projectile(false, x - 20, y + height);
				projectileList.push_back(*arr);
				projectileList.push_back(*arr1);
				projectileList.push_back(*arr2);
				delete arr;
				delete arr1;
				delete arr2;
				arr = nullptr;
				arr1 = nullptr;
				arr2 = nullptr;
				lastShot = graphics::getGlobalTime();
			}
			break;
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
			break;
		}
		case 2:
		{
			if (y > 1000)
				return true;
			else
				return false;
			break;
		}
		case 3:
		{
			if (x > 600)
				return true;
			else
				return false;
			break;
		}
		case 4:
		{
			if (y > 1000)
				return true;
			else
				return false;
			break;
		}
		case 5:
		{
			if (y < 0)
				return true;
			else
				return false;
			break;
		}
	}
}

bool EnemyPlane::isDestroyed(std::list <Projectile>& projectileList, std::list <Explosion>& expList, bool vol)
{
	std::list <Projectile> ::iterator iter;
	for (iter = projectileList.begin(); iter != projectileList.end();)
	{
		float min_distance = iter->distanceToCorner() + getSize();
		float distance = std::pow(iter->getX() - x, 2);
		distance += std::pow(iter->getY() - y, 2);
		distance = std::pow(distance, 0.5);
		if (iter->wasThrownByPlayer() && min_distance > distance && y >= 100 )
		{
			iter = projectileList.erase(iter);
			healthPoints = healthPoints - 1;
			if (healthPoints == 0)
			{
				Explosion* temp = new Explosion(x, y);
				expList.push_back(*temp);
				graphics::playSound("assets/sound/explosion.mp3", 0.33f * vol);
				delete temp;
				temp = nullptr;

				return true;
			}

			else
				++iter;
		}

		else
			++iter;
	}

	return false;
}