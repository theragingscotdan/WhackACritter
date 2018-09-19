// ---------- INCLUDES ------------------
// library includes

#include <cstdlib>


// project includes
#include "Critter.h"
// ----------------------------------------

Critter::Critter()
	: m_sprite()
	, m_texture() // initialisation list
	, m_alive(true)
	, m_deathSound()
	, m_deathBuffer()
	, m_pendingScore(0)
	, m_scoreValue(1)
	
{
	
	
	m_deathBuffer.loadFromFile("audio/buttonclick.ogg");
	m_deathSound.setBuffer(m_deathBuffer);
}

void Critter::Draw(sf::RenderTarget& _target)
{
	if (m_alive) // only draw our sprite if we are alive
	{
		_target.draw(m_sprite);
	}
}

 // ----- input

void Critter::Input(sf::Event _gameEvent)
{
	// only handle input if alive
	if (m_alive)
	{
	// check if this event is a click
		if (_gameEvent.type == sf::Event::MouseButtonPressed)
		{
			// did they click on this critter
			if (m_sprite.getGlobalBounds().contains(_gameEvent.mouseButton.x, _gameEvent.mouseButton.y))
			{
				// they clicked it!
				// we die
				m_alive = false;

				//play the death sound
				m_deathSound.play();

				// add to pending score
				m_pendingScore += m_scoreValue;
			}
		}
	}
}

int Critter::GetPendingScore()
{
	return m_pendingScore;
}

void Critter::ClearPendingScore()
{
	m_pendingScore = 0;
}

void Critter::Setup(std::string _textureFile, int _pointValue)
{
	// set up the sprite
	m_texture.loadFromFile(_textureFile);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(rand() % sf::VideoMode::getDesktopMode().width,
		rand() % sf::VideoMode::getDesktopMode().height);

	m_scoreValue = _pointValue;

}