#include "itemstorage.h"

ItemStorage::ItemStorage()
{

}


/*******************************************************************************
 *
 *
 ******************************************************************************/
void ItemStorage::addItem(Item *item)
{
    std::string identifier = item->getName();

    m_itemMap[identifier] = item;
}


/*******************************************************************************
 *
 *
 ******************************************************************************/
void ItemStorage::removeItem(Item *item)
{
    std::string identifier = item->getName();

    if(m_itemMap.find(identifier) != m_itemMap.end())
    {
        m_itemMap.erase(identifier);
    }
}


/*******************************************************************************
 *
 *
 ******************************************************************************/
Item *ItemStorage::getItem(std::string id)
{
    if(m_itemMap.find(id) != m_itemMap.end())
    {
        return m_itemMap.find(id)->second;
    }
    else
    {
        return NULL;
    }
}


/*******************************************************************************
 *
 *
 ******************************************************************************/
std::vector<std::string> ItemStorage::toStringList()
{
    std::vector<std::string> list;

    std::map<std::string,Item*>::iterator it;

    for(it=m_itemMap.begin(); it!=m_itemMap.end(); ++it);
    {
        list.push_back("test-eintrag");
        list.push_back(it->first);
    }

    return list;
}

