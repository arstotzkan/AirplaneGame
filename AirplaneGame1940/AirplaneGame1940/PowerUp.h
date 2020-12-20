#pragma once
#include "graphics.h"
#include <cmath>

class PowerUp
{
protected:
	float velocity;

public:
	PowerUp(float vel);
	PowerUp();
	virtual void draw();
	virtual void update();
	virtual bool borderCheck();
	virtual ~PowerUp() {};
};




