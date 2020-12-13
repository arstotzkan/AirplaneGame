#include "entity.h"
#include "graphics.h"
#include "scancodes.h"

Entity::Entity(float temp_x, float temp_y, float temp_l, float temp_h)
{
	x = temp_x;
	y = temp_y;
	length = temp_l;
	height = temp_h
}
Entity::Entity()
{
	x = 250;
	y = 800;
	length = 50;
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
