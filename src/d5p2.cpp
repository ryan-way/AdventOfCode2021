#include <string>
#include <algorithm>
#include <numeric>
#include "d5.h"
#include "days.h"
#include <iostream>
#include "logging.h"

void addAllLineToGrid(
    line &l,
    std::vector<std::vector<int>> &grid) {
  std::pair<int, int> draw = l.start;
  grid[l.end.first][l.end.second]++;
  while(draw.first != l.end.first
      || draw.second != l.end.second) {
    grid[draw.first][draw.second]++;
    if(draw.first < l.end.first) draw.first++;
    if(draw.first > l.end.first) draw.first--;
    if(draw.second < l.end.second) draw.second++;
    if(draw.second > l.end.second) draw.second--;
  }
}
void addAllLinesToGrid(
    std::vector<line> &lines,
    std::vector<std::vector<int>> &grid) {
  for(line l : lines) {
    addAllLineToGrid(l, grid);
  }
}

int d5p2(std::ifstream &ifile) {
  std::vector<line> lines = getLines(ifile);
  std::pair<int, int> max = getMaxDimensions(lines);
  std::vector<std::vector<int>> grid(
      max.first, std::vector<int>(max.second, 0));

  addAllLinesToGrid(lines, grid);
  return countIntersections(grid);
}
