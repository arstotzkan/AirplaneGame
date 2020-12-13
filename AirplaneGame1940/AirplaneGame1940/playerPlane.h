#pragma once
#include "graphics.h"
#include "airplane.h"
#include "projectile.h"
#include "enemyplane.h"
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
	float lastShot;

	PlayerPlane();
	void draw();
	void update(std::list <Projectile> &projectileList);
	bool borderCheck();
	bool collisionCheck(std::list <Projectile>& projectileList, std::list <EnemyPlane>& enemyList);
	virtual ~PlayerPlane() {}


};
