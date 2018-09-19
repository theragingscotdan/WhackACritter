// ---------- INCLUDES ------------------
// library includes

#include <cstdlib>


// project includes
#include "Critter.h"
// ----------------------------------------

Critter::Critter()
	: m_sprite()
	, m_texture() // initialisation list
{
	// set up the sprite
	m_texture.loadFromFile("graphics/frog.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(rand() % sf::VideoMode::getDesktopMode().width,
		rand() % sf::VideoMode::getDesktopMode().height);
}

void Critter::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprite);
}