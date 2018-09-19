// ---------- INCLUDES -------------------
#include <SFML/Graphics.hpp>
#include <cstdlib>  // gives access to library func
#include <ctime>    // gives access to time func
#include <string>   // gives access to string funcs


#include "Critter.h"  // project includes
// ----------------------------------------


int main()
{
	// ------- game setup--------------------
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Whack a Critter",
		sf::Style::Titlebar | sf::Style::Close);


	sf::Clock gameClock;

	// seed our random number generator
	srand(time(NULL));

	// create an instance of our Critter class
	const int NUM_CRITTERS = 5;
	Critter victims[NUM_CRITTERS];
	victims[0].Setup("graphics/frog.png", 10000);
	victims[1].Setup("graphics/pig.png", 100);
	victims[2].Setup("graphics/crocodile.png", 5000);
	victims[3].Setup("graphics/bear.png", 300);
	victims[4].Setup("graphics/rhino.png", 1000);


	// game font
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");

	// score tracking
	int score = 0;
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(25);
	scoreText.setFillColor(sf::Color::Cyan);
	scoreText.setPosition(50, 50);

	// ----- game setup end ----------------
	
	
 	// ----- game loop---------------
		   
	
	while (gameWindow.isOpen())
	{
		// ------ input -----------
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			// process input on critters
		
			for (int i = 0; i < NUM_CRITTERS; ++i)
			{
				victims[i].Input(event);
			}

			if (event.type == sf::Event::Closed)
				gameWindow.close();
		} // end while



	
		// ------------ update ---------------

		sf::Time fameTime = gameClock.restart();
		for (int i = 0; i < NUM_CRITTERS; ++i)
		{
			score += victims[i].GetPendingScore();
			victims[i].ClearPendingScore();
		}
		
		scoreText.setString("Score: " + std::to_string(score));


	// end update


	// ------------ draw --------------

	// clear to a single colour

		gameWindow.clear();

		//draw everything
		
		for (int i = 0; i < NUM_CRITTERS; ++i)
		{
			victims[i].Draw(gameWindow);
		}
		
		gameWindow.draw(scoreText);
		
		
		// display the contents to screen
		gameWindow.display();


	// ----- end draw ----
	} // end of game while loop

	// exit point for program
	return 0;
} // end of main function
