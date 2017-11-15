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
        std::string name;
        std::string description;
};

#endif // GAMEOBJECT_H
