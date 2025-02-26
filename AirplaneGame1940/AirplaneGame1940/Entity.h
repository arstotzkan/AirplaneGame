#pragma once
#include "graphics.h"
#include <cmath>

class Entity //abstract class, oi perissoteres klasses einai apogonoi ths
{
protected:
	float x;
	float y;
	float width;
	float height;
	float velocity;

public:
	Entity(float x, float y, float vel, float length , float height);
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