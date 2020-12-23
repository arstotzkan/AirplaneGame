#include "game.h"
#include <fstream>
#include <iostream>

#define MAIN_MENU 0
#define SETTINGS 1
#define CONTROLS 2
#define CREDITS 3
#define INTRO 4
#define MAIN_GAME 5
#define VICTORY 6
#define DEFEAT 7

Game::Game()
{
	state = MAIN_GAME;
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
		case MAIN_MENU:
		{
			//starting menu
			std::string options[4] = { "PLAY", "SETTINGS", "CONTROLS" , "CREDITS" };
			graphics::Brush br;
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			graphics::setFont("assets/fonts/Gill Sans Bold.otf");
			graphics::drawText(50, 50, 60, "DAY OF THE EAGLE", br);

			graphics::setFont("assets/fonts/Gill Sans.otf");
			for (int i = 0; i <= 3; i++)
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
		case SETTINGS:
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
		case CONTROLS:
		{
			graphics::setFont("assets/fonts/Gill Sans.otf");
			graphics::Brush br;
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			graphics::drawText(50, 250, 60, "PLACEHOLDER", br);
			break;
		}
		case CREDITS:
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

			if (minimum < (int) text.length())
				graphics::playSound("assets/sound/typewriter.mp3", 0.25f * soundEffects);

			graphics::drawText(50 , 50 * (subStateCounter1 + 1) , 18, text.substr(0, minimum), br);

			if (subStateCounter2 / 3 == (int)text.length() && subStateCounter1 < 5)
			{
				subStateCounter1++;
				subStateCounter2 = 0;
			}

			break;
		}
		case INTRO:
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

			if (minimum < (int)text.length())
				graphics::playSound("assets/sound/typewriter.mp3", 0.25f * soundEffects);

			graphics::setFont("assets/fonts/Gill Sans.otf");
			graphics::drawText(50, 400, 18, text.substr(0, minimum), br);
			break;
		}
		case MAIN_GAME:
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
		case VICTORY:
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

			std::string quote = "Never was so much owed by so many to so few.";

			int minimum = std::min(subStateCounter1 / 3, (int)quote.length() );

			if (minimum < (int)quote.length())
				graphics::playSound("assets/sound/typewriter.mp3", 0.25f * soundEffects);

			graphics::drawText(50, 600, 20, quote.substr(0, minimum), br);
			break;
		}
		case DEFEAT:
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

			std::string quote = "We shall never surrender!";

			int minimum = std::min(subStateCounter1 / 3, (int) quote.length());

			if (minimum < (int)quote.length())
				graphics::playSound("assets/sound/typewriter.mp3", 0.25f * soundEffects);

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
			case MAIN_MENU:
			{
				//starting menu
				if (graphics::getKeyState(graphics::SCANCODE_UP))
				{
					if (subStateCounter1 > 0)
						subStateCounter1--;
					else
						subStateCounter1 = 3;

					graphics::playSound("assets/sound/button.mp3", 0.33f * soundEffects);
					lastStateChange = graphics::getGlobalTime();
				}

				if (graphics::getKeyState(graphics::SCANCODE_DOWN))
				{
					if (subStateCounter1 < 3)
						subStateCounter1++;
					else
						subStateCounter1 = 0;

					graphics::playSound("assets/sound/button.mp3", 0.33f * soundEffects);
					lastStateChange = graphics::getGlobalTime();
				}

				if (graphics::getKeyState(graphics::SCANCODE_RETURN))
				{
					graphics::playSound("assets/sound/button.mp3", 0.33f * soundEffects);
					if (subStateCounter1 != 0)
						setState(subStateCounter1);
					else
						setState(INTRO);
					lastStateChange = graphics::getGlobalTime();
				}
				break;
			}
			case SETTINGS:
			{
				//settings
				if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE))
				{
					graphics::playSound("assets/sound/button.mp3", 0.33f * soundEffects);
					setState(MAIN_MENU);
				}

				if (graphics::getKeyState(graphics::SCANCODE_UP))
				{
					if (subStateCounter1 > 0)
						subStateCounter1--;
					else
						subStateCounter1 = 2;

					graphics::playSound("assets/sound/button.mp3", 0.33f * soundEffects);
					lastStateChange = graphics::getGlobalTime();
				}

				if (graphics::getKeyState(graphics::SCANCODE_DOWN))
				{
					if (subStateCounter1 < 2)
						subStateCounter1++;
					else
						subStateCounter1 = 0;

					graphics::playSound("assets/sound/button.mp3", 0.33f * soundEffects);
					lastStateChange = graphics::getGlobalTime();
				}
				
				if (graphics::getKeyState(graphics::SCANCODE_LEFT))
				{
					graphics::playSound("assets/sound/button.mp3", 0.33f * soundEffects);
					switch (subStateCounter1)
					{
						case 0:
						{
							if (playerLifes >= 3)
								playerLifes -= 2;
							else
								playerLifes = 5;
							break;
						}
						case 1:
						{
							music = !(music);
							break;
						}
						case 2:
						{
							soundEffects = !(soundEffects);
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
							else
								playerLifes = 1;

							break;
						}
						case 1:
						{
							music = !(music);
							break;
						}
						case 2:
						{
							soundEffects = !(soundEffects);
							break;
						}
					}
					lastStateChange = graphics::getGlobalTime();
				}

				break;
			}
			case CONTROLS:
			{
				if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE))
				{
					graphics::playSound("assets/sound/button.mp3", 0.33f * soundEffects);
					setState(MAIN_MENU);
				}
				break;
			}
			case CREDITS:
			{
				if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE))
				{
					graphics::playSound("assets/sound/button.mp3", 0.33f * soundEffects);
					setState(MAIN_MENU);
				}

				subStateCounter2++;
				break;
			}
			case INTRO:
			{
				subStateCounter2++;
				if (graphics::getKeyState(graphics::SCANCODE_RETURN))
				{
					subStateCounter1++;
					subStateCounter2 = 0;
					lastStateChange = graphics::getGlobalTime();
					if (subStateCounter1 == 7)
					{
						setState(MAIN_GAME);
						initialize(true);
					}
				}
				break;
			}

			case MAIN_GAME:
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
						setState(DEFEAT);
					}
				}

				if (background->borderCheck())
				{
					setState(VICTORY);
					std::cout << graphics::getGlobalTime() - lastStateChange << std::endl;
					std::cout << enemyCreator->getCounter() <<std::endl;
					lastStateChange = graphics::getGlobalTime();
				}

				break;
			}
			case VICTORY:
			{
				subStateCounter1++;
				if (graphics::getKeyState(graphics::SCANCODE_RETURN))
				{
					setState(MAIN_MENU);
				}
				break;
			}
			case DEFEAT:
			{
				subStateCounter1++;
				if (graphics::getKeyState(graphics::SCANCODE_RETURN))
				{
					setState(MAIN_MENU);
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

		Explosion* temp = new Explosion(-900, -600); //fixed bug with 1st explosion (some pics would not load immidiately)
		exList.push_back(*temp);
		delete temp;
		temp = nullptr;
	}

	//square->setX(300);
	//square->setY(900);
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