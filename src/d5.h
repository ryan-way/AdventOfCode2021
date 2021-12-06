#include <utility>
#include <vector>
#include <fstream>
#include <sstream>
#include <numeric>

struct line {
  std::pair<int, int> start;
  std::pair<int, int> end;
};

std::vector<line> getLines(std::ifstream &ifile);
std::pair<int, int> getMaxDimensions(std::vector<line> &lines);
int countIntersections(std::vector<std::vector<int>> &grid);
int getInputNumber(std::stringstream &ss);
