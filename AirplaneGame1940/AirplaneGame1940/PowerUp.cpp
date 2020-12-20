#include "PowerUp.h"

PowerUp::PowerUp(float t_x, float t_y) : Entity::Entity(t_x , t_y, 2 , 40 , 40)
{
}

void PowerUp::draw()
{
	graphics::Brush br;

	graphics::setOrientation(0);

	br.outline_opacity = 0.0f;
	graphics::drawRect(x, y, width, height, br);
}
void PowerUp::update()
{
	y += velocity * graphics::getDeltaTime() / 333;
}
bool PowerUp::borderCheck()
{
	if (y > 900)
		return true;
	else
		return false;
}
