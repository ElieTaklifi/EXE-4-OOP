#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Graphics
{
public:
	Graphics(); //this function cunstructs the object.
	~Graphics();
	sf::Sprite* getSprite(int index); //this function returns the objects sprite.

private:
	std::vector<std::string> m_textures; //Holds the file names.
	std::vector<sf::Sprite> m_SpriteButton; //Holds the buttons sprites.
	std::vector<sf::Texture> m_TextureButton; //Holds the buttons textures
	sf::Texture m_backgroundTexture; //Holds the background texture (floor).

	//private functions of the class.
	void setTexture(); //sets the textures to the buttons.
};