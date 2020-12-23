#include "playerSquadron.h"

PlayerSquadron::PlayerSquadron()
{
	lead = new PlayerPlane();
	left = new PlayerPlane();
	right = new PlayerPlane();
	level = 1;
	leftExists = false;
	rightExists = false;

}

PlayerSquadron::PlayerSquadron(int lvl)
{
	lead = new PlayerPlane();
	left = new PlayerPlane(lead->getX() - 80 , lead->getY());
	right = new PlayerPlane(lead->getX() + 80, lead->getY());
	level = lvl;
	leftExists = false;
	rightExists = false;
}

void PlayerSquadron::draw()
{
	lead->draw();
	if (leftExists)
		left->draw();
	if (rightExists)
		right->draw();
}

void PlayerSquadron::update(std::list <Projectile>& projectileList, std::list <PowerUp> &upgradeList,  bool vol)
{

	lead->update(projectileList, vol);

	if (leftExists)
		left->update(projectileList, vol);
	if (rightExists)
		right->update(projectileList, vol);

	borderCheck();

	upgrade(upgradeList, vol);


}

void PlayerSquadron::borderCheck()
{
	//if there are three planes

	if (right->getX() >= 570 && rightExists)
	{
		lead->setX(490.0f);
		if (leftExists)
			left->setX(410.0f);
	}

	
	if (left->getX() <= 30 && leftExists)
	{
		lead->setX(110.0f);
		if (rightExists)
			right->setX(190.0f);
	}

	//if there are only two planes
	if (lead->getX() >= 570 && leftExists)
	{
		left->setX(490.0f);
	}

	if (lead->getX() <= 30 && rightExists)
	{
		right->setX(110.0f);
	}

}


bool PlayerSquadron::isDestroyed(std::list <Projectile>& projectileList, std::list <EnemyPlane>& enemyList, std::list <Explosion>& expList, bool vol)
{
	std::list <PlayerPlane> ::iterator it;

	if (rightExists && right->isDestroyed(projectileList, enemyList, expList, vol))
		rightExists = false;

	if (leftExists && left->isDestroyed(projectileList, enemyList, expList, vol))
		leftExists = false;
	

	if (!rightExists && !leftExists && level > 2)
		level = 2;

	if (lead->isDestroyed(projectileList, enemyList, expList, vol))
		return true;

	return false;

}

void PlayerSquadron::upgrade(std::list <PowerUp>& upgradeList, bool vol)
{
	bool flag = false;

	if (lead->upgrade(upgradeList, vol))
		flag = true;

	std::list <PlayerPlane> ::iterator it;

	if (leftExists)
		left->upgrade(upgradeList, vol);
	
	if (rightExists)
		right->upgrade(upgradeList, vol);


	if (flag)
	{
		graphics::playSound("assets/sound/upgrade.mp3", 0.2f * vol);
		switch (level)
		{
			case 1:
			{
				lead->powerUp();
				break;
			}

			case 2:
			{
				left->setX(lead->getX() - 80);
				left->setY(lead->getY());

				leftExists = true;

				right->setX(lead->getX() + 80);
				right->setY(lead->getY());

				rightExists = true;
				break;
			}

			case 3:
			{
				std::list <PlayerPlane> ::iterator it;

				left->powerUp();
				right->powerUp();
				break;
			}

		}

		if (level < 4)
			level++;
	}

}

PlayerSquadron::~PlayerSquadron() 
{ 
	delete lead;
	delete right;
	delete left;
};