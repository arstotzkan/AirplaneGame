#include "Airplane.h"
#include "graphics.h"
#include "scancodes.h"


Airplane::Airplane(int lvl, float x , float y) : Entity::Entity(x,y)
{
	level = lvl;
}