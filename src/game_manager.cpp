#include "game_manager.h"
#include "data_handler.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <dirent.h>
#include <unistd.h>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <set>

bool GameManager::quit_game = false;

bool GameManager::initManager()
{

    std::cout << " ----- WELCOME TO SNAKE -----" << std::endl;
    std::cout << "   " << std::endl;
    std::cout << " 1 - New Game" << std::endl;
    std::cout << " 2 - Score Board" << std::endl;
    std::cout << " 3 - Quit" << std::endl;
    std::cout << "User choice --> ";

    int key_pressed;

    while (!(std::cin >> key_pressed))
    {

        std::cin.clear();

        while (std::cin.get() != '\n')
            continue;

        // Ask the user to try again with a valid number
        std::cout << "Error. Only a single number is allowed. Please enter a number from the list above -->  ";
    }
    if ((key_pressed < 1) || (key_pressed > 3))
    {
        std::cout << "Key pressed : " << key_pressed << std::endl;
        std::cout << "Error. Please enter a valid number!"
                  << "\n\n";
        return false;
    }

    switch (key_pressed)
    {

    case 1:
    {
        return true;
    };
    break;

    case 2:
    {
        DataHandler dm;
        std::map<string, int> recorded_gamers;
        recorded_gamers = dm.readGameHistoryMap();
        if (recorded_gamers.size() > 0)
        {
            std::cout << "*** Top 10 Scores ***" << std::endl;
            dm.displayScoreboard(recorded_gamers);
        }
        else
        {
            std::cout << "No game history exists!" << std::endl;
        }
        return false;
    };
    break;
    case 3:
    {
        std::cout << "\nThanks for playing snake, comeback soon! Game quitting." << std::endl;
        quit_game = true;
    };

        return false;
    }
}

void GameManager::manageNewGamer(Gamer *g)
{

    g->setGamerID();
}

void GameManager::dumpDataToFile(Gamer *g)
{

    std::cout << "Gamer:  " << g->getGamerID() << " :: " << g->getGamerScore() << " :: " << g->getGameTime() << std::endl;
}