#include "Factory.h"

Factory::Factory()
{
	counter = 0;
}

void Factory::update(std::list <EnemyPlane>& enemyList, std::list <PowerUp> &powerList)
{
	if (counter <= 20000)
	{
		switch (counter % 10000)
		{
			case 1000:
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

			case 1750:
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

			case 2500:
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
				

				PowerUp* p1 = new PowerUp(300, -200);
				powerList.push_back(*p1);
				delete p1;
				p1 = nullptr;

				break;
			}

			case 3250:
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
				break;
			}

			case 4000:
			{
				EnemyPlane* a0 = new EnemyPlane(4, 200, -100);
				EnemyPlane* a1 = new EnemyPlane(4, 250, -100);
				EnemyPlane* a2 = new EnemyPlane(4, 350, -100);
				EnemyPlane* a3 = new EnemyPlane(4, 400, -100);
				enemyList.push_back(*a0);
				enemyList.push_back(*a1);
				enemyList.push_back(*a2);
				enemyList.push_back(*a3);
				delete a0;
				delete a1;
				delete a2;
				delete a3;
				a0 = nullptr;
				a1 = nullptr;
				a2 = nullptr;
				a3 = nullptr;
				break;
			}

			case 5000:
			{
				EnemyPlane* a0 = new EnemyPlane(1, 100, -100);
				EnemyPlane* a1 = new EnemyPlane(2, 300, -100);
				EnemyPlane* a2 = new EnemyPlane(1, 500, -100);
				EnemyPlane* a3 = new EnemyPlane(5, 100, 1100);
				enemyList.push_back(*a0);
				enemyList.push_back(*a1);
				enemyList.push_back(*a2);
				enemyList.push_back(*a3);
				delete a0;
				delete a1;
				delete a2;
				delete a3;
				a0 = nullptr;
				a1 = nullptr;
				a2 = nullptr;
				a3 = nullptr;

				PowerUp* p1 = new PowerUp(300, -200);
				powerList.push_back(*p1);
				delete p1;
				p1 = nullptr;


				break;
			}

			case 6000:
			{
				EnemyPlane* a0 = new EnemyPlane(1, 100, -100);
				EnemyPlane* a1 = new EnemyPlane(1, 200, -100);
				EnemyPlane* a2 = new EnemyPlane(2, 300, -100);
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

			case 7000:
			{
				EnemyPlane* a0 = new EnemyPlane(2, 100, -100);
				EnemyPlane* a1 = new EnemyPlane(4, 250, -100);
				EnemyPlane* a2 = new EnemyPlane(4, 350, -100);
				EnemyPlane* a3 = new  EnemyPlane(2, 500, -100);
				enemyList.push_back(*a0);
				enemyList.push_back(*a1);
				enemyList.push_back(*a2);
				enemyList.push_back(*a3);
				delete a0;
				delete a1;
				delete a2;
				delete a3;
				a0 = nullptr;
				a1 = nullptr;
				a2 = nullptr;
				a3 = nullptr;
				break;
			}

			case 8000:
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

		}
	}

	else
	{
		switch (counter % 5000)
		{
			case 1500:
			{
				EnemyPlane* a0 = new EnemyPlane(2, 150, -100);
				EnemyPlane* a1 = new EnemyPlane(4, 250, -100);
				EnemyPlane* a3 = new EnemyPlane(4, 350, -100);
				EnemyPlane* a4 = new EnemyPlane(2, 450, -100);
				enemyList.push_back(*a0);
				enemyList.push_back(*a1);
				enemyList.push_back(*a3);
				enemyList.push_back(*a4);
				delete a0;
				delete a1;
				delete a3;
				delete a4;
				a0 = nullptr;
				a1 = nullptr;
				a3 = nullptr;
				a4 = nullptr;
				break;
			}
			case 2500:
			{
				EnemyPlane* a0 = new EnemyPlane(5, 100, 1100);
				EnemyPlane* a1 = new EnemyPlane(5, 500, 1300);
				EnemyPlane* a2 = new EnemyPlane(3, -100, 300);
				EnemyPlane* a3 = new EnemyPlane(3, -100, 500);
				enemyList.push_back(*a0);
				enemyList.push_back(*a1);
				enemyList.push_back(*a2);
				enemyList.push_back(*a3);
				delete a0;
				delete a1;
				delete a2;
				delete a3;
				a0 = nullptr;
				a1 = nullptr;
				a2 = nullptr;
				a3 = nullptr;

				PowerUp* p1 = new PowerUp(300, -200);
				powerList.push_back(*p1);
				delete p1;
				p1 = nullptr;

				break;
			}

			case 4000:
			{
				EnemyPlane* a0 = new EnemyPlane(5, 100, 1300);
				EnemyPlane* a1 = new EnemyPlane(5, 500, 100);
				EnemyPlane* a2 = new EnemyPlane(4, 200, -100);
				EnemyPlane* a3 = new EnemyPlane(4, 400, -100);
				enemyList.push_back(*a0);
				enemyList.push_back(*a1);
				enemyList.push_back(*a2);
				enemyList.push_back(*a3);
				delete a0;
				delete a1;
				delete a2;
				delete a3;
				a0 = nullptr;
				a1 = nullptr;
				a2 = nullptr;
				a3 = nullptr;
				break;
			}

		}
	}
	counter++;
}


