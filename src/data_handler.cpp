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

#define TOP_TEN 10

using std::string;
using std::vector;

DataHandler::DataHandler(){};
DataHandler::~DataHandler(){};

std::map<string, int> DataHandler::readGameHistoryMap()
{

  string line;
  string gamer_name;
  int gamer_score;
  std::map<string, int> gamers_map;
  std::map<string, int>::iterator iter;
  const std::string gameDataDirectory{"../data"};

  std::ifstream filestream(gameDataDirectory + "/" + "scoreboard.txt");

  if (filestream.is_open())
  {
    while (std::getline(filestream, line))
    {

      std::istringstream linestream(line);
      while (linestream >> gamer_name >> gamer_score)
      {
        gamers_map.insert(std::make_pair(gamer_name, gamer_score));
      }
    }
    filestream.close();
    std::cout << "Finished reading file ..." << std::endl;
    return gamers_map;
  }
  else
  {
    std::ofstream outfile("scoreboard.txt");
    std::cout << "Scoreboard file does not exist. Creating a new file." << std::endl;
  }
}

void DataHandler::writeGameHistoryMapSorted(std::map<string, int> aux_map)
{

  std::ofstream dataFile;

  dataFile.open("../data/scoreboard.txt", std::ios::in | std::ios::out | std::ios::app);
  if (!dataFile.is_open())
  {
    std::cout << " Cannot open file" << std::endl;
  }
  else
  {
    std::map<string, int> sorted_aux_map;

    typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;

    Comparator compFunctor =
        [](std::pair<std::string, int> elem1, std::pair<std::string, int> elem2) {
          return elem1.second > elem2.second;
        };

    // Declare a set to store name-score pairs using comparision logic above
    std::set<std::pair<std::string, int>, Comparator> sorted_map(
        aux_map.begin(), aux_map.end(), compFunctor);

    // Iterate over a set using a range base for loop to print the items in order of values
    int ii = 1;
    for (std::pair<std::string, int> element : sorted_map)
    {
      dataFile << ii << ". Name: " << element.first << ", Score: " << element.second << "\n";
      ii++;
    }

    dataFile.close();
  }
}

void DataHandler::writeGameHistoryMap(std::map<string, int> gamers_map)
{

  std::map<string, int>::iterator it;
  std::map<string, int>::iterator itr;

  std::ofstream dataFile;

  dataFile.open("../data/scoreboard.txt", std::ios::in | std::ios::out | std::ios::app);
  if (!dataFile.is_open())
  {
    std::cout << " Cannot open file" << std::endl;
  }
  else
  {
  //   for (auto itr = gamers_map.begin(); itr != gamers_map.end(); itr++)
  //   {
  //     if( itr == gamers_map.end())
  //     {
  //       std::cout << "[" << itr->first << "," << itr->second << "]\n";
  //     }
      
  //   }
    // for (std::pair<std::string, int> element : gamers_map)
    // {
    //   //Accessing key from element
    //   std::string name = element.first;
    //   //Accessing value from element
    //   int count = element.second;
    //   std::cout << name << " :: " << count << std::endl;
    // }
    // dataFile << "\n" << "***Game history from the current session***"<< "\n";

    for (it = gamers_map.begin(); it != gamers_map.end(); it++)
    {
      dataFile << (*it).first << " " << (*it).second << "\n";
    }
    
    dataFile.close();
  }
}

void DataHandler::displayScoreboard(std::map<string, int> aux_map)
{

  typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;

  Comparator compFunctor =
      [](std::pair<std::string, int> elem1, std::pair<std::string, int> elem2) {
        return elem1.second > elem2.second;
      };

  // Declare a set to store name-score pairs using comparision logic above
  std::set<std::pair<std::string, int>, Comparator> sorted_map(
      aux_map.begin(), aux_map.end(), compFunctor);

  // Iterate over a set using a range base for loop to print the items in order of values
  int i = 1;

  for (std::pair<std::string, int> element : sorted_map)
  {
    std::cout << i << ". Name: " << element.first << ", Score: " << element.second << std::endl;
    i++;
    if (i > TOP_TEN)
      break;
  }
}