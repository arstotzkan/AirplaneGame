#include <iostream>
#include "graphics.h"

class Projectile : public Entity
{
public:
	Projectile(float x, float y, float width, float height);
	Projectile();
	void drawAndUpdate();
};