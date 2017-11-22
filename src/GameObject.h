#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <map>


class GameObject
{
    public:
        GameObject();
        virtual ~GameObject();

        void setName(std::string name);
        void setDescription(std::string description);
        void addDetail(std::string name, std::string description);

        std::string getDetail(std::string name);
        std::string getName();
        std::string getDescription();

    protected:


    private:
        std::string m_name;
        std::string m_description;
        std::map<std::string,std::string> m_details;

};

#endif // GAMEOBJECT_H
