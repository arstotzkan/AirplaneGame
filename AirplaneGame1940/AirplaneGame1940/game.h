#pragma once
#include "graphics.h"
#include "scancodes.h"
#include "entity.h"
#include "projectile.h"
#include "playerSquadron.h"
#include "Factory.h"
#include "background.h"
#include "Explosion.h"
#include <list> 
#include <iterator> 
#include <string>
#include <algorithm>
#include <cmath>

class Game
{
//i kyria klasi tou paixnidiou
//elegxei kathe plevra tou paixnidiou
private:
	PlayerSquadron* squadron;

	std::list <Projectile> projList;
	std::list <EnemyPlane> enList;
	std::list <Explosion> exList;
	std::list <PowerUp> upList;

	Factory* enemyCreator;
	Background* background;
	int state;
	int subStateCounter1;
	int subStateCounter2;


	float lastStateChange = 0.0f;
	float gameTime = 0.0f;

	int score;
	bool music;
	bool soundEffects;
	bool paused;

	int initialLifes;
	int playerLifes;
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
	void initialize(bool fromScratch);
};

std::string getLineFromText(int x, const char* file_name);