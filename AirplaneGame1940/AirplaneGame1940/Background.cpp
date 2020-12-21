#include "background.h"

Background::Background() : Entity::Entity(300, 0, 15, 600, 2400) //we'll need to make it bigger later
{

}

void Background::draw()
{
	graphics::Brush br;

	graphics::setOrientation(0);

	br.texture = "assets/bg.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(x, y, width, height, br);
}

void Background::update()
{
	y += velocity * graphics::getDeltaTime() / 333;
}

bool Background::borderCheck()
{
	return false;
}