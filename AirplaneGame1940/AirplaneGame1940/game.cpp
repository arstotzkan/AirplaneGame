#include "game.h"
#include <fstream>
#include <iostream>

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

	music = true;
	soundEffects = true;
	playerLifes = 3;
}

void Game::draw()
{
	switch (state)
	{
		case 0:
		{
			//starting menu
			std::string options[3] = { "PLAY", "SETTINGS", "CREDITS" };
			graphics::Brush br;
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			graphics::setFont("assets/fonts/Gill Sans.otf");
			graphics::drawText(50, 50, 60, "DAY OF THE EAGLE", br);

			for (int i = 0; i <= 2; i++)
			{
				br.fill_color[0] = 1.0f;
				br.fill_color[1] = 1.0f;
				br.fill_color[2] = 1.0f;

				if (i == subStateCounter1)
				{
					graphics::drawRect(200, 225 + (100 * i), 400, 100, br );

					br.fill_color[0] = 0.0f;
					br.fill_color[1] = 0.0f;
					br.fill_color[2] = 0.0f;
				}				
				graphics::drawText(50, 250 + (100 * i), 30, options[i], br);
			}
			break;
		}
		case 1:
		{
			//settings
			//std::string options[3] = { "LIVES", "MUSIC", "SOUND EFFECTS" };
			graphics::Brush br;
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			graphics::setFont("assets/fonts/Gill Sans.otf");
			graphics::drawText(50, 50, 45, "SETTINGS", br);
			
			std::string settings[3] = { "LIFES" , "MUSIC" , "SOUND EFFECTS" };
			std::string setup[3] = { "a", "b", "c" };
			setup[0] = std::to_string(playerLifes);
			
			if (music)
				setup[1] = "ON";
			else
				setup[1] = "OFF";

			if (soundEffects)
				setup[2] = "ON";
			else
				setup[2] = "OFF";


			for (int i = 0; i <= 2; i++)
			{
				br.fill_color[0] = 1.0f;
				br.fill_color[1] = 1.0f;
				br.fill_color[2] = 1.0f;

				if (i == subStateCounter1)
				{
					graphics::drawRect(200, 225 + (100 * i), 1000, 100, br);

					br.fill_color[0] = 0.0f;
					br.fill_color[1] = 0.0f;
					br.fill_color[2] = 0.0f;
				}
				graphics::drawText(50, 250 + (100 * i), 30, settings[i], br);
				graphics::drawText(350, 250 + (100 * i), 30, setup[i], br);
			}
			break;
		}
		case 2:
		{	
			//credits
			graphics::Brush br;
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;

			for (int i = 0; i < subStateCounter1; i++)
			{
				std::string temp = getLineFromText(i, "assets/credits.txt");
				graphics::setFont("assets/fonts/Gill Sans.otf");
				graphics::drawText(50, 50 *(i + 1), 18, temp, br);
			}
			
			std::string text = getLineFromText(subStateCounter1, "assets/credits.txt");

			int minimum = std::min(subStateCounter2 / 3, (int)text.length());
		
			graphics::setFont("assets/fonts/Gill Sans.otf");

			graphics::drawText(50 , 50 * (subStateCounter1 + 1) , 18, text.substr(0, minimum), br);

			if (subStateCounter2 / 3 == (int)text.length() && subStateCounter1 < 5)
			{
				subStateCounter1++;
				subStateCounter2 = 0;
			}

			break;
		}
		case 3:
		{
			std::string text = getLineFromText(subStateCounter1, "assets/story.txt");
			std::string img = "assets/events/intro" + std::to_string(subStateCounter1 + 1) + ".png";

			graphics::Brush br;
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			br.texture = img;
			graphics::drawRect(300, 200, 400, 250, br);

			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			int minimum = std::min(subStateCounter2 / 3, (int) text.length());

			graphics::setFont("assets/fonts/Gill Sans.otf");
			graphics::drawText(50, 400, 18, text.substr(0, minimum), br);
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
			graphics::drawRect(300, 50, 600, 100, br);

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
			graphics::drawRect(300, 300, 400, 250, br1);

			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			std::string quote = "Never was so much owed by so many to so few.";
			int minimum = std::min(subStateCounter1 / 3, (int)quote.length() );
			graphics::drawText(50, 600, 20, quote.substr(0, minimum), br);
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
			graphics::drawRect(300, 300, 400, 250, br);

			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			std::string quote = "We shall never surrender!";
			int minimum = std::min(subStateCounter1 / 3, (int) quote.length());
			graphics::drawText(50, 600, 20, quote.substr(0, minimum), br);
			break;
		}
	}
}

void Game::update(float ms)
{
	if (graphics::getGlobalTime() - lastStateChange > 200.0f)
	{
		switch (state)
		{
			case 0:
			{
				//starting menu
				if (graphics::getKeyState(graphics::SCANCODE_UP) && subStateCounter1 > 0)
				{
					subStateCounter1--;
					graphics::playSound("assets/sound/button.mp3", 0.33f * soundEffects);
					lastStateChange = graphics::getGlobalTime();
				}

				if (graphics::getKeyState(graphics::SCANCODE_DOWN) && subStateCounter1 < 2)
				{
					subStateCounter1++;
					graphics::playSound("assets/sound/button.mp3", 0.33f * soundEffects);
					lastStateChange = graphics::getGlobalTime();
				}

				if (graphics::getKeyState(graphics::SCANCODE_RETURN))
				{
					graphics::playSound("assets/sound/button.mp3", 0.33f * soundEffects);
					if (subStateCounter1 != 0)
						setState(subStateCounter1);
					else
						setState(3);
					lastStateChange = graphics::getGlobalTime();
				}
				break;
			}
			case 1:
			{
				//settings
				if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE))
				{
					graphics::playSound("assets/sound/button.mp3", 0.33f * soundEffects);
					setState(0);
				}

				if (graphics::getKeyState(graphics::SCANCODE_UP) && subStateCounter1 > 0)
				{
					subStateCounter1--;
					graphics::playSound("assets/sound/button.mp3", 0.33f * soundEffects);
					lastStateChange = graphics::getGlobalTime();
				}

				if (graphics::getKeyState(graphics::SCANCODE_DOWN) && subStateCounter1 < 2)
				{
					subStateCounter1++;
					graphics::playSound("assets/sound/button.mp3", 0.33f * soundEffects);
					lastStateChange = graphics::getGlobalTime();
				}
				
				if (graphics::getKeyState(graphics::SCANCODE_LEFT))
				{
					switch (subStateCounter1)
					{
						case 0:
						{
							if (playerLifes >= 3)
								playerLifes -= 2;
						}
						case 1:
						{
							music = true;
							break;
						}
						case 2:
						{
							soundEffects = true;
							break;
						}
					}

					lastStateChange = graphics::getGlobalTime();
				}

				if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
				{
					graphics::playSound("assets/sound/button.mp3", 0.33f * soundEffects);

					switch (subStateCounter1)
					{
						case 0:
						{
							if (playerLifes <= 3)
								playerLifes += 2;
							break;
						}
						case 1:
						{
							music = false;
							break;
						}
						case 2:
						{
							soundEffects = false;
							break;
						}
					}
					lastStateChange = graphics::getGlobalTime();
				}

				break;
			}
			case 2:
			{
				if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE))
				{
					graphics::playSound("assets/sound/button.mp3", 0.33f * soundEffects);
					setState(0);
				}

				subStateCounter2++;
				break;
			}
			case 3:
			{
				subStateCounter2++;
				if (graphics::getKeyState(graphics::SCANCODE_RETURN))
				{
					subStateCounter1++;
					subStateCounter2 = 0;
					lastStateChange = graphics::getGlobalTime();
					if (subStateCounter1 == 7)
					{
						setState(4);
						initialize(true);
					}
				}
				break;
			}

			case 4:
			{
				//normal game
				background->update();
				square->update(projList, soundEffects);
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
					if (it1->borderCheck() || it1->isDestroyed(projList, exList, soundEffects))
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

				if (square->isDestroyed(projList, enList, exList, soundEffects))
				{
					square->removeLife();
					if (square->getLifes() > 0)
						initialize(false);
					else
					{
						setState(6);
					}
				}

				if (background->borderCheck())
				{
					setState(5);
					lastStateChange = graphics::getGlobalTime();
				}

				break;
			}
			case 5:
			{
				subStateCounter1++;
				if (graphics::getKeyState(graphics::SCANCODE_RETURN))
				{
					setState(0);
				}
				break;
			}
			case 6:
			{
				subStateCounter1++;
				if (graphics::getKeyState(graphics::SCANCODE_RETURN))
				{
					setState(0);
				}
				break;
			}
		}
	}
}

void Game::setState(int x)
{
	state = x;
	subStateCounter1 = 0;
	subStateCounter2 = 0;
	lastStateChange = graphics::getGlobalTime();
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
		square = new PlayerPlane(playerLifes);
		background = new Background();
		score = 0;
	}

	square->setX(300);
	square->setY(900);
	projList.clear();
	enList.clear();
}




std::string getLineFromText(int x, const char* file_name)
{
	std::string line;
	std::ifstream file(file_name);
	int i = 0;
	if (!file.is_open())
	{
		std::cout << "ERROR" << std::endl;
	}
	else
	{
		while (std::getline(file, line) && i < x)
		{
			i++;
		}
		file.close();
		return line;
	}
}