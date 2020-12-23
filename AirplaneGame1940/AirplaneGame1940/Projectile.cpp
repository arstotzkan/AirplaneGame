#include "projectile.h"


Projectile::Projectile(bool thrownBy, float t_x , float t_y) : Entity::Entity(t_x , t_y ,  thrownBy * 100 + 100,  10, 25)
{
	thrownByPlayer = thrownBy;
}

void Projectile::draw()
{
	graphics::Brush br;
	if (thrownByPlayer)
		graphics::setOrientation(0);
	else
		graphics::setOrientation(180);

	br.texture = "assets/projectile.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(x, y,width,height, br);

	graphics::resetPose();
}

void Projectile::update()
{
	if (thrownByPlayer)
		y -= velocity * graphics::getDeltaTime() / 333;
	else
	{
		y += velocity * graphics::getDeltaTime() / 333;
	}
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
