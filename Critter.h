#pragma once

// ---------- INCLUDES ------------------
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
// ----------------------------------------


class Critter
{
	// ------ behaviour -----------
public:

	// constructor
	Critter();

	// render the critter to the target
	void Draw(sf::RenderTarget& _target);

	 // process input on the Critter
	void Input(sf::Event _gameEvent);
	
	//
	int GetPendingScore();

	// clear pending score
	void ClearPendingScore();

	// set the critter type
	void Setup(std::string _textureFile, int _pointValue);
	// ----- end behaviour ----------


	// ----------- data--------------
private:

	sf::Sprite m_sprite;    // m_ member of class
	sf::Texture m_texture;
	bool m_alive;
	sf::Sound m_deathSound;
	sf::SoundBuffer m_deathBuffer;
	int m_pendingScore;
	int m_scoreValue;
	// ---------- end data ------------

}; // end critter class