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
    this->name = name;
}

void GameObject::setDescription(std::string description)
{
    this->description = description;
}

std::string GameObject::getName()
{
    return this->name;
}

std::string GameObject::getDescription()
{
    return this->description;
}
