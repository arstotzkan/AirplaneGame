#include "projectile.h"
#include "graphics.h"
#include "scancodes.h"

Projectile::Projectile(bool thrownBy, float t_x , float t_y) : Entity::Entity(t_x , t_y , 10)
{
	thrownByPlayer = thrownBy;
}

void Projectile::draw()
{
	graphics::Brush br;

	graphics::setOrientation(0);

	br.outline_opacity = 0.0f;
	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	graphics::drawDisk(x, y,rad, br);
}

void Projectile::update()
{
	y -= 5;
}

void Projectile::borderCheck()
{

}
