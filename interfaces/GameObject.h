#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

class GameObject
{
    public:
        GameObject();
        virtual ~GameObject();

        void setName(std::string name);
        void setDescription(std::string description);
        std::string getName();
        std::string getDescription();

    protected:
        std::string m_name;
        std::string m_description;
};

#endif // GAMEOBJECT_H
