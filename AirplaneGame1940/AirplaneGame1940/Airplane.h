#pragma once

#include <iostream>
#include "graphics.h"
#include "entity.h"

class Airplane : public Entity
{
public:
	
	int level;

	Airplane(int lvl);
	virtual ~Airplane() {}
};