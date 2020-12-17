#pragma once
#include "graphics.h"
#include "scancodes.h"
#include "entity.h"
#include "projectile.h"
#include "playerPlane.h"
#include "Factory.h"
#include "background.h"
#include <list> 
#include <iterator> 

class Game
{
private:
	PlayerPlane* square;
	std::list <Projectile> projList;
	std::list <EnemyPlane> enList;
	Factory* enemyCreator = new Factory();
	Background* background;
	int state;
	/*
	* state 1: start menu
	* state 2: game
	* state 3: game over
	* state 4: victory menu
	*/
public:
	Game();
	void draw();
	void update(float ms);
	void setState(int x);
	virtual ~Game();
};
