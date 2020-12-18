#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Button {

public:
	Button();
	~Button();

	void setLocation(sf::Vector2f newLocation);

	void setImage(sf::Sprite* image);
	sf::Sprite* getImage();

	void setAction(sf::Sprite* action);
	sf::Sprite* getAction();

	void setId(char c);
	char getId();

	bool clicked(sf::Window& window);

private:
	char m_id;
	sf::Vector2f m_location;
	sf::Sprite* m_Image;
	sf::Sprite* m_Action;

};