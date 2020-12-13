#include "graphics.h"
#include "scancodes.h"
#include "playerplane.h"
#include <list> 
#include <iterator> 


PlayerPlane::PlayerPlane() : Airplane::Airplane(1)
{
	lives = 3;
}

void PlayerPlane::draw()
{
	graphics::Brush br;

	graphics::setOrientation(0);

	br.outline_opacity = 0.0f;
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	graphics::drawDisk(x, y, rad, br);
}

void PlayerPlane::update(std::list <Projectile>  &projectileList)
{
	if (graphics::getKeyState(graphics::SCANCODE_W) || graphics::getKeyState(graphics::SCANCODE_UP))
		y -= 5;
	if (graphics::getKeyState(graphics::SCANCODE_S) || graphics::getKeyState(graphics::SCANCODE_DOWN))
		y += 5;
	if (graphics::getKeyState(graphics::SCANCODE_A) || graphics::getKeyState(graphics::SCANCODE_LEFT))
		x -= 5;
	if (graphics::getKeyState(graphics::SCANCODE_D) || graphics::getKeyState(graphics::SCANCODE_RIGHT))
		x += 5;

	borderCheck();

	if (graphics::getKeyState(graphics::SCANCODE_SPACE))
	{
		Projectile* arr = new Projectile(true, x , y);
		projectileList.push_back(*arr);
	}
}

bool PlayerPlane::borderCheck()
{
	if (x < 50)
		x = 50;
	else if(x > 950)
		x = 950;
	
	if (y < 50)
		y = 50;
	else if (y > 450)
		y = 450;
	return true;
}
