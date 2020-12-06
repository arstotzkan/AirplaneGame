#include <iostream>
#include "graphics.h"
#include "Entity.h"

class Airplane : public Entity
{
public:
	Airplane(float x, float y, float width, float height);
	Airplane();
};