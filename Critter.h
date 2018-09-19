#pragma once

// ---------- INCLUDES ------------------
#include <SFML/Graphics.hpp>
// ----------------------------------------


class Critter
{
	// ------ behaviour -----------
public:

	// constructor
	Critter();

	// render the critter to the target
	void Draw(sf::RenderTarget& _target);


	// ----- end behaviour ----------


	// ----------- data--------------
private:

	sf::Sprite m_sprite;    // m_ member of class
	sf::Texture m_texture;

	// ---------- end data ------------

}; // end critter class