#include <string>
#include <algorithm>
#include <numeric>
#include "d5.h"
#include "days.h"

void addLineToGrid(
    line &l,
    std::vector<std::vector<int>> &grid) {
  std::pair<int, int> draw = l.start;
  if(draw.first != l.end.first && draw.second != l.end.second) return;
  grid[l.end.first][l.end.second]++;
  while(draw.first != l.end.first) {
    grid[draw.first][draw.second]++;
    if(draw.first < l.end.first) draw.first++;
    else draw.first--;
  }
  while(draw.second != l.end.second) {
    grid[draw.first][draw.second]++;
    if(draw.second < l.end.second) draw.second++;
    else draw.second--;
  }
}

void addLinesToGrid(
    std::vector<line> &lines,
    std::vector<std::vector<int>> &grid) {
  for(line l : lines) {
    addLineToGrid(l, grid);
  }
}

int d5p1(std::ifstream &ifile) {
  std::vector<line> lines = getLines(ifile);
  std::pair<int, int> max = getMaxDimensions(lines);
  std::vector<std::vector<int>> grid(
      max.first, std::vector<int>(max.second, 0));

  addLinesToGrid(lines, grid);
  return countIntersections(grid);
}
