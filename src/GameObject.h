#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <map>
#include <vector>


class GameObject
{
    public:
        GameObject();
        virtual ~GameObject();

        void setName(std::string name);
        void setDescription(std::string description);
        void setId(std::string id);
        void addDetail(std::string name, std::string description);

        std::string getName();
        std::string getDescription();
        std::string getId();        
        std::string getDetail(std::string name);

    private:
        std::string m_name;
        std::string m_description;
        std::string m_id;

        std::map<std::string,std::string> m_detailMap;

};

#endif // GAMEOBJECT_H
