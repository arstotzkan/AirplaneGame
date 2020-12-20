#include "Airplane.h"
#include "graphics.h"
#include "scancodes.h"


Airplane::Airplane(int lvl, float vel, float x , float y) : Entity::Entity(x,y, vel, lvl * 50 , lvl * 50)
{
	level = lvl;
}