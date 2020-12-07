#pragma once
#include "graphics.h"
#include "projectile.h"

class Entity
{
/*private:
	float x;
	float y;
	float width;
	float height;
*/
public:
	float x;
	float y;
	float width;
	float height;

	Entity(float x, float y, float width, float height);
	Entity();
	void draw();
	void update();
	void borderCheck();
	virtual ~Entity() {}


};