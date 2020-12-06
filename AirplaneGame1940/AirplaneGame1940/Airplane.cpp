#include "Airplane.h"
#include "graphics.h"
#include "scancodes.h"

Airplane::Airplane(float temp_x, float temp_y, float temp_width, float temp_height)
{
	x = temp_x;
	y = temp_y;
	width = temp_width;
	height = temp_height;
}
Airplane::Airplane()
{
	x = 400;
	y = 400;
	width = 20;
	height = 150;
}