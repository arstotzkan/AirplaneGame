#pragma once

#include <iostream>
#include "Entity.h"

class Projectile //: public Entity
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
