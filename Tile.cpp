#include "Tile.h"

Tile::Tile()
{
}

Tile::~Tile()
{
}

void Tile::setObject(const sf::Texture* obj)
{
	m_object.setTexture(*obj);
}

sf::Sprite* Tile::getObject()
{
	return &m_object;
}

void Tile::setLocation(sf::Vector2f newLocation)
{
	m_location = newLocation;
	m_object.setPosition(m_location);
}

void Tile::setId(char c)
{
	m_id = c;
}

char Tile::getId()
{
	return m_id;
}
