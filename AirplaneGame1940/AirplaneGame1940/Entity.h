#pragma once
#include "graphics.h"
#include <cmath>

class Entity
{
protected:
	float x;
	float y;
	float width;
	float height;
	float velocity;

public:
	Entity(float x, float y, float length , float height, float vel);
	Entity();
	Entity(float temp_x, float temp_y, float vel);
	virtual void draw();
	virtual void update();
	virtual bool borderCheck();
	virtual float distanceToCorner();
	virtual ~Entity() {};

	virtual float getX();
	virtual float getY();
	virtual void setX(float tx) { x = tx; };
	virtual void setY(float ty) { y = ty; };
	virtual float getHeight();
	virtual float getWidth();


};