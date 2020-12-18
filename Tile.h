#pragma once
#include <SFML/Graphics.hpp>

class Tile {

public:
	Tile(); //*****************************PAS BESOIN ?
	~Tile(); //*****************************PAS BESOIN ?

	void setObject(const sf::Texture* obj);
	sf::Sprite* getObject();

	void setLocation(sf::Vector2f newLocation);

	void setId(char c);
	char getId();
private:

	sf::Sprite m_object;
	sf::Vector2f m_location;
	char m_id;
};