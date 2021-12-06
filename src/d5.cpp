#include "d5.h"
#include <iostream>

int getInputNumber(std::stringstream &ss) {
  int num = 0;
  while(ss.peek() < '0' || ss.peek() > '9') ss.ignore();
  while(ss.peek() >= '0' && ss.peek() <= '9') {
    num *= 10;
    num += ss.peek() - '0';
    ss.ignore();
  }
  return num;
}

std::vector<line> getLines(std::ifstream &ifile) {
  std::vector<line> lines;
  std::string inputLine;
  while(std::getline(ifile, inputLine)) {
    std::stringstream ss(inputLine);
    struct line mLine;
    std::string arrow;

    mLine.start.first = getInputNumber(ss);
    mLine.start.second = getInputNumber(ss);
    mLine.end.first = getInputNumber(ss);
    mLine.end.second = getInputNumber(ss);

    lines.push_back(mLine);
  }

  return lines;
}

std::pair<int, int> getMaxDimensions(std::vector<line> &lines) {
  std::pair<int, int> max{0, 0};
  for(line l : lines) {
    max.first = std::max(max.first, l.start.first);
    max.second = std::max(max.second, l.start.second);

    max.first = std::max(max.first, l.end.first);
    max.second = std::max(max.second, l.end.second);
  }
  max.first++;
  max.second++;

  return max;
}

int countIntersections(std::vector<std::vector<int>> &grid) {
  return std::accumulate(grid.begin(), grid.end(), 0, 
      [](int count, std::vector<int> &v) { 
        return count + std::accumulate(v.begin(), v.end(), 0, 
              [](int count, int value) { return count + (value > 1);});
        });
}
