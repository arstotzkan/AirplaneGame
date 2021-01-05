#pragma once

#include <iostream>
#include "graphics.h"
#include "entity.h"

class Airplane : public Entity //abstract class 
{
protected:
	int level;
	float lastShot;
public:
	Airplane(int lvl, float vel, float x, float y, float size);
	virtual ~Airplane() {}
	virtual int getLevel() { return level; };
	virtual float getSize() { return width; };
};