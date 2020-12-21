#include "game.h"

Game::Game()
{
	state = 0; 
	subStateCounter1 = 0;
	subStateCounter2 = 0;

	square = new PlayerPlane();
	projList;
	enList;
	enemyCreator = new Factory();
	background = new Background();
	score = 0;
}

void Game::draw()
{
	switch (state)
	{
		case 0:
		{
			//starting menu
			graphics::Brush br;
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			graphics::setFont("assets/fonts/Gill Sans.otf");
			graphics::drawText(150, 450, 25, "PRESS SPACE TO PLAY", br);
			
			break;
		}
		case 1:
		{
			//settings
			break;
		}
		case 2:
		{
			//credits
			break;
		}
		case 3:
		{
			//intro
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
			for (it2 = exList.begin(); it2 != exList.end(); ++it2)
			{
				it2->draw();
			}

			graphics::Brush br;
			br.fill_color[0] = 0.0f;
			br.fill_color[1] = 0.0f;
			br.fill_color[2] = 0.0f;
			graphics::drawRect(250, 50, 500, 100, br);

			//graphics::Brush br;
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			graphics::setFont("assets/fonts/Gill Sans.otf");
			std::string text1 = "SCORE: " + std::to_string(score);
			std::string text2 = "LIVES: " + std::to_string(square->getLifes());
			graphics::drawText(50, 50, 25, text1, br);
			graphics::drawText(300, 50, 25, text2, br);
			break;
		}
		case 5:
		{
			//victory screen
			graphics::Brush br;
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			graphics::setFont("assets/fonts/Gill Sans.otf");
			graphics::drawText(150, 50, 35, "VICTORY", br);

			graphics::Brush br1;
			br1.texture = "assets/events/victory.png";
			graphics::drawRect(250, 300, 400, 250, br1);

			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			graphics::drawText(50, 800, 20, "Never was so much owed by so many to so few", br);
			break;
		}
		case 6:
		{
			//defeat screen
			graphics::Brush br;
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			graphics::setFont("assets/fonts/Gill Sans.otf");
			graphics::drawText(150, 50, 35, "DEFEAT", br);
			
			//graphics::Brush br;
			br.texture = "assets/events/defeat.png";
			graphics::drawRect(250, 300, 400, 250, br);

			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			graphics::drawText(50, 800, 20, "We shall never surrender!", br);
			break;
		}
	}
}

void Game::update(float ms)
{
	if (graphics::getGlobalTime() - lastStateChange > 300.0f)
	{
		switch (state)
		{
			case 0:
			{
				//starting menu
				if (graphics::getKeyState(graphics::SCANCODE_SPACE))
				{
					state = 4;
					initialize(true);
					lastStateChange = graphics::getGlobalTime();
				}
				break;
			}
			case 1:
			{
				//settings
				break;
			}
			case 2:
			{
				//credits
				break;
			}
			case 3:
			{
				//intro
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
					if (it1->borderCheck() || it1->isDestroyed(projList, exList))
					{
						score += it1->getLevel() * 50;
						it1 = enList.erase(it1);
					}

					else
						++it1;
				}


				std::list <Explosion> ::iterator it2;
				for (it2 = exList.begin(); it2 != exList.end();)
				{
					it2->update();

					if (it2->shouldBeDestroyed())
					{
						it2 = exList.erase(it2);
					}
					else
						++it2;
				}

				if (square->isDestroyed(projList, enList, exList))
				{
					square->removeLife();
					if (square->getLifes() > 0)
						initialize(false);
					else
					{
						state = 6;
						lastStateChange = graphics::getGlobalTime();
					}
				}

				if (background->getY() >= 1200)
				{
					state = 5;
					lastStateChange = graphics::getGlobalTime();
				}

				break;
			}
			case 5:
			{
				if (graphics::getKeyState(graphics::SCANCODE_SPACE))
				{
					state = 0;
					lastStateChange = graphics::getGlobalTime();
				}
				break;
			}
			case 6:
			{
				if (graphics::getKeyState(graphics::SCANCODE_SPACE))
				{
					state = 0;
					lastStateChange = graphics::getGlobalTime();
				}
				break;
			}
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

void Game::initialize(bool fromScratch)
{
	if (fromScratch)
	{
		square = new PlayerPlane();
		background = new Background();
		score = 0;
	}
	else
	{
		square->setX(250);
		square->setY(800);
	}
	projList.clear();
	enList.clear();
}