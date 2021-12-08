#include "days.h"
#include "parsing.h"
#include <climits>
#include <algorithm>
#include <numeric>

using namespace Parsing;
int d7(std::ifstream &ifile, int (*fun)(int i, int j)) {
  std::string input;
  std::getline(ifile, input);
  std::vector<int> crabs = csvLineToVector(input);

  int best = INT_MAX;
  int small = std::accumulate(crabs.begin(), crabs.end(), 0,
      [] (int i, int j) { return std::min(i, j);});
  int big = std::accumulate(crabs.begin(), crabs.end(), 0,
      [] (int i, int j) { return std::max(i, j);});

  int current = small;

  while(current < big) {
    int next = 0;
    for(int crab : crabs) {
      next += fun(crab, current);
    }
    best = std::min(best, next);
    current++;
  }
  return best;
}

int d7p1(std::ifstream &ifile) {
  return d7(ifile, [](int i, int j) { return std::abs(i-j); });
}

int d7p2(std::ifstream &ifile) {
  return d7(ifile, [] (int i, int j) { 
      return (std::abs(i-j)+1)*std::abs(i-j)/2;
    });
}
