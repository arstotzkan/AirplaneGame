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
	if (lvl > 1)
		lead->powerUp();

	left = new PlayerPlane(lead->getX() - 80 , lead->getY());
	right = new PlayerPlane(lead->getX() + 80, lead->getY());
	level = lvl;
	leftExists = false;
	rightExists = false;
}

void PlayerSquadron::draw()
{
	lead->draw("0");
	if (leftExists)
		left->draw("1");
	if (rightExists)
		right->draw("1");
}

void PlayerSquadron::update(std::list <Projectile>& projectileList, std::list <PowerUp> &upgradeList,  bool vol, float time)
{
	upgrade(upgradeList, vol);
	lead->update(projectileList, vol, time);

	if (leftExists)
		left->update(projectileList, vol, time);
	if (rightExists)
		right->update(projectileList, vol, time);

	borderCheck();

}

void PlayerSquadron::borderCheck()
{
	//if there are three planes

	if (right->getX() >= 570 && rightExists)
	{
		lead->setX(500.0f);
		if (leftExists)
			left->setX(430.0f);
	}

	
	if (left->getX() <= 30 && leftExists)
	{
		lead->setX(100.0f);
		if (rightExists)
			right->setX(170.0f);
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
	{
		rightExists = false;
		right->setLevel(1);

		Explosion* temp = new Explosion(right->getX(), right->getY(), right->getSize() );
		expList.push_back(*temp);
		graphics::playSound("assets/sound/explosion.mp3", 0.33f * vol);
		delete temp;
		temp = nullptr;
	}

	if (leftExists && left->isDestroyed(projectileList, enemyList, expList, vol))
	{
		leftExists = false;
		left->setLevel(1);

		Explosion* temp = new Explosion(left->getX(), left->getY(), left->getSize());
		expList.push_back(*temp);
		graphics::playSound("assets/sound/explosion.mp3", 0.33f * vol);
		delete temp;
		temp = nullptr;
	}

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
				left->setX(lead->getX() - 70);
				left->setY(lead->getY());

				leftExists = true;

				right->setX(lead->getX() + 70);
				right->setY(lead->getY());

				rightExists = true;
				break;
			}

			case 3:
			{
				std::list <PlayerPlane> ::iterator it;

				if (rightExists)
					left->powerUp();
				if(leftExists)
					right->powerUp();
				break;
			}

			case 4:
			{
				if (!leftExists)
				{
					left->setX(lead->getX() - 70);
					left->setY(lead->getY());
					left->powerUp();
					leftExists = true;
				}
				
				if (!rightExists)
				{
					right->setX(lead->getX() + 70);
					right->setY(lead->getY());
					right->powerUp();
					rightExists =  true;
				}
				break;
			}


		}

		level++;
	}

}

void PlayerSquadron::setY(float new_y)
{
	lead->setY(new_y);

	if (leftExists)
		left->setY(new_y);
	
	if (rightExists)
		right->setY(new_y);
}

void PlayerSquadron::setX(float new_x)
{
	lead->setX(new_x);

	if (leftExists)
		left->setX(new_x- 70);

	if (rightExists)
		right->setX(new_x + 70);
}

PlayerSquadron::~PlayerSquadron() 
{ 
	delete lead;
	delete right;
	delete left;
};