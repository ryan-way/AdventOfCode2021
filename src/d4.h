#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include "parsing.h"

std::vector<int> createDrawList(std::string draw); 
std::vector<std::vector<int>> getBoard(std::ifstream &ifile);
void removeValueFromBoard(std::vector<std::vector<int>>& board, int value);
bool checkBoardWon(std::vector<std::vector<int>>& board);
int boardSum(std::vector<std::vector<int>>& board);
