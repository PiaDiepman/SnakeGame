#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <dirent.h>
#include <unistd.h>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <set>

#include "data_handler.h"
#include "game_manager.h"
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "snake.h"

int main()
{
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  bool start_game;
  int gamer_score;
  start_game = false;
  bool quit_game_flag = false;

  std::map<string, int> actual_gamer_map;
  std::string gamer_ID;
  Snake tempSnake;

  while (true)
  {

    while (start_game == false)
    {
      GameManager gm;

      if (gm.quit_game == true)
      {
        return 0;
      }

      start_game = gm.initManager();
    }
    start_game = false;
    Gamer *newgamer = new Gamer();
    DataHandler *new_datahandler = new DataHandler();
    Snake newsnake;
    newgamer->setGamerID();
    tempSnake.total_head_distance_travelled = 0;

    std::cout << "Begin!" << std::endl;

    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight);
    game.Run(controller, renderer, kMsPerFrame);

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "              GAME OVER!\n";
    std::cout << "----------------------------------------" << std::endl;
    gamer_ID = newgamer->getGamerID();
    std::cout << "Gamer Name:  " << gamer_ID << std::endl;
    std::cout << "Score: " << game.GetScore() << "\n";
    std::cout << "Size: " << game.GetSize() << "\n";
    gamer_score = game.GetScore();

    actual_gamer_map.insert(std::make_pair(gamer_ID, gamer_score));
    new_datahandler->writeGameHistoryMap(actual_gamer_map);
  }
  return 0;
}