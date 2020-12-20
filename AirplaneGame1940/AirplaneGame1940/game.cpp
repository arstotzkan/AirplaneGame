#include "game.h"

Game::Game()
{
	state = 1; 
	square = new PlayerPlane();
	projList;
	enList;
	enemyCreator = new Factory();
	background = new Background();
}

void Game::draw()
{
	switch (state)
	{
		case 1:
		{
			graphics::Brush br;
			graphics::setFont("assets/orange juice 2.0.ttf");
			graphics::drawText(250,450,25, "PRESS ENTER TO PLAY", br);
			//starting menu
			break;
		}
		case 2:
		{
			//intro
			break;
		}
		case 3:
		{
			//freeze
			break;
		}
		case 4:
		{
			//normal game
			background->draw();
			square->draw();
			graphics::resetPose();

			std::list <Projectile> ::iterator it;
			for (it = projList.begin(); it != projList.end(); ++it)
				it->draw();

			std::list <EnemyPlane> ::iterator it1;
			for (it1 = enList.begin(); it1 != enList.end(); ++it1)
			{
				it1->draw();
			}

			std::list <Explosion> ::iterator it2;
			for (it2 = exList.begin(); it2 != exList.end(); ++it1)
			{
				if (ex.counter == x)
					exList.erase(it2);
			}

			break;
		}
		case 5:
		{
			//victory menu
			break;
		}
		case 6:
		{
			//game over
			break;
		}
	}
}

void Game::update(float ms)
{
	switch (state)
	{
		case 1:
		{
			//starting menu
			if (graphics::getKeyState(graphics::SCANCODE_KP_ENTER))
				state = 4;
			break;
		}
		case 2:
		{
			//intro
			break;
		}
		case 3:
		{
			//game is initialized or re-initalized
			break;
		}

		case 4:
		{
			//normal game
			background->update();
			square->update(projList);
			enemyCreator->update(enList);

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

			std::list <EnemyPlane> ::iterator it1;
			for (it1 = enList.begin(); it1 != enList.end();)
			{
				it1->update(projList);
				if (it1->borderCheck() || it1->isDestroyed(projList))
				{
					it1 = enList.erase(it1);
				}

				else
					++it1;
			}

			if (square->isDestroyed(projList, enList))		
			{
				square->removeLife();
				if (square->getLifes() > 0)
					initialize();
				else
					state = 6;
			}

			break;
		}
		case 5:
		{
			//victory menu
			break;
		}
		case 6:
		{
			//game over
			break;
		}
	}
}

void Game::setState(int x)
{
	state = x;
}

Game::~Game()
{
	delete square;
	delete enemyCreator;
	delete background;
}

void Game::initialize()
{
	square = new PlayerPlane();
	projList.clear();
	enList.clear();
}