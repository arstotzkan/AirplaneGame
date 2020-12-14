#pragma once

#include <iostream>
#include "graphics.h"
#include "entity.h"

class Airplane : public Entity
{
protected:
	int level;
public:
	Airplane(int lvl, float vel, float x, float y);
	virtual ~Airplane() {}
};