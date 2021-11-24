#include <iostream>
#include <string>
#include <ctime>
#include <vector>

#include "gamer.h"

using std::string;
using std::vector;


Gamer::Gamer(string gamer_name, int gamer_score, string game_time){

    std::cout<<"----- New Gamer ----- "<< std::endl;

    this->_gamer_name = gamer_name;
    this->_gamer_score = gamer_score;
    this->_game_time = game_time;
}

string Gamer::getGamerID(){

    return _gamer_name;
}

int Gamer::getGamerScore(){

    
    return _gamer_score;
}

string Gamer::getGameTime(){
    return _game_time;
}

void Gamer::setGameTime(){
    //local machine date/time
    time_t now = time(0);
    char* dt = ctime(&now);
    _game_time = dt;
    std::cout << "Game Time: "<< _game_time;
    
}    

void Gamer::setGamerID(){
    // Get input from user for gamer name
    string gamer_ID;
    std::cout<<"Gamer Name:  ";
    std::cin >> gamer_ID;
    this->_gamer_name = gamer_ID;
}

void Gamer::setGamerScore(){
    //Print gamer's score
    int gamer_score;
    std::cout<< "Gamer score:  ";
    std::cin >> gamer_score;
    this->_gamer_score = gamer_score;

}
