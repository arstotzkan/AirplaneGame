#pragma once

#include <iostream>
#include "graphics.h"
#include "entity.h"

class Projectile
{
public:
	float x;
	float y;
	float width;
	float height;
	bool thrownByPlayer;

	Projectile(bool thrownBy, float x , float y);
	void draw();
	void update();
	void borderCheck();
	virtual ~Projectile() {};
};
