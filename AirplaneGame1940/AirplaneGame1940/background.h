#pragma once
#include "entity.h"

class Background : public Entity
{
	public:
		Background();
		void draw();
		void update();
		bool borderCheck();
		~Background() {};
};
