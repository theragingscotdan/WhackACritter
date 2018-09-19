// ---------- INCLUDES ------------------

// ----------------------------------------

#include <SFML/Graphics.hpp>
int main()
{
	// ------- game setup--------------------
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Whack a Critter",
		sf::Style::Titlebar | sf::Style::Close);


	sf::Clock gameClock;


	// ----- game setup end ----------------
	
	
 	// ----- game loop---------------
		   
	
	while (gameWindow.isOpen())
	{
		// ------ input -----------
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gameWindow.close();
		} // end while



	
		// ------------ update ---------------




	// end update


	// draw

	// clear to a single colour

		gameWindow.clear();
		
		gameWindow.display();

	// ----- end draw ----
	} // end of game while loop

	// exit point for program
	return 0;
} // end of main function
