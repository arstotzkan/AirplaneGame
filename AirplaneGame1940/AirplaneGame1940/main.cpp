#include <iostream>
#include "graphics.h"
#include "scancodes.h"
#include "Entity.h"

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

Entity* square = new Entity(600, 300, 30, 30);

void update(float ms)
{
    square->update();

}

// The window content drawing function.
void draw()
{
    square->draw();
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
