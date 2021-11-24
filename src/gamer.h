#include <iostream>
#include <string>
#include <vector>

#include "snake.h"

class Gamer
{
    public:
        Gamer() { std::cout << "New Gamer" << std::endl; }
        Gamer(std::string gamer_name, int gamer_score, std::string game_time);
        ~Gamer(){};
        Snake newsnake();

        //Getters and Setters
        std::string getGamerID();
        int getGamerScore();
        std::string getGameTime();

        void setGamerID();
        void setGamerScore();
        void setGameTime();

    private:
        std::string _gamer_name;
        int _gamer_score;
        std::string _game_time;
        double _snake_head_distance;
};