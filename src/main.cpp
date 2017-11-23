#include <iostream>
#include "Session.h"
#include "Logger.h"

int main()
{
    Logger::init();
    std::string playerName;

    std::cout << "--------------------" << std::endl;
    std::cout << "Herzlich willkommen!" << std::endl;
    std::cout << "--------------------" << std::endl;

    std::cout << "Spielername:";
    getline (std::cin, playerName);

    Session *m_session = new Session(playerName);

    while(1)
    {
        m_session->execute();
    }

    delete m_session;

    return 0;
}




