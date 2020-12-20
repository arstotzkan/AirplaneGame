#pragma once

#include <iostream>
#include "graphics.h"
#include "entity.h"
#include <list>
#include <iterator>

class Explosion : public Entity
{
	protected:
		float timeCreated;

	public:
		Explosion(float temp_x, float temp_y);
		void draw();
		void update();
		bool shouldBeDestroyed(){ return (graphics::getGlobalTime() - timeCreated > 500.0f) ; };
};