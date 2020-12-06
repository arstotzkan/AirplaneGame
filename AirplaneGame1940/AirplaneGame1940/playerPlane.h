#pragma once
#include "graphics.h"
#include "projectile.h"
#include <list> 
#include <iterator> 

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
	//Projectile* arr;

	playerPlane(float x, float y, float width, float height);
	playerPlane();
	void draw();
	void update(std::list <Projectile> &projectileList);
	void borderCheck();


};
