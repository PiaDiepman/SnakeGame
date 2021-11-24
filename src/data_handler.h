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

using std::string;
using std::vector;

class DataHandler
{

public:
    DataHandler();
    ~DataHandler();
    std::map<string, int> readGameHistoryMap();
    void writeGameHistoryMapSorted(std::map<string, int> aux_map);
    void writeGameHistoryMap(std::map<string, int> gamers_map);
    void displayScoreboard(std::map<string, int> aux_map);
};