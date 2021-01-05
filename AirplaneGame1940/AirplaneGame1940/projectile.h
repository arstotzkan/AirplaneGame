#pragma once

#include <iostream>
#include "graphics.h"
#include "entity.h"
#include <list>
#include <iterator>

class Projectile : public Entity
{
	//ektoksevontai kai apo ton paikti kai apo to AI
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
