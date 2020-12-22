#pragma once

#include <iostream>
#include "graphics.h"
#include "entity.h"
#include <list>
#include <iterator>
#include <string>

class Explosion : public Entity
{
	protected:
		float timeCreated;
		int counter;

	public:
		Explosion(float temp_x, float temp_y);
		void draw();
		void update();
		bool shouldBeDestroyed(){ return (counter / 3 > 11 ) ; };
};