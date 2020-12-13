#pragma once

#include <iostream>
#include "graphics.h"
#include "entity.h"

class Projectile : public Entity
{
public:

	bool thrownByPlayer;

	Projectile(bool thrownBy, float x, float y);
	void draw();
	void update();
	bool borderCheck();
	virtual ~Projectile() {};
};
