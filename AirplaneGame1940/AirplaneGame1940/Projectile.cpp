#include "projectile.h"


Projectile::Projectile(bool thrownBy, float t_x , float t_y) : Entity::Entity(t_x , t_y , 200,  25, 25)
{
	thrownByPlayer = thrownBy;
}

void Projectile::draw()
{
	graphics::Brush br;

	graphics::setOrientation(0);

	br.texture = "assets/projectile.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(x, y,width,height, br);
}

void Projectile::update()
{
	if (thrownByPlayer)
		y -= velocity * graphics::getDeltaTime() / 333;
	else
		y += velocity * graphics::getDeltaTime() / 333;
}

bool Projectile::borderCheck()
{
	if (y > 1000 || y < 100)
		return true;
	else
		return false;
}

bool Projectile::wasThrownByPlayer()
{
	return thrownByPlayer;
}

/*
bool Projectile::isDestroyed(std::list <EnemyPlane>& enemyList, PlayerPlane *pp)
{
	std::list <EnemyPlane> ::iterator iter;
	for (iter = enemyList.begin(); iter != enemyList.end(); ++iter)
	{
		float min_distance = iter->distanceToCorner() + distanceToCorner();
		float distance = std::pow(iter->getX() - x, 2);
		distance += std::pow(iter->getY() - y, 2);
		distance = std::pow(distance, 0.5);
		if (wasThrownByPlayer() && min_distance > distance)
		{
			return true;
		}
	}

	float min_distance = pp->distanceToCorner() + distanceToCorner();
	float distance = std::pow(pp->getX() - x, 2);
	distance += std::pow(pp->getY() - y, 2);
	distance = std::pow(distance, 0.5);
	if ( !(wasThrownByPlayer()) && min_distance > distance)
	{
		return true;
	}

	return false;

}
*/