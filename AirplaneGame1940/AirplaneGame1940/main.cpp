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

*/
Game* game = new Game(); //initializing game class

void draw()
{
    //h draw function tou paixnidiou
    game->draw();
}

void update(float ms)
{
    //h update function tou paixnidiou
    game->update(ms);
}

int main()
{
    graphics::createWindow(600, 1000, "Day of the Eagle"); //parathiro

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(600, 1000); //canvas
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    graphics::Brush br;
    br.fill_color[0] = 0.0f;
    br.fill_color[1] = 0.0f;
    br.fill_color[2] = 0.0f;
    graphics::setWindowBackground(br);

    graphics::startMessageLoop(); //arxh paixnidiou

    graphics::destroyWindow(); //telos paixnidiou

    delete game; //apofigi memory leak
    return 0;
}
