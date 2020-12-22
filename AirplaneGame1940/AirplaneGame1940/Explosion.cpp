#include "explosion.h"

Explosion::Explosion(float temp_x, float temp_y) : Entity::Entity(temp_x , temp_y , 0 ,  30 , 30)
{
	timeCreated = graphics::getGlobalTime();
	counter = 1;
}

void Explosion::draw()
{

	if (!shouldBeDestroyed())
	{
		graphics::Brush br;
		graphics::setOrientation(0);

		br.outline_opacity = 0.0f;
		std::string img = "assets/explosion/explosion" + std::to_string( counter / 3 + 1) + ".png";
		br.texture = img;
		graphics::drawRect(x, y, width, height, br);
	}
}

void Explosion::update() 
{
	counter++;
}