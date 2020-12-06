#pragma once
#include "graphics.h"
#include "projectile.h"

class playerPlane
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
	Projectile* arr;

	playerPlane(float x, float y, float width, float height);
	playerPlane();
	void draw();
	void update();
	void borderCheck();


};
