#pragma once

#include <iostream>
#include "graphics.h"
#include "Entity.h"

class Projectile
{
public:
	float x;
	float y;
	float width;
	float height;

	Projectile(float x, float y, float width, float height);
	Projectile();
	void draw();
	void update();
	void borderCheck();
};
