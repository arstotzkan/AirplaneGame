#include "graphics.h"
#include "scancodes.h"
#include "playerplane.h"
#include <list> 
#include <iterator> 


PlayerPlane::PlayerPlane() : Airplane::Airplane(1)
{
	lives = 3;
	lastShot = 0.0f;
}

void PlayerPlane::draw()
{
	graphics::Brush br;

	graphics::setOrientation(0);

	br.texture = "assets/plane1.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(x, y, width ,height, br);
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

	if (graphics::getKeyState(graphics::SCANCODE_SPACE) && (graphics::getGlobalTime() - lastShot > 100.0f ) )
	{
		lastShot = graphics::getGlobalTime();
		Projectile* arr = new Projectile(true, x , y - height);
		projectileList.push_back(*arr);
		delete arr;
	}
}

bool PlayerPlane::borderCheck()
{
	if (x < 50)
		x = 50;
	else if(x > 450)
		x = 450;
	
	if (y < 50)
		y = 50;
	else if (y > 850)
		y = 850;

	return false;
}
