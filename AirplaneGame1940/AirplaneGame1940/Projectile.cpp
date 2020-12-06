#include "Projectile.h"
#include "graphics.h"
#include "scancodes.h"
#include "Entity.h"

Projectile::Projectile(float temp_x, float temp_y, float temp_width, float temp_height)
{
	x = temp_x;
	y = temp_y;
	width = temp_width;
	height = temp_height;
}
Projectile::Projectile()
{
	x = 400;
	y = 400;
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
