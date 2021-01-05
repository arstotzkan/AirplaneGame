#pragma once

#include <iostream>
#include "enemyplane.h"
#include "PowerUp.h"
#include <list>

class Factory
{
	//dimiourgei exthrika aeroplana
protected:
	int counter; //metritis wste na dhmiourghthei to katallhlo exthriko formation
	float lastSpawn; //teleutaia stigmh pou egine spawn antipalwn
	bool onlyOnce; //apofygi diplwn spawn
public:
	Factory();
	void update(std::list <EnemyPlane>& enemyList, std::list <PowerUp>& powerList, float time);
	virtual ~Factory() {}
	int getCounter() { return counter; };
};