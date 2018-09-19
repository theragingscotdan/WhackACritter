// ---------- INCLUDES -------------------
#include <SFML/Graphics.hpp>
#include <cstdlib>  // gives access to library func
#include <ctime>    // gives access to time func


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
	Critter victim;


	// ----- game setup end ----------------
	
	
 	// ----- game loop---------------
		   
	
	while (gameWindow.isOpen())
	{
		// ------ input -----------
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			// process input on critters
			victim.Input(event);

			if (event.type == sf::Event::Closed)
				gameWindow.close();
		} // end while



	
		// ------------ update ---------------




	// end update


	// ------------ draw --------------

	// clear to a single colour

		gameWindow.clear();

		//draw everything
		victim.Draw(gameWindow);
		
		// display the contents to screen
		gameWindow.display();


	// ----- end draw ----
	} // end of game while loop

	// exit point for program
	return 0;
} // end of main function
