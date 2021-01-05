#include "background.h"

Background::Background() : Entity::Entity(300,-6500, 15, 600, 15000)
{
}

void Background::draw() //zwgrafizei
{
	graphics::Brush br;

	graphics::setOrientation(0);

	br.texture = "assets/bg.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(x, y, width, height, br);
}

void Background::update() //metakinhsh pros ta panw
{
	y += velocity * graphics::getDeltaTime() / 333;
}

bool Background::borderCheck() //an vgei true, o paikths exei nikhsei to paixnidi
{
	return (y >= 7500);
}