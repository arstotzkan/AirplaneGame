#pragma once
#include "playerplane.h"
#include <list>
#include <iterator>

class PlayerSquadron
{
protected:
	int level;
	PlayerPlane* lead;
	PlayerPlane* left;
	PlayerPlane* right;
	bool leftExists;
	bool rightExists;

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