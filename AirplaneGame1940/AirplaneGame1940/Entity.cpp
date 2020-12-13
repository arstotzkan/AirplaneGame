#include "entity.h"
#include "graphics.h"
#include "scancodes.h"

Entity::Entity(float temp_x, float temp_y, float temp_rad)
{
	x = temp_x;
	y = temp_y;
	rad = temp_rad;
}
Entity::Entity()
{
	x = 400;
	y = 400;
	rad = 50;
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
