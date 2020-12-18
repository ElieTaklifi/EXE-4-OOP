#include "Button.h"

Button::Button()
{
	m_id = ' ';
	m_location = { 0, 0 };
	//m_image ?
	//m_action ?
}

Button::~Button()
{
}

void Button::setLocation(sf::Vector2f newLocation)
{
	m_location = newLocation;
	m_Image->setPosition(newLocation);
	// Pas besoin pour Action ?
}

void Button::setImage(sf::Sprite* image)
{
	this->m_Image = image;
	this->m_Image->setTextureRect({}); //4 integers *******Raison??****
}

sf::Sprite* Button::getImage()
{
	return m_Image; //Pas besoin d'un & ? yavais besoin pour tile obj
}

void Button::setAction(sf::Sprite* action)
{
	this->m_Action = action;
	this->m_Action->setTextureRect({}); //4 integers *******Raison??****

}

sf::Sprite* Button::getAction()
{
	return m_Action;
}

void Button::setId(char c)
{
	m_id = c;
}

char Button::getId()
{
	return m_id;
}

bool Button::clicked(sf::Window& window)
{
	return ;
}
