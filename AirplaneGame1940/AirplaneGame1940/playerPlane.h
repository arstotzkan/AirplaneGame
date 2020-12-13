#pragma once
#include "graphics.h"
#include "airplane.h"
#include "projectile.h"
#include <list> 
#include <iterator> 

class PlayerPlane : public Airplane
{
	/*private:
		float x;
		float y;
		float width;
		float height;
	*/
public:

	int lives;

	PlayerPlane();
	void draw();
	void update(std::list <Projectile> &projectileList);
	bool borderCheck();
	virtual ~PlayerPlane() {}


};
