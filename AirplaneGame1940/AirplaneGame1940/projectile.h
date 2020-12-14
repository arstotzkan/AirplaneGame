#pragma once

#include <iostream>
#include "graphics.h"
#include "entity.h"

class Projectile : public Entity
{
protected:
	bool thrownByPlayer;
public:
	Projectile(bool thrownBy, float x, float y);
	void draw();
	void update();
	bool borderCheck();
	bool wasThrownByPlayer();
	virtual ~Projectile() {};
};
