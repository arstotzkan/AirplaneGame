#include "projectile.h"
#include "graphics.h"
#include "scancodes.h"

Projectile::Projectile(bool thrownBy, float t_x , float t_y) : Entity::Entity(t_x , t_y , 10, 10)
{
	thrownByPlayer = thrownBy;
}

void Projectile::draw()
{
	graphics::Brush br;

	graphics::setOrientation(0);

	br.texture = "assets/projectile.png";
	graphics::drawRect(x, y,width,height, br);
}

void Projectile::update()
{
	y -= 5;
}

bool Projectile::borderCheck()
{
	if (y > 900 || y < 0)
		return true;
	else
		return false;
}
