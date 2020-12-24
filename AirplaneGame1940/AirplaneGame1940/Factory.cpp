#include "Factory.h"

Factory::Factory()
{
	counter = 0;
	lastSpawn = 0.0f;
	onlyOnce = false;
}

void Factory::update(std::list <EnemyPlane>& enemyList, std::list <PowerUp> &powerList, float time)
{
	
	if (time - lastSpawn >= 10000.0f)
	{
		lastSpawn = time;
		onlyOnce = true;
		counter++;
	}
	
	if (onlyOnce)
	{
		switch (counter)
		{
			case 0:
				break;
			case 1:
			case 2:
			{
				EnemyPlane* a1 = new EnemyPlane(1, 150, -100);
				EnemyPlane* a2 = new EnemyPlane(1, 300, -100);
				EnemyPlane* a3 = new EnemyPlane(1, 450, -100);
				enemyList.push_back(*a1);
				enemyList.push_back(*a2);
				enemyList.push_back(*a3);
				delete a1;
				delete a2;
				delete a3;
				a1 = nullptr;
				a2 = nullptr;
				a3 = nullptr;
				break;
			}
			case 3:
			{
				EnemyPlane* a0 = new EnemyPlane(1, 100, -100);
				EnemyPlane* a1 = new EnemyPlane(1, 200, -100);
				EnemyPlane* a2 = new EnemyPlane(1, 300, -100);
				EnemyPlane* a3 = new EnemyPlane(1, 400, -100);
				EnemyPlane* a4 = new EnemyPlane(1, 500, -100);
				enemyList.push_back(*a0);
				enemyList.push_back(*a1);
				enemyList.push_back(*a2);
				enemyList.push_back(*a3);
				enemyList.push_back(*a4);
				delete a0;
				delete a1;
				delete a2;
				delete a3;
				delete a4;
				a0 = nullptr;
				a1 = nullptr;
				a2 = nullptr;
				a3 = nullptr;
				a4 = nullptr;
				break;
			}
			case 4:
			case 6:
			case 7:
			case 17:
			{
				EnemyPlane* a1 = new EnemyPlane(2, 150, -100);
				EnemyPlane* a2 = new EnemyPlane(2, 300, -100);
				EnemyPlane* a3 = new EnemyPlane(2, 450, -100);
				enemyList.push_back(*a1);
				enemyList.push_back(*a2);
				enemyList.push_back(*a3);
				delete a1;
				delete a2;
				delete a3;
				a1 = nullptr;
				a2 = nullptr;
				a3 = nullptr;
				break;
			}
			case 5:
			case 8:
			case 11:
			case 16:
			case 21:
			case 23:
			{
				EnemyPlane* a1 = new EnemyPlane(3, -100, 150);
				EnemyPlane* a2 = new EnemyPlane(3, -100, 250);
				EnemyPlane* a3 = new EnemyPlane(3, -100, 350);
				EnemyPlane* a4 = new EnemyPlane(3, -100, 450);
				EnemyPlane* a5 = new EnemyPlane(3, -100, 550);
				enemyList.push_back(*a1);
				enemyList.push_back(*a2);
				enemyList.push_back(*a3);
				delete a1;
				delete a2;
				delete a3;
				delete a4;
				delete a5;
				a1 = nullptr;
				a2 = nullptr;
				a3 = nullptr;
				a4 = nullptr;
				a5 = nullptr;

				PowerUp* p1 = new PowerUp(300, -200);
				powerList.push_back(*p1);
				delete p1;
				p1 = nullptr;

				break;
			}
			case 9:
			case 10:
			case 13:
			case 18:
			case 19:
			case 24:
			{
				EnemyPlane* a0 = new EnemyPlane(4, 100, -100);
				EnemyPlane* a1 = new EnemyPlane(4, 300, -100);
				EnemyPlane* a2 = new EnemyPlane(4, 500, -100);
				enemyList.push_back(*a0);
				enemyList.push_back(*a1);
				enemyList.push_back(*a2);
				delete a0;
				delete a1;
				delete a2;
				a0 = nullptr;
				a1 = nullptr;
				a2 = nullptr;
				break;
			}

			case 12:
			case 20:
			case 27:
			{
				EnemyPlane* a0 = new EnemyPlane(5, 100, 1100);
				EnemyPlane* a1 = new EnemyPlane(5, 500, 1300);
				enemyList.push_back(*a0);
				enemyList.push_back(*a1);
				delete a0;
				delete a1;
				a0 = nullptr;
				a1 = nullptr;

				break;
			}
			case 14:
			case 22:
			{
				EnemyPlane* a0 = new EnemyPlane(4, 100, -100);
				EnemyPlane* a1 = new  EnemyPlane(4, 500, -100);
				enemyList.push_back(*a0);
				enemyList.push_back(*a1);
				delete a0;
				delete a1;
				a0 = nullptr;
				a1 = nullptr;
				break;
			}

			case 15:
			case 26:
			case 28:
			{
				EnemyPlane* a0 = new EnemyPlane(5, 100, 1300);
				EnemyPlane* a1 = new EnemyPlane(5, 500, 1100);
				enemyList.push_back(*a0);
				enemyList.push_back(*a1);
				delete a0;
				delete a1;
				a0 = nullptr;
				a1 = nullptr;

				break;
			}
			
		}
		onlyOnce = false;
	}
	
	
}


