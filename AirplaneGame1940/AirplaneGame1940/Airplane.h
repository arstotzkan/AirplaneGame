#include <iostream>
#include "graphics.h"
#include "entity.h"

class Airplane
{
public:
	float x;
	float y;
	float width;
	float height;
	int level;

	Airplane(int lvl);
	virtual ~Airplane() {}
};