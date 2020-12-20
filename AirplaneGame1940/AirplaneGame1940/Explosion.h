#pragma once

#include <iostream>
#include "graphics.h"
#include <list>
#include <iterator>

class Explosion {
	protected:
		float x;
		float y;
		float height;
		float width;
		float timeCreated;

	public:
		Explosion(float temp_x, float temp_y);
		void draw();
		void update();
		bool shouldBeDestroyed(){ return (graphics::getGlobalTime() - timeCreated > 500.0f) ; };
};