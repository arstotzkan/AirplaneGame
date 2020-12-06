#include "Entity.h"
#include "graphics.h"


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

Entity::drawAndUpdate()
{

}
