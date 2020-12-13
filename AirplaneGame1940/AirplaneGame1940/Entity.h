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
	float length;
	float height;

	Entity(float x, float y, float length , float height);
	Entity();
	virtual void draw();
	virtual void update();
	virtual bool borderCheck();
	virtual ~Entity() {}


};