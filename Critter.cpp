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
	
{
	// set up the sprite
	m_texture.loadFromFile("graphics/frog.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(rand() % sf::VideoMode::getDesktopMode().width,
		rand() % sf::VideoMode::getDesktopMode().height);
	
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
			}
		}
	}
}