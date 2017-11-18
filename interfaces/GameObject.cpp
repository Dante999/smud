#include "GameObject.h"

GameObject::GameObject()
{
    //ctor
}

GameObject::~GameObject()
{
    //dtor
}

void GameObject::setName(std::string name)
{
    m_name = name;
}

void GameObject::setDescription(std::string description)
{
    m_description = description;
}

std::string GameObject::getName()
{
    return m_name;
}

std::string GameObject::getDescription()
{
    return m_description;
}
