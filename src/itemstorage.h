#ifndef ITEMSTORAGE_H
#define ITEMSTORAGE_H

#include "item.h"
#include "map"
#include "string"


class ItemStorage
{
public:
    ItemStorage();

    void addItem(Item *item);
    void removeItem(Item *item);
    Item *getItem(std::string id);

    std::vector<std::string> toStringList();

protected:
    std::map<std::string,Item*> m_itemMap;

};

#endif // ITEMSTORAGE_H
