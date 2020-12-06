#include "projectile.h"
#include "graphics.h"
#include "scancodes.h"

Projectile::Projectile(bool thrownBy, float t_x , float t_y)
{
	thrownByPlayer = thrownBy;
	x = t_x;
	y = t_y;
	width = 10;
	height = 5;
}

void Projectile::draw()
{
	graphics::Brush br;

	graphics::setOrientation(0);

	br.outline_opacity = 0.0f;
	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	graphics::drawRect(x, y, width, width, br);
}

void Projectile::update()
{
	y -= 5;
}

void Projectile::borderCheck()
{

}
