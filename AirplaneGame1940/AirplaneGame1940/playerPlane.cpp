#include "playerplane.h"

PlayerPlane::PlayerPlane() : Airplane::Airplane(1, 125,  300, 900, 60.0f)
{

}


PlayerPlane::PlayerPlane(float x, float y) : Airplane::Airplane(1, 125, x, y, 66.0f)
{

}

void PlayerPlane::draw(std::string img)
{
	graphics::Brush br;

	graphics::setOrientation(0);

	br.texture = "assets/planes/player" + img  + ".png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(x, y, width ,height, br);
}

void PlayerPlane::update(std::list <Projectile>  &projectileList , bool vol, float time)
{
	if (graphics::getKeyState(graphics::SCANCODE_W) || graphics::getKeyState(graphics::SCANCODE_UP))
		y -= velocity * graphics::getDeltaTime() / 333;
	if (graphics::getKeyState(graphics::SCANCODE_S) || graphics::getKeyState(graphics::SCANCODE_DOWN))
		y += velocity * graphics::getDeltaTime() / 333;
	if (graphics::getKeyState(graphics::SCANCODE_A) || graphics::getKeyState(graphics::SCANCODE_LEFT))
		x -= velocity * graphics::getDeltaTime() / 333;
	if (graphics::getKeyState(graphics::SCANCODE_D) || graphics::getKeyState(graphics::SCANCODE_RIGHT))
		x += velocity * graphics::getDeltaTime() / 333;

	borderCheck();

	if (graphics::getKeyState(graphics::SCANCODE_SPACE) && (time - lastShot > 100.0f))
	{
		graphics::playSound("assets/sound/shot.mp3", 0.33f * vol);
		lastShot = time;
		Projectile* arr1 = new Projectile(true, x - 15.0f, y - height);
		Projectile* arr2 = new Projectile(true, x + 15.0f, y - height);

		if (level == 2)
		{
			Projectile* arr3 = new Projectile(true, x - 30.0f, y - height);
			Projectile* arr4 = new Projectile(true, x + 30.0f, y - height);
			projectileList.push_back(*arr3);
			projectileList.push_back(*arr4);
			delete arr3;
			delete arr4;
			arr3 = nullptr;
			arr4 = nullptr;
		}
		projectileList.push_back(*arr1);
		projectileList.push_back(*arr2);
		delete arr1;
		delete arr2;
		arr1 = nullptr;
		arr2 = nullptr;
	}
}

bool PlayerPlane::borderCheck()
{
	if (x < 30)
		x = 30;
	else if(x > 570)
		x = 570;
	
	if (y < 150)
		y = 150;
	else if (y > 950)
		y = 950;

	return false;
}

bool PlayerPlane::isDestroyed(std::list <Projectile>& projectileList, std::list <EnemyPlane>& enemyList , std::list <Explosion>& expList, bool vol)
{
	std::list <Projectile> ::iterator iter;
	for (iter = projectileList.begin(); iter != projectileList.end(); ++iter)
	{
		float min_distance = iter->distanceToCorner() + getSize()- 10.0f;
		float distance = std::pow(iter->getX() - x, 2);
		distance += std::pow(iter->getY() - y, 2);
		distance = std::pow(distance, 0.5);
		if (!(iter->wasThrownByPlayer()) && min_distance > distance)
		{
			return true;
		}
	}

	std::list <EnemyPlane> ::iterator iter1;
	for (iter1 = enemyList.begin(); iter1 != enemyList.end(); ++iter1)
	{
		float min_distance = iter1->getSize() + getSize() - 20.0f;
		float distance = std::pow(iter1->getX() - x, 2);
		distance += std::pow(iter1->getY() - y, 2);
		distance = std::pow(distance, 0.5);
		if (min_distance > distance)
		{
			return true;
		}
	}

	return false;
}

bool PlayerPlane::upgrade(std::list <PowerUp>& upgradeList, bool vol)
{

	std::list <PowerUp> ::iterator iter;
	for (iter = upgradeList.begin(); iter != upgradeList.end(); ++iter)
	{
		float min_distance = iter->distanceToCorner() + distanceToCorner();
		float distance = std::pow(iter->getX() - x, 2);
		distance += std::pow(iter->getY() - y, 2);
		distance = std::pow(distance, 0.5);
		if (min_distance > distance)
		{
			iter = upgradeList.erase(iter);
			return true;
		}
	}
	return false;
}