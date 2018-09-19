// ---------- INCLUDES ------------------
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
	m_sprite.setPosition(300, 300);
}

void Critter::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprite);
}