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
	Factory* enemyCreator;
	Background* background;
	int state;
	/*
	* state 1: start menu
	* state 2: introduction
	* state 3: freeze
	* state 4: game
	* state 5: game over
	* state 6: victory menu
	* (tbf the last 2 can be together or sth)
	*/
public:
	Game();
	void draw();
	void update(float ms);
	void setState(int x);
	virtual ~Game();
	//void initialize(bool fromScratch);
};
