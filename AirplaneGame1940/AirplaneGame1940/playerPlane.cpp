#include "playerplane.h"



PlayerPlane::PlayerPlane() : Airplane::Airplane(1, 125,  250, 800)
{
	lives = 3;
	lastShot = 0.0f;
}

void PlayerPlane::draw()
{
	graphics::Brush br;

	graphics::setOrientation(0);

	br.texture = "assets/plane1.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(x, y, width ,height, br);
}

void PlayerPlane::update(std::list <Projectile>  &projectileList)
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

	if (graphics::getKeyState(graphics::SCANCODE_SPACE) && (graphics::getGlobalTime() - lastShot > 100.0f ) )
	{
		lastShot = graphics::getGlobalTime();
		Projectile* arr = new Projectile(true, x , y - height);
		projectileList.push_back(*arr);
		//delete arr;
	}
}

bool PlayerPlane::borderCheck()
{
	if (x < 50)
		x = 50;
	else if(x > 450)
		x = 450;
	
	if (y < 50)
		y = 50;
	else if (y > 850)
		y = 850;

	return false;
}

bool PlayerPlane::isDestroyed(std::list <Projectile>& projectileList, std::list <EnemyPlane>& enemyList)
{
	std::list <Projectile> ::iterator iter;
	for (iter = projectileList.begin(); iter != projectileList.end(); ++iter)
	{
		float min_distance = iter->distanceToCorner() + distanceToCorner();
		float distance = std::pow(iter->getX() - x, 2);
		distance += std::pow(iter->getY() - y, 2);
		distance = std::pow(distance, 0.5);
		if (!(iter->wasThrownByPlayer()) && min_distance > distance)
			return true;

	}

	std::list <EnemyPlane> ::iterator iter1;
	for (iter1 = enemyList.begin(); iter1 != enemyList.end(); ++iter1)
	{
		float min_distance = iter1->distanceToCorner() + distanceToCorner();
		float distance = std::pow(iter1->getX() - x, 2);
		distance += std::pow(iter1->getY() - y, 2);
		distance = std::pow(distance, 0.5);
		if (min_distance > distance)
			return true;
	}

	return false;
}