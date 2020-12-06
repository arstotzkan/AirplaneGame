#include "Entity.h"
#include "graphics.h"


Entity::Entity(float temp_x, float temp_y, float temp_width, float temp_height)
{
	x = temp_x;
	y = temp_y;
	width = temp_width;
	height = temp_height;
}
Entity();
void drawAndUpdate();
