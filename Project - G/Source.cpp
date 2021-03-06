#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<vector>

using namespace std;


int main()
{
	const int w = sf::VideoMode::getDesktopMode().width;
	const int h = sf::VideoMode::getDesktopMode().height;

	sf::RenderWindow window(sf::VideoMode(w, h), "PROJECT G", sf::Style::Fullscreen);

	window.setFramerateLimit(490);

	//Background 
	sf::Texture Background_texture;
	sf::Sprite Background;
	Background_texture.loadFromFile("Background/Background_1.jpg");
	Background.setTexture(Background_texture);

	//Intro Sounds
	sf::SoundBuffer intro_buff;
	intro_buff.loadFromFile("Audio/Intro01.wav");

	sf::Sound intro;
	intro.setBuffer(intro_buff);
	intro.setVolume(10.0f);
	intro.setLoop(true);

	//kill Sounds
	sf::SoundBuffer kill_buff;
	kill_buff.loadFromFile("Audio/Kill01.wav");

	sf::Sound kill;
	kill.setBuffer(kill_buff);
	kill.setVolume(10.0f);

	//kill Sounds
	sf::SoundBuffer Missile_buff_sound;
	Missile_buff_sound.loadFromFile("Audio/Missile01.wav");

	sf::Sound Missile_sound;
	Missile_sound.setBuffer(Missile_buff_sound);
	Missile_sound.setVolume(10.0f);


	//Fonts
	sf::Font Font1;
	Font1.loadFromFile("Fonts/FFF_Tusj.ttf");

	sf::Font Font2;
	Font2.loadFromFile("Fonts/KaushanScript-Regular.otf");

	sf::Font Font3;
	Font3.loadFromFile("Fonts/AlexBrush-Regular.ttf");

	//Display Contents	
	//For Main Menu

	sf::Text Name;
	Name.setFont(Font2);
	Name.setString(" UFO Shooter ");
	Name.setOutlineColor(sf::Color::Cyan);
	Name.setOutlineThickness(0.15f);
	Name.setCharacterSize(115);
	Name.setPosition(sf::Vector2f((w / 2 - (Name.getCharacterSize() * 3)) * 1.0f, (h / 7) * 1.0f));

	sf::Text Play;
	Play.setFont(Font1);
	Play.setString("Play");
	Play.setCharacterSize(125);
	Play.setPosition(sf::Vector2f((w / 2 - Play.getCharacterSize()) * 1.0f, (h / 2) * 1.0f));

	sf::Text Instructions;
	Instructions.setFont(Font1);
	Instructions.setString("Instructions");
	Instructions.setCharacterSize(75);
	Instructions.setPosition(sf::Vector2f((w / 2 - (Instructions.getCharacterSize() * 3)) * 1.0f, (h / 2 + Play.getCharacterSize() + 30) * 1.0f));

	sf::Text Exit;
	Exit.setFont(Font1);
	Exit.setString("Exit");
	Exit.setCharacterSize(75);
	Exit.setPosition(sf::Vector2f((w / 2 - Exit.getCharacterSize()) * 1.0f, (h / 2 + Instructions.getCharacterSize() + Play.getCharacterSize() + 60) * 1.0f));

	//For Gameover Screen
	sf::Text GameOver;
	GameOver.setFont(Font1);
	GameOver.setString("GameOver");
	GameOver.setOutlineColor(sf::Color::Cyan);
	GameOver.setOutlineThickness(0.15f);
	GameOver.setCharacterSize(100);
	GameOver.setPosition(sf::Vector2f((w / 2 + 10 - (GameOver.getCharacterSize() * 3)) * 1.0f, (h / 8 - 50) * 1.0f));

	sf::Text Comment1;
	Comment1.setFont(Font2);
	Comment1.setString("You lost !!");
	Comment1.setOutlineColor(sf::Color::Cyan);
	Comment1.setCharacterSize(125);
	Comment1.setPosition(sf::Vector2f((w / 2 + 10 - Comment1.getCharacterSize() * 2.25) * 1.0f, (h / 2 - 200) * 1.0f));

	sf::Text Comment2;
	Comment2.setFont(Font3);
	Comment2.setCharacterSize(40);
	Comment2.setString("You were not able to kill of them !!!, You ruined everyone's life  !! ");
	Comment2.setOutlineColor(sf::Color::Cyan);
	Comment2.setPosition(sf::Vector2f((w / 2 + 10 - Comment2.getCharacterSize() * 12) * 1.0f, (h - 300) * 1.0f));

	sf::Text Comment3;
	Comment3.setFont(Font3);
	Comment3.setCharacterSize(40);
	Comment3.setString("You need to take Revenge and Try again for Everyone ... ");
	Comment3.setOutlineColor(sf::Color::Cyan);
	Comment3.setPosition(sf::Vector2f((w / 2 + 10 - Comment3.getCharacterSize() * 10) * 1.0f, (h - 280 + Comment2.getCharacterSize()) * 1.0f));


	sf::Text Comment4;
	Comment4.setFont(Font2);
	Comment4.setString(" Press Escape key to Return ...");
	Comment4.setOutlineColor(sf::Color::Cyan);
	Comment4.setPosition(sf::Vector2f((w / 2 - Comment4.getCharacterSize() * 6) * 1.0f, (h - 30 - Comment4.getCharacterSize()) * 1.0f));

	sf::Text Comment5;
	Comment5.setFont(Font2);
	Comment5.setCharacterSize(38);
	Comment5.setString(" Out of Missiles !! You were not able to manage all the Missile carefully ....");
	Comment5.setOutlineColor(sf::Color::Cyan);
	Comment5.setPosition(sf::Vector2f((w / 2 - Comment5.getCharacterSize() * 15) * 1.0f, (h / 2 + 50) * 1.0f));

	sf::Text Comment6;
	Comment6.setFont(Font2);
	Comment6.setCharacterSize(35);
	Comment6.setString(" Time's up !! You were not able to Kill all of them in time ....");
	Comment6.setOutlineColor(sf::Color::Cyan);
	Comment6.setPosition(sf::Vector2f((w / 2 - Comment6.getCharacterSize() * 13) * 1.0f, (h / 2 + 50) * 1.0f));

	//For win screen
	sf::Text Win;
	Win.setFont(Font2);
	Win.setString("You Won !!");
	Win.setOutlineColor(sf::Color::Cyan);
	Win.setCharacterSize(125);
	Win.setPosition(sf::Vector2f((w / 2 + 10 - Win.getCharacterSize() * 2.8) * 1.0f, (h / 2 - 150) * 1.0f));

	sf::Text Congrats;
	Congrats.setFont(Font1);
	Congrats.setString("Congrats");
	Congrats.setOutlineColor(sf::Color::Cyan);
	Congrats.setOutlineThickness(0.15f);
	Congrats.setCharacterSize(100);
	Congrats.setPosition(sf::Vector2f((w / 2 + 10 - (Congrats.getCharacterSize() * 3.1)) * 1.0f, (h / 8 - 50) * 1.0f));

	sf::Text Comment7;
	Comment7.setFont(Font3);
	Comment7.setCharacterSize(40);
	Comment7.setString(" You defeated those creature and turned into a LEGEND !!! ");
	Comment7.setOutlineColor(sf::Color::Cyan);
	Comment7.setPosition(sf::Vector2f((w / 2 - Comment7.getCharacterSize() * 12) * 1.0f, (h - 250) * 1.0f));

	sf::Text Comment8;
	Comment8.setFont(Font3);
	Comment8.setCharacterSize(40);
	Comment8.setString(" You saved everyones life !!  and they all lived happily even after....");
	Comment8.setOutlineColor(sf::Color::Cyan);
	Comment8.setPosition(sf::Vector2f((w / 2 - Comment8.getCharacterSize() * 9) * 1.0f, (h - 230 + Comment7.getCharacterSize()) * 1.0f));

	//Instruction Page
	sf::Text Instruction_Heading;
	Instruction_Heading.setFont(Font1);
	Instruction_Heading.setString("Instructions");
	Instruction_Heading.setOutlineColor(sf::Color::Cyan);
	Instruction_Heading.setOutlineThickness(0.15f);
	Instruction_Heading.setCharacterSize(100);
	Instruction_Heading.setPosition(sf::Vector2f((w / 2 - (Instruction_Heading.getCharacterSize() * 3.1)) * 1.0f, (h / 8 - 50) * 1.0f));

	sf::Text Comment9;
	Comment9.setFont(Font2);
	Comment9.setString("These creatures are making our live's Hell !! !!!!! , so you need to destory all ");
	Comment9.setOutlineColor(sf::Color::Cyan);
	Comment9.setPosition(sf::Vector2f((w / 2 - Comment9.getCharacterSize() * 15) * 1.0f, (h / 8 + 50 + Instruction_Heading.getCharacterSize()) * 1.0f));

	sf::Text Comment10;
	Comment10.setFont(Font2);
	Comment10.setString(" in order to gain victory ! and save everybody's life ");
	Comment10.setOutlineColor(sf::Color::Cyan);
	Comment10.setPosition(sf::Vector2f((w / 2 - Comment10.getCharacterSize() * 10) * 1.0f, (h / 8 + 70 + Instruction_Heading.getCharacterSize() + Comment9.getCharacterSize()) * 1.0f));

	sf::Text Comment11;
	Comment11.setFont(Font3);
	Comment11.setCharacterSize(40);
	Comment11.setString(" Move Right and Left arrow key to move your Spaceship Right and Left respectively ...");
	Comment11.setOutlineColor(sf::Color::Cyan);
	Comment11.setPosition(sf::Vector2f((w / 8) * 1.0f, (h / 8 + 170 + Instruction_Heading.getCharacterSize() + Comment9.getCharacterSize() + Comment10.getCharacterSize()) * 1.0f));

	sf::Text Comment12;
	Comment12.setFont(Font3);
	Comment12.setString(" Use Space bar to shoot missiles and Destroy them ...");
	Comment12.setCharacterSize(40);
	Comment12.setOutlineColor(sf::Color::Cyan);
	Comment12.setPosition(sf::Vector2f((w / 8) * 1.0f, (h / 8 + 220 + Instruction_Heading.getCharacterSize() + Comment9.getCharacterSize() + Comment10.getCharacterSize() + Comment11.getCharacterSize()) * 1.0f));

	sf::Text Comment13;
	Comment13.setFont(Font3);
	Comment13.setString(" You have 24 Missiles in total to Destroy them all ...");
	Comment13.setCharacterSize(40);
	Comment13.setOutlineColor(sf::Color::Cyan);
	Comment13.setPosition(sf::Vector2f((w / 8) * 1.0f, (h / 8 + 270 + Instruction_Heading.getCharacterSize() + Comment9.getCharacterSize() + Comment10.getCharacterSize() + Comment11.getCharacterSize() + Comment12.getCharacterSize()) * 1.0f));

	sf::Text Comment14;
	Comment14.setFont(Font3);
	Comment14.setString(" You have only 20 seconds to Destroy all them ...");
	Comment14.setCharacterSize(40);
	Comment14.setOutlineColor(sf::Color::Cyan);
	Comment14.setPosition(sf::Vector2f((w / 8) * 1.0f, (h / 8 + 320 + Instruction_Heading.getCharacterSize() + Comment9.getCharacterSize() + Comment10.getCharacterSize() + Comment11.getCharacterSize() + Comment12.getCharacterSize() + Comment13.getCharacterSize()) * 1.0f));

	sf::Text Comment15;
	Comment15.setFont(Font2);
	Comment15.setString(" Press Escape key to Return ...");
	Comment15.setOutlineColor(sf::Color::Cyan);
	Comment15.setPosition(sf::Vector2f((w / 2 - Comment15.getCharacterSize() * 6) * 1.0f, (h - 30 - Comment15.getCharacterSize()) * 1.0f));

	//Bullets as serial no
	int no_of_bullets = 4;
	sf::Sprite* Bullets;
	sf::Texture Bullets_texture;
	Bullets_texture.loadFromFile("Sprites/Bullet_01.png");
	Bullets = new sf::Sprite[no_of_bullets];

	for (int i = 0; i < 4; i++)
	{
		Bullets[i].setTexture(Bullets_texture);
		Bullets[i].setPosition((w / 8 - 40 - Bullets_texture.getSize().x) * 1.0f, (h / 8 + Instruction_Heading.getCharacterSize() + 170 + 50 * i + 42 * (i + 2)) * 1.0f);
	}


	intro.play();
Play:      //Lable name for goto statement                                          


//Helpers
	int page = 0;
	int cause = 0;
	int win = 0;

	sf::Clock Game_Timer;   //Game timer

	// Spaceship  
	sf::Texture Spaceship_texture;
	Spaceship_texture.loadFromFile("Sprites/Spaceship_01.png");
	sf::Sprite Spaceship;
	Spaceship.setTexture(Spaceship_texture);
	float Spaceship_x_cor = (w / 2 - 56) * 1.0f;
	int spaceship_counter = 0;
	sf::Clock spaceship_clock;

	//Enemies

	//Enemies_01
	sf::Sprite* Enemy;
	sf::Texture Enemies_texture;
	Enemies_texture.loadFromFile("Sprites/Enemy_01.png");
	int no_of_enemies = 9;
	Enemy = new sf::Sprite[no_of_enemies];
	float Enemy_x_cor[9];
	float X_Counter[9] = { 0,0,0,0,0,0,0,0 };
	float Enemy_x = w / 2 * 1.0f;
	int Enemy_counter = 0;
	sf::Clock Enemy_clock;
	int Limit = 0;
	int count[9] = { 1,1,1,1,1,1,1,1,1 };

	//Enemies_02
	sf::Sprite* Enemy_02;
	sf::Texture Enemies_texture_02;
	Enemies_texture_02.loadFromFile("Sprites/Enemy_02.png");
	int no_of_enemies_02 = 9;
	Enemy_02 = new sf::Sprite[no_of_enemies_02];
	float Enemy_x_cor_02[9];
	float X_Counter_02[9] = { 0,0,0,0,0,0,0,0 };
	float Enemy_02_x = w / 2 * 1.0f;
	int Enemy_02_counter = 0;
	sf::Clock Enemy_02_clock;
	int Limit_02 = 0;
	int count_02[9] = { 1,1,1,1,1,1,1,1,1 };

	//Missiles
	sf::Sprite Missile;
	sf::Texture Missile_texture;
	Missile_texture.loadFromFile("Sprites/Missiles_001.png");
	vector<sf::Sprite> Missiles;
	Missiles.push_back(sf::Sprite(Missile));
	Missile.setTexture(Missile_texture);
	int Missile_counter = 0;
	sf::Clock Missile_clock;
	float Missile_y_cor = (h - h / 3.57209302) * 1.0f;
	int Shoot_timer = 0;
	int Missiles_count = 0;

	//score       
	int score = 0;
	char scorech[50];

	sf::Text scores;
	scores.setFont(Font2);
	scores.setOutlineColor(sf::Color::Cyan);
	scores.setPosition(sf::Vector2f((w - 60 - scores.getCharacterSize() * 6) * 1.0f, (25) * 1.0f));

	//Game_timer
	char timeleft[50];
	sf::Text time;
	time.setFont(Font2);
	time.setOutlineColor(sf::Color::Cyan);
	time.setPosition(sf::Vector2f((w / 2 - scores.getCharacterSize() * 5) * 1.0f, (25) * 1.0f));
	int time1;

	//Missilesleft
	char Missilesch[50];
	sf::Text Missiletxt;
	Missiletxt.setFont(Font2);
	Missiletxt.setOutlineColor(sf::Color::Cyan);
	Missiletxt.setPosition(sf::Vector2f((15 + Missiletxt.getCharacterSize() * 3) * 1.0f, (25) * 1.0f));



	//Window loop
	while (window.isOpen())
	{
		//Event for open window
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(Background);


		//Mouse initialization
		sf::Vector2i Mouseposition = sf::Mouse::getPosition(window);

		//Play selections from Menu
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Mouseposition.x > (w / 2.461261261261261) && Mouseposition.x < (w / 1.674019607843137) && Mouseposition.y >(h / 1.828571428571429) && Mouseposition.y < (h / 1.50293542074364))
		{
			page = 1;
			intro.stop();


			//insert background audio

			//Game loop
			while (window.isOpen())
			{

				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
				}

				window.clear();
				window.draw(Background);

				//Game condition
				if (Game_Timer.getElapsedTime().asSeconds() < 20.0f)
				{
					//Spaceship update
				Spaceship.setTextureRect({ spaceship_counter,0,112,114 });

				if (spaceship_clock.getElapsedTime().asSeconds() > 0.005f)
				{
					if (spaceship_counter < 225)
						spaceship_counter += 112;
					else
						spaceship_counter = 0;
					spaceship_clock.restart();

				}

				Spaceship.setPosition(sf::Vector2f(Spaceship_x_cor, (h - h / 6.144) * 1.0f));

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Spaceship_x_cor < (w - w / 11.77586206896552))
					Spaceship_x_cor++;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Spaceship_x_cor > 10)
					Spaceship_x_cor--;

				//Enemies_01 update
				for (int i = 1; i < 9; i++)
				{
					Enemy[i].setTexture(Enemies_texture);
					Enemy[i].setTextureRect({ Enemy_counter,0,75,93 });

					if (Enemy_clock.getElapsedTime().asSeconds() > 0.25f)
					{
						if (Enemy_counter < 375)
							Enemy_counter += 75;
						else
							Enemy_counter = 0;
						Enemy_clock.restart();

					}

					if (count[i] == 1)
						Enemy_x_cor[i] = (w/ 32.52380952380952 * i + (i-1)* (w/11.38333333333333))*1.0f;
					else
						Enemy_x_cor[i] = w * 2.0f;

					Enemy[i].setPosition(sf::Vector2f(Enemy_x_cor[i] + X_Counter[i], w/20.66));

					if (X_Counter[i] < 100 && Limit == 0)
					{
						X_Counter[i] += 0.26;
						if (X_Counter[i] > 100)
						{
							Limit = 1;
						}
					}
					else
					{
						X_Counter[i] -= 0.26;
						if (X_Counter[i] + Enemy_x_cor[i] == Enemy_x_cor[i])
							Limit = 0;
					}
				}

				//Enemy_02 update
				for (int i = 1; i < 9; i++)
				{
					Enemy_02[i].setTexture(Enemies_texture_02);
					Enemy_02[i].setTextureRect({ Enemy_02_counter,0,75,76});

					if (Enemy_02_clock.getElapsedTime().asSeconds() > 0.3f)
					{
						if (Enemy_02_counter < 375)
							Enemy_02_counter += 75;
						else
							Enemy_02_counter = 0;
						Enemy_02_clock.restart();

					}

					if (count_02[i] == 1)
						Enemy_x_cor_02[i] = (w/ 9.970802919708029 * i + (i-1)*(w/ 54.64))*1.0f;
					else
						Enemy_x_cor_02[i] = w * 2.0f;

					Enemy_02[i].setPosition(sf::Vector2f(Enemy_x_cor_02[i] - X_Counter_02[i], w/7.464));

					if (X_Counter_02[i] < 100 && Limit_02 == 0)
					{
						X_Counter_02[i] += 0.26;
						if (X_Counter_02[i] > 100)
						{
							Limit_02 = 1;
						}
					}
					else
					{
						X_Counter_02[i] -= 0.26;
						if (X_Counter_02[i] + Enemy_x_cor_02[i] == Enemy_x_cor_02[i])
							Limit_02 = 0;
					}
				}

				//Missile update
				Shoot_timer++;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && Shoot_timer >= 200 && Missiles_count < 23)
				{

					Missile_sound.play();
					Missile.setPosition(sf::Vector2f(Spaceship_x_cor + 35.0f, Missile_y_cor));
					Missiles.push_back(sf::Sprite(Missile));
					Shoot_timer = 0;
					Missiles_count++;
				}
				else
					if (!(Missiles_count <= 22))
					{
						cause = 1;
						break;
					}

				for (int i = 0; i < Missiles.size(); i++)
				{
					Missiles[i].move(0.0f, -3.0f);
				}

				//Collision between Missiles and Enemies

				//For Enemies_01
				for (int i = 0; i < Missiles.size(); i++)
					for (int j = 0; j < 9; j++)
						if (Missiles[i].getGlobalBounds().intersects(Enemy_02[j].getGlobalBounds()))
						{
							kill.play();
							score += 100;
							win++;
							count_02[j] = 0;
							Enemy_02[j].setPosition((w + 100) * 1.f, (h + 100) * 1.0f);
							Missiles.erase(Missiles.begin() + i);
							break;
						}

				//For Enemies_02
				for (int i = 0; i < Missiles.size(); i++)
					for (int j = 0; j < 9; j++)
						if (Missiles[i].getGlobalBounds().intersects(Enemy[j].getGlobalBounds()))
						{
							kill.play();
							score += 50;
							win++;
							count[j] = 0;
							Enemy[j].setPosition((w + 100) * 1.f, (h + 100) * 1.0f);
							Missiles.erase(Missiles.begin() + i);
							break;
						}

				if (win == 16)                                       //Win condition
				{
					break;
				}
				}
				else                                                 //Lose condition
				{
					cause = 2;
					break;
				}

				//Draawing Spaceship
				window.draw(Spaceship);

				//Drawing Enemies

				//Enemy_01
				for (int i = 1; i < 9; i++)
					window.draw(Enemy[i]);
				//Enemy_02
				for (int i = 1; i < 9; i++)
					window.draw(Enemy_02[i]);

				//Drawing Missiles
				for (int i = 0; i < Missiles.size(); i++)
					window.draw(Missiles[i]);



				//Calculate scores
				sprintf_s(scorech, "Score : %d", score);
				scores.setString(scorech);

				//Calculate Time left
				sf::Time Timer = Game_Timer.getElapsedTime();
				time1 = (int)Timer.asSeconds();
				sprintf_s(timeleft, "Time :  %d sec", 20 - time1);
				time.setString(timeleft);

				//Calculate Missiles left
				sprintf_s(Missilesch, "Missiles left:  %d ", 24 - Missiles_count);
				Missiletxt.setString(Missilesch);

				//Printing scores
				window.draw(scores);

				//Printing time
				window.draw(time);

				//printing Missile left
				window.draw(Missiletxt);

				window.display();

			}

		}

		//Instruction Selection From Menu
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Mouseposition.x > (w / 3.02212389380531) && Mouseposition.x < (w / 1.483170466883822) && Mouseposition.y >(h / 1.366548042704626) && Mouseposition.y < (h / 1.250814332247557))
		{
			page = 2;
		}

		//Exit Selection From Menu
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Mouseposition.x > (w / 2.280467445742905) && Mouseposition.x < (w / 1.783289817232376) && Mouseposition.y >(h / 1.156626506024096) && Mouseposition.y < (h / 1.069637883008357))
		{
			window.close();
		}

		//Drawing Comments,names etc
		if (page == 0)                                              //For Main Menu
		{
			window.draw(Name);
			window.draw(Play);
			window.draw(Instructions);
			window.draw(Exit);
		}
		else
			if (page == 2)                                             //For Instruction screen
			{
				for (int i = 0; i < 4; i++)
					window.draw(Bullets[i]);

				window.draw(Instruction_Heading);
				window.draw(Comment9);
				window.draw(Comment10);
				window.draw(Comment11);
				window.draw(Comment12);
				window.draw(Comment13);
				window.draw(Comment14);
				window.draw(Comment15);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					goto Play;
			}
			else
			{
				if (win == 16)                                         //For Win screen
				{
					window.draw(Win);
					window.draw(Congrats);
					window.draw(Comment7);
					window.draw(Comment8);
				}
				else
					if (page == 1)                                     //For Game Over screen
					{
						window.draw(GameOver);
						window.draw(Comment1);
						window.draw(Comment2);
						window.draw(Comment3);
						window.draw(Comment4);
						if (cause == 1)
							window.draw(Comment5);
						else
							if (cause == 2)
								window.draw(Comment6);
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
							goto Play;
					}

				//calc scores
				sprintf_s(scorech, "Score : %d", score);
				scores.setString(scorech);
				scores.setCharacterSize(40);

				//printing scores
				window.draw(scores);

			}


		window.display();
	}

	return 0;
}