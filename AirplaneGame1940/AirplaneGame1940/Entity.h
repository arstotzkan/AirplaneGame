#pragma once
#include "graphics.h"


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
	float rad;

	Entity(float x, float y, float rad);
	Entity();
	void draw();
	void update();
	void borderCheck();
	virtual ~Entity() {}


};