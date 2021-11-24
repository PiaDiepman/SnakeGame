#include <iostream>
#include "gamer.h"
#include <vector>

using std::vector;

class GameManager
{

public:
    GameManager()
    {

        std::cout << " " << std::endl;
    };

    void manageNewGamer(Gamer *gamer);
    bool initManager();
    void dumpDataToFile(Gamer *gamer);
    void retriveDataFromFile();

    static bool quit_game;

private:
    Gamer *gamer;
    vector<Gamer *> v_gamer;
};