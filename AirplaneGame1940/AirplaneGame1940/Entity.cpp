#include "Entity.h"
#include "graphics.h"
#include "scancodes.h"

Entity::Entity(float temp_x, float temp_y, float temp_width, float temp_height)
{
	x = temp_x;
	y = temp_y;
	width = temp_width;
	height = temp_height;
}
Entity::Entity()
{
	x = 400;
	y = 400;
	width = 100;
	height = 50;
}

void Entity::drawAndUpdate()
{
	if (graphics::getKeyState(graphics::SCANCODE_W))
		y += 1;
	else if (graphics::getKeyState(graphics::SCANCODE_S))
		y -= 1;
	else if (graphics::getKeyState(graphics::SCANCODE_A))
		x -= 1;
	else if (graphics::getKeyState(graphics::SCANCODE_D))
		x += 1;

}
