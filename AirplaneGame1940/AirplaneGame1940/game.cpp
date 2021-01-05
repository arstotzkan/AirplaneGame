#include "game.h"
#include <fstream>
#include <iostream>

#define LOADING_SCREEN 0
#define MAIN_MENU 1
#define SETTINGS 2
#define CONTROLS 3
#define CREDITS 4
#define INTRO 5
#define MAIN_GAME 6
#define SCREEN_FREEZE 7
#define VICTORY 8
#define DEFEAT 9

Game::Game()
{
	//CONSTRUCTOR
	music = true;
	soundEffects = true;

	subStateCounter1 = 0;
	subStateCounter2 = 0;

	squadron = new PlayerSquadron();
	projList;
	enList;
	upList;
	enemyCreator;
	background = new Background();
	score = 0;

	paused = false;

	gameTime = 0.0f;

	playerLifes = 3;
	initialLifes = 3;

	state = LOADING_SCREEN;

}

void Game::draw()
{
	//zwgrafisei stin othoni analoga me to gameState
	switch (state)
	{
		case LOADING_SCREEN:
		{
			//to proto pragma pou vlepei o xrhsths
			//yparxei mono kai mono gia na paizei mousikh sto main menu
			graphics::Brush br;
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			graphics::setFont("assets/fonts/Gill Sans.otf");
			std::string txt = "LOADING...";
			graphics::drawText(230, 300, 30, txt.substr(0, 7 + (subStateCounter1 / 25 ) % 4) ,br);
			break;
		}

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
			//paromoio me to start menu

			graphics::Brush br;
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			graphics::setFont("assets/fonts/Gill Sans.otf");
			graphics::drawText(50, 50, 45, "SETTINGS", br);
			
			std::string settings[3] = { "LIFES" , "MUSIC" , "SOUND EFFECTS" };
			std::string setup[3] = { "a", "b", "c" };
			setup[0] = std::to_string(initialLifes);
			
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

			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			graphics::drawText(50, 900, 12, "BACKSPACE: GO BACK , ENTER: SKIP", br);
			break;
		}
		case CONTROLS:
		{
			//deixnei ta controls gia to paixnidi
			graphics::Brush br;
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;

			for (int i = 0; i < subStateCounter1; i++)
			{
				std::string temp = getLineFromText(i, "assets/text/controls.txt");
				graphics::setFont("assets/fonts/Gill Sans.otf");
				graphics::drawText(50, 50 * (i + 1), 18, temp, br);
			}

			std::string text = getLineFromText(subStateCounter1, "assets/text/controls.txt");

			int minimum = std::min(subStateCounter2 / 3, (int)text.length());

			graphics::setFont("assets/fonts/Gill Sans.otf");

			if (minimum < (int)text.length())
				graphics::playSound("assets/sound/typewriter.mp3", 0.25f * soundEffects);

			graphics::drawText(50, 50 * (subStateCounter1 + 1), 18, text.substr(0, minimum), br);

			if (subStateCounter2 / 3 == (int)text.length() && subStateCounter1 < 3)
			{
				subStateCounter1++;
				subStateCounter2 = 0;
			}

			graphics::drawText(50, 900, 12, "BACKSPACE: GO BACK", br);
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
				std::string temp = getLineFromText(i, "assets/text/credits.txt");
				graphics::setFont("assets/fonts/Gill Sans.otf");
				graphics::drawText(50, 50 *(i + 1), 18, temp, br);
			}
			
			std::string text = getLineFromText(subStateCounter1, "assets/text/credits.txt");

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

			graphics::drawText(50, 900, 12, "BACKSPACE: GO BACK", br);
			break;
		}
		case INTRO:
		{
			//introduction
			//deixnei keimeno me typewritter effect
			//kai deixnei tin eikona
			std::string text = getLineFromText(subStateCounter1, "assets/text/story.txt");
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

			graphics::drawText(50, 900, 12, "LEFT: PREVIOUS SLIDE , RIGHT: NEXT SLIDE, BACKSPACE: GO BACK , ENTER: SKIP", br);
			break;
		}
		case SCREEN_FREEZE:
		{
			//pausi othonis
			//paused -> to main paixnidi exei stamathsei
			if (paused)
			{
				graphics::Brush br;
				br.fill_color[0] = 0.0f;
				br.fill_color[1] = 0.0f;
				br.fill_color[2] = 0.0f;
				graphics::setFont("assets/fonts/Gill Sans.otf");
				graphics::drawText(250, 200, 30, "PAUSED", br);
			}
		}
		case MAIN_GAME:
		{
			//normal game
			//zwgrafizei aeroplana, ekrikseis, power-up, kai projectiles

			background->draw();
			
			if (playerLifes > 0)
			 squadron->draw();
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

			std::list <PowerUp> ::iterator it3;
			for (it3 = upList.begin(); it3 != upList.end(); ++it3)
			{
				it3->draw();
			}


			graphics::Brush br;
			br.fill_color[0] = 0.0f;
			br.fill_color[1] = 0.0f;
			br.fill_color[2] = 0.0f;
			br.outline_opacity = 0.0f;
			graphics::drawRect(300, 50, 600, 100, br);

			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;

			graphics::setFont("assets/fonts/Gill Sans.otf");
			std::string text1 = "SCORE: " + std::to_string(score);
			std::string text2 = "LIVES: " + std::to_string(playerLifes);
			graphics::drawText(50, 50, 25, text1, br);
			graphics::drawText(300, 50, 25, text2, br);
			break;
		}
		case VICTORY:
		{
			//victory screen
			//xaroumenh eikona kai xaroumeno quote
			graphics::Brush br;
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			graphics::setFont("assets/fonts/Gill Sans.otf");
			graphics::drawText(230, 50, 30, "VICTORY", br);

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
			//lyphterh eikona kai lyphtero quote
			graphics::Brush br;
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			graphics::setFont("assets/fonts/Gill Sans.otf");
			graphics::drawText(230, 50, 30, "DEFEAT", br);
			
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
	if (graphics::getGlobalTime() - lastStateChange > 200.0f) //gia na min ginontai oi allages ypervolika grhgora
	{
		switch (state)
		{
			case LOADING_SCREEN:
			{
				subStateCounter1++;
				//apla perimenei mexri na anoixtei to main menu
				if (graphics::getGlobalTime() > 2000.0f)
					setState(MAIN_MENU);

				break;
			}
			case MAIN_MENU:
			{
				//starting menu
				//to highlighted option paei panw katw analoga me to input tou xrhsth
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
						setState(subStateCounter1 + 1);
					else
						setState(INTRO);
					lastStateChange = graphics::getGlobalTime();
				}
				break;
			}
			case SETTINGS:
			{
				//settings
				//paromoio me to menu, apla allazeis kai option an patas aristera/dexia veli
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
							if (initialLifes >= 3)
								initialLifes -= 2;
							else
								initialLifes = 5;
							break;
						}
						case 1:
						{
							music = !(music);

							if (music)
								graphics::playMusic("assets/music/Menu.mp3", 0.25f * music, true, 2000);
							else
								graphics::stopMusic();

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
							if (initialLifes <= 3)
								initialLifes += 2;
							else
								initialLifes = 1;

							break;
						}
						case 1:
						{
							music = !(music);

							if (music)
								graphics::playMusic("assets/music/Menu.mp3", 0.25f * music, true, 2000);
							else
								graphics::stopMusic();

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
				//to subStateCounter2 voithaei gia to typing effect
				//kai epistrofi sto main menu
				if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE))
				{
					graphics::playSound("assets/sound/button.mp3", 0.33f * soundEffects);
					setState(MAIN_MENU);
				}
				subStateCounter2++;
				break;
			}
			case CREDITS:
			{
				//to subStateCounter2 voithaei gia to typing effect
				//kai epistrofi sto main menu
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
				//typing effect kai anamoni gia input (epistrofi, skip, synexeia stin epomenh eikona)
				subStateCounter2++;
				if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
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

				if (graphics::getKeyState(graphics::SCANCODE_LEFT))
				{
					subStateCounter1--;
					subStateCounter2 = 0;
					lastStateChange = graphics::getGlobalTime();
					if (subStateCounter1 == -1)
					{
						setState(MAIN_MENU);
					}
				}

				if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE))
				{
					setState(MAIN_MENU);
				}

				if (graphics::getKeyState(graphics::SCANCODE_RETURN))
				{
					setState(MAIN_GAME);
					initialize(true);
				}

				break;
			}

			case MAIN_GAME:
			{
				//normal game
				//allages sta aeroplana, projectiles, ekrikseis kai power-up
				gameTime += graphics::getDeltaTime();

				background->update();
				squadron->update(projList, upList,  soundEffects, gameTime);

				if (squadron->getLevel() > 4)
				{
					squadron->setLevel(4);
					playerLifes++;
				}


				enemyCreator->update(enList, upList, gameTime);
		
				std::list <EnemyPlane> ::iterator it1;
				for (it1 = enList.begin(); it1 != enList.end();)
				{
					it1->update(projList, soundEffects);
					if (it1->borderCheck() || it1->isDestroyed(projList, exList, soundEffects))
					{
						if (!it1->borderCheck())
						{
							score += it1->getLevel() * 50;
						}

						it1 = enList.erase(it1);
					}


					else
						++it1;
				}

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

				std::list <PowerUp> ::iterator it3;
				for (it3 = upList.begin(); it3 != upList.end();)
				{
					it3->update();

					if (it3->borderCheck())
					{
						it3 = upList.erase(it3);
					}
					else
						++it3;
				}

				if (squadron->isDestroyed(projList, enList, exList, soundEffects)) //katastrofi lead plane
				{
					playerLifes--;
					if (playerLifes > 0)
						initialize(false); //reinitalization
					else //loss condition
					{
						Explosion* ex = new Explosion(squadron->getX(), squadron->getY(), 100.0f);
						exList.push_back(*ex);
						delete ex;
						ex = nullptr;
						setState(SCREEN_FREEZE);
					}
				}
				
				if (background->borderCheck()) //victory condition
				{
					setState(SCREEN_FREEZE);
					lastStateChange = graphics::getGlobalTime();
				}

				if (graphics::getKeyState(graphics::SCANCODE_P)) //pausi
				{
					paused = true;
					setState(SCREEN_FREEZE);
				}

				break;
			}
			case SCREEN_FREEZE:
			{
				//perimenei unpause, i an oi zwes tou paikti einai mikroteres tou 0, apla deixnei tin ekriksi
				//an o paiktis nikise to paixnidi, to paixnidi kanei ta aparaithta victory animation
				if (graphics::getKeyState(graphics::SCANCODE_P) && paused)
				{
					paused = false;
					setState(MAIN_GAME);
				}

				if (playerLifes == 0 )
				{
					if (graphics::getGlobalTime() - lastStateChange < 2000.0f)
					{
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
					}
					else
						setState(DEFEAT);
				}

				if (background->borderCheck())
				{
					if (graphics::getGlobalTime() - lastStateChange < 2000.0f)
					{
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

						float temp_y = squadron->getY();
						temp_y -= 300 * graphics::getDeltaTime() / 333;
						if (temp_y >= 30)
							squadron->setY(temp_y);


						float temp_x = squadron->getX();
						if (temp_x > 300)
						{
							temp_x -= 300 * graphics::getDeltaTime() / 333;
							squadron->setX(temp_x);
						}
						else if (temp_x < 300)
						{
							temp_x += 300 * graphics::getDeltaTime() / 333;
							squadron->setX(temp_x);
						}

					}

					else
						setState(VICTORY);
				}

				break;
			}
			case VICTORY:
			{
				//anamoni inout, typing effect
				subStateCounter1++;
				if (graphics::getKeyState(graphics::SCANCODE_RETURN))
				{
					setState(MAIN_MENU);
				}
				break;
			}
			case DEFEAT:
			{
				//anamoni inout, typing effect
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
	//thethei state
	subStateCounter1 = 0;
	subStateCounter2 = 0;
	lastStateChange = graphics::getGlobalTime();

	switch (x)
	{
		//to switch stamataei tin mousiki, kai arxisei to allo tragoudi
		case MAIN_MENU:
		{
			if (state != SETTINGS && state != CONTROLS && state != CREDITS)
			{
				graphics::stopMusic();
				graphics::playMusic("assets/music/Menu.mp3", 0.25f * music, true, 2000);
			}
			break;
		}
		case MAIN_GAME:
		{
			if (state != SCREEN_FREEZE)
			{
				graphics::stopMusic();
				graphics::playMusic("assets/music/Main.mp3", 0.25f * music, true);
			}
			break;
		}
		case VICTORY:
		{
			graphics::stopMusic();
			graphics::playMusic("assets/music/Victory.mp3", 0.25f * music, true);
			break;
		}
		case DEFEAT:
		{
			graphics::stopMusic();
			graphics::playMusic("assets/music/Defeat.mp3", 0.25f * music, true);
			break;
		}

	}
	state = x;

}

Game::~Game()
{
	//destructor
	delete squadron;
	delete enemyCreator;
	delete background;
}

void Game::initialize(bool fromScratch)
{
	//arxikopoihsh tou paixnidiou
	if (fromScratch)
	{
		//ginetai stin arxi tou paixnidiou
		squadron = new PlayerSquadron();
		background = new Background();
		score = 0;
		enemyCreator = new Factory();
		playerLifes = initialLifes;
		gameTime = 0.0f;

		Explosion* temp = new Explosion(-900, -600); //fixed bug with 1st explosion (some pics would not load immidiately)
		exList.push_back(*temp);
		delete temp;
		temp = nullptr;
	}
	else
	{
		//ginetai otan xanei zwi o paiktis
		if (squadron->getLevel() > 2)
			squadron = new PlayerSquadron(2);
		else
			squadron = new PlayerSquadron();
	}
	//square->setX(300);
	//square->setY(900);
	projList.clear();
	enList.clear();
	upList.clear();
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