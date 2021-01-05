#pragma once
#include "playerplane.h"
#include <list>
#include <iterator>

class PlayerSquadron
{
//einai to synolo filikwn aeroplanwn pou elegxei o paikths
protected:
	int level;
	PlayerPlane* lead;
	PlayerPlane* left;
	PlayerPlane* right;
	bool leftExists; //an yparxei aristero aeroplano, an einai false to aeroplano yparxei mono os placeholder
	bool rightExists; //an yparxei dexi aeroplano, an einai false to aeroplano yparxei mono os placeholder

public:
	PlayerSquadron();
	PlayerSquadron(int lv);
	void draw();
	void update(std::list <Projectile>& projectileList, std::list <PowerUp>& upgradeList,  bool vol, float time);
	void upgrade(std::list <PowerUp>& upgradeList, bool vol);
	void borderCheck();
	int getLevel() { return level; };
	void setLevel(int x) { level = x; };

	float getX() { return lead->getX(); };
	float getY() { return lead->getY(); };
	void setY(float new_y);
	void setX(float new_X);

	bool isDestroyed(std::list <Projectile>& projectileList, std::list <EnemyPlane>& enemyList, std::list <Explosion>& expList, bool vol);
	virtual ~PlayerSquadron();
};