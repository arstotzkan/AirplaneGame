#pragma once
#include "graphics.h"


class Entity
{
protected:
	float x;
	float y;
	float width;
	float height;
public:
	Entity(float x, float y, float length , float height);
	Entity();
	virtual void draw();
	virtual void update();
	virtual bool borderCheck();
	virtual float distanceToCorner();
	virtual ~Entity() {}

	virtual float getX();
	virtual float getY();
	virtual float getHeight();
	virtual float getWidth();


};