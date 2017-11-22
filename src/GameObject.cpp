#include "GameObject.h"


/*******************************************************************************
 * constructor
 *
 * @param   none
 *
 * @return  none
 *
 ******************************************************************************/
GameObject::GameObject()
{
    m_name = "not set";
    m_description = "not set";
}


/*******************************************************************************
 * destructor
 *
 * @param   none
 *
 * @return  none
 *
 ******************************************************************************/
GameObject::~GameObject()
{
    //dtor
}


/*******************************************************************************
 * sets the name of the gameObject
 *
 * @param   name    the name to set
 *
 * @return  none
 *
 ******************************************************************************/
void GameObject::setName(std::string name)
{
    m_name = name;
}


/*******************************************************************************
 * sets the description of the gameObject
 *
 * @param   description     the description of the object
 *
 * @return  none
 *
 ******************************************************************************/
void GameObject::setDescription(std::string description)
{
    m_description = description;
}


/*******************************************************************************
 * returns the name of the gameObject
 *
 * @param   none
 *
 * @return  the name of the gameObject
 *
 ******************************************************************************/
std::string GameObject::getName()
{
    return m_name;
}


/*******************************************************************************
 * returns the description of the gameObject
 *
 * @param   none
 *
 * @return  the description of the gameObject
 *
 ******************************************************************************/
std::string GameObject::getDescription()
{
    return m_description;
}


/*******************************************************************************
 * adds a detail to the object
 *
 * @param   name            name of the detail
 *
 * @param   description     description of the detail
 *
 * @return  none
 *
 ******************************************************************************/
void GameObject::addDetail(std::string name, std::string description)
{
    m_details[name] = description;
}


/*******************************************************************************
 * returns a object detail
 *
 * @param   name    name of the detail
 *
 * @return  the description of the detail, empty if there is no detail
 *
 ******************************************************************************/
std::string GameObject::getDetail(std::string name)
{
    if(m_details.find(name) != m_details.end())
    {
        return m_details.find(name)->second;
    }
    else
    {
        return "";
    }
}
