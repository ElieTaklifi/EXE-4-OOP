#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>


class Effect{

public:

	Effect();//Builds the object.
	~Effect();

	void setId(char c);//sets the id of the object.
	char getId();//returns the id of the object.

	void setObject(sf::Sprite* object);//sets the sprite of the object.
	sf::Sprite* getObject();//returns a pointer to the sprite of the object.

private:

	sf::Sprite* m_object;//holds a pointer to the sprite.
	char m_id;//holds objects character id.
};

