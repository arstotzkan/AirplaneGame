#include <iostream>
#include "graphics.h"

/*class hierarchy:
* -item
*	-airplane
*		-player
*		-enemy
*			-fighter
*			-bomber
*			-heavy bomber
*	-projectile 
*		-player(maybe)
*		-enemy (maybe)
*/

void update(float ms)
{

}

// The window content drawing function.
void draw()
{
    graphics::Brush br;

    graphics::setOrientation(45);

    br.outline_opacity = 0.0f;

    graphics::drawRect(500, 250, 200, 200, br);

    br.fill_color[0] = 1.0f;
    br.fill_color[1] = 1.0f;
    br.fill_color[2] = 1.0f;

    drawText(300, 440, 70, "Hello World!", br);
    graphics::resetPose();
}

int main()
{
    graphics::createWindow(1200, 600, "Hello World");

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(1000, 500);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    graphics::Brush br;
    br.fill_color[0] = 0.5f;
    br.fill_color[1] = 0.5f;
    br.fill_color[2] = 0.5f;
    graphics::setWindowBackground(br);

    graphics::startMessageLoop();

    return 0;
}