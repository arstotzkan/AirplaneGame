#include "entity.h"
#include "graphics.h"
#include "scancodes.h"
#include <cmath>


Entity::Entity(float temp_x, float temp_y, float temp_w, float temp_h)
{
	x = temp_x;
	y = temp_y;
	width = temp_w;
	height = temp_h;
}
Entity::Entity()
{
	x = 250;
	y = 800;
	width = 50;
	height = 50;
}

void Entity::draw()
{

}

void Entity::update()
{

}

bool Entity::borderCheck()
{
	return false;
}

float Entity::distanceToCorner()
{
	return pow(pow(height, 2) + pow(width, 2), 0.5) / 2;
}