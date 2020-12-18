#include "..\include\Graphics.h"

Graphics::Graphics()
{

	m_textures.resize(9);
	m_textures[0] = "";
	m_textures[1] = "";
	m_textures[2] = "";
	m_textures[3] = "";
	m_textures[4] = "";
	m_textures[5] = "";
	m_textures[6] = "";
	m_textures[7] = "";
	m_textures[8] = "";
}

Graphics::~Graphics()
{
}

sf::Sprite* Graphics::getSprite(int index)
{
	return &m_SpriteButton[index];
}

void Graphics::setTexture()
{
	m_SpriteButton.resize(9);
	m_TextureButton.resize(9);

	for (int i = 0; i < m_TextureButton.size(); i++){
		m_TextureButton[i].loadFromFile(m_textures[i]);
		m_SpriteButton[i].setTexture(m_TextureButton[i]);
	}
}