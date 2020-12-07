#pragma once
#include "graphics.h"
#include "projectile.h"
#include <list> 
#include <iterator> 

class PlayerPlane
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
	int lives;

	PlayerPlane();
	void draw();
	void update(std::list <Projectile> &projectileList);
	void borderCheck();
	virtual ~PlayerPlane() {}


};
