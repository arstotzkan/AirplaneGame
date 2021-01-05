#include "PowerUp.h"

PowerUp::PowerUp(float t_x, float t_y) : Entity::Entity(t_x , t_y, 15 , 40 , 40)
{
}

void PowerUp::draw() // zwgrafizei to power up sthn othoni
{
	graphics::Brush br;

	graphics::setOrientation(0);

	br.outline_opacity = 0.0f;

	br.texture = "assets/powerup.png";
	graphics::drawRect(x, y, width, height, br);
}
void PowerUp::update() // anaparagei to power up
{
	y += velocity * graphics::getDeltaTime() / 333;
}
bool PowerUp::borderCheck() // kanei elegxo wste na mhn bgei apo ta perithoria ths othonis
{
	if (y > 900)
		return true;
	else
		return false;
}
