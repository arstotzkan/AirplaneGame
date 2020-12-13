#include <iostream>
#include "graphics.h"
#include "scancodes.h"
#include "entity.h"
#include "projectile.h"
#include "playerPlane.h"
#include <list> 
#include <iterator> 

/*class hierarchy:
* -item +
*	-airplane + 
*		-player +
*		-enemy +
*	-projectile + 
*
*/

PlayerPlane* square = new PlayerPlane();
std::list <Projectile> projList;

void update(float ms)
{
    square->update(projList);
    std::list <Projectile> ::iterator it;
    for (it = projList.begin(); it != projList.end();)
    {
        it->update();
        if (it->borderCheck())
        {
            it = projList.erase(it);
        }

        else
            ++it;
    }
}

// The window content drawing function.
void draw()
{
    square->draw();
    graphics::resetPose();

    std::list <Projectile> ::iterator it;
    for (it = projList.begin(); it != projList.end(); ++it)
        it->draw();
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

    delete square;
    return 0;
}
