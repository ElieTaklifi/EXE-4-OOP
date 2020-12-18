#include "Effect.h"

Effect::Effect()
{
}


Effect::~Effect()
{
}

void Effect::setId(char c)
{
    m_id = c;
}

char Effect::getId()
{
    return m_id;
}

void Effect::setObject(sf::Sprite* object)
{
    m_object = object;
}

sf::Sprite* Effect::getObject()
{
    return m_object;
}