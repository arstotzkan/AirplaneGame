#include <iostream>
#include "graphics.h"
#include "scancodes.h"
#include "game.h"

/*class hierarchy:
* -item +
*	-airplane + 
*		-player +
*		-enemy +
*	-projectile + 
*
* 
*/
Game* game = new Game();

void draw()
{
    game->draw();
}

void update(float ms)
{
    game->update(ms);
}

int main()
{
    graphics::createWindow(500, 900, "Hello World");

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(500, 900);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    graphics::Brush br;
    br.fill_color[0] = 0.0f;
    br.fill_color[1] = 0.85f;
    br.fill_color[2] = 0.85f;
    graphics::setWindowBackground(br);

    graphics::startMessageLoop();

    graphics::destroyWindow();

    delete game;
    return 0;
}
