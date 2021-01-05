#pragma once

#include <iostream>
#include "graphics.h"
#include "entity.h"
#include <list>
#include <iterator>
#include <string>

class Explosion : public Entity //ekriksi
{
	protected:
		int counter;

	public:
		Explosion(float temp_x, float temp_y);
		Explosion(float temp_x, float temp_y , float size);
		void draw();
		void update();
		bool shouldBeDestroyed(){ return (counter / 3 > 11 ) ; };
};