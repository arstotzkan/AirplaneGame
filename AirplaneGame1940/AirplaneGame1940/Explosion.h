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

	public:
		Explosion(float temp_x, float temp_y);
		void draw();
		void update();
};