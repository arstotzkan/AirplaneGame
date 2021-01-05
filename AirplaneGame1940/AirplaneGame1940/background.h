#pragma once
#include "entity.h"

class Background : public Entity //to fonto tou paixnidiou
{
	public:
		Background();
		void draw();
		void update();
		bool borderCheck();
		~Background() {};
};
