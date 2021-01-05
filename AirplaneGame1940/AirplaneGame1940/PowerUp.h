#pragma once
#include "graphics.h"
#include "entity.h"
#include <cmath>

class PowerUp : public Entity
{
	//an ta aggixei o paikths, tha kanei upgrade
public:
	PowerUp(float t_x, float t_y);
	virtual void draw();
	virtual void update();
	virtual bool borderCheck();
	virtual ~PowerUp() {};
};




