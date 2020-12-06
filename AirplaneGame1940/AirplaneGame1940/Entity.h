#pragma once
#include "graphics.h"

class Entity
{
private:
	float x;
	float y;
	float width;
	float height;

public:
	Entity(float x, float y, float width, float height);
	Entity();
	void drawAndUpdate();


};