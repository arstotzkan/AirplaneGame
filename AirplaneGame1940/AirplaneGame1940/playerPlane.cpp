#include "Entity.h"
#include "graphics.h"
#include "scancodes.h"
#include "playerPlane.h"

playerPlane::playerPlane(float temp_x, float temp_y, float temp_width, float temp_height)
{
	x = temp_x;
	y = temp_y;
	width = temp_width;
	height = temp_height;
}
playerPlane::playerPlane()
{
	x = 400;
	y = 400;
	width = 100;
	height = 50;
}

void playerPlane::draw()
{
	graphics::Brush br;

	graphics::setOrientation(0);

	br.outline_opacity = 0.0f;
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	arr->draw();
	graphics::drawRect(x, y, width, width, br);
}

void playerPlane::update()
{
	if (graphics::getKeyState(graphics::SCANCODE_W) || graphics::getKeyState(graphics::SCANCODE_UP))
		y -= 5;
	if (graphics::getKeyState(graphics::SCANCODE_S) || graphics::getKeyState(graphics::SCANCODE_DOWN))
		y += 5;
	if (graphics::getKeyState(graphics::SCANCODE_A) || graphics::getKeyState(graphics::SCANCODE_LEFT))
		x -= 5;
	if (graphics::getKeyState(graphics::SCANCODE_D) || graphics::getKeyState(graphics::SCANCODE_RIGHT))
		x += 5;
	if (graphics::getKeyState(graphics::SCANCODE_SPACE))
		arr = new Projectile();

	arr->update();
}

void playerPlane::borderCheck()
{

}
