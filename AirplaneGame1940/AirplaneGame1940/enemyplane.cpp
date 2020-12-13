#include "entity.h"
#include "graphics.h"
#include "scancodes.h"
#include "enemyplane.h"
#include <list> 
#include <iterator> 


EnemyPlane::EnemyPlane(int lvl) : Airplane(lvl)
{
	healthPoints = 2;
}

void EnemyPlane::draw()
{
	graphics::Brush br;

	graphics::setOrientation(0);
	br.outline_opacity = 0.0f;
}

void EnemyPlane::update(std::list <Projectile>& projectileList)
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
}

bool EnemyPlane::borderCheck()
{
	if (x < 0)
		return true;
	else
		return false;
}

