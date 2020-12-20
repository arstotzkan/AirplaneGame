#include "explosion.h"

Explosion::Explosion(float temp_x, float temp_y) {
	x = temp_x;
	y = temp_y;
	width = 30;
	height = 30;
	timeCreated = graphics::getGlobalTime();
}

void Explosion::draw() {
	graphics::Brush br;

	graphics::setOrientation(0);

	//br.texture = 0.0f;
	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.85f;
	br.outline_opacity = 0.0f;
	graphics::drawRect(x, y, width, height, br);
}

void Explosion::update() {
	/**
	if (width <= 100) {
		width++;
	}
	if (height <= 100) {
		height++;
	}
	else {
		//katastrefei to antikeimeno
	}
	*/

}