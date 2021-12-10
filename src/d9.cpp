#include "days.h"
#include <vector>
#include <sstream>
#include <utility>
#include <algorithm>
#include <iostream>

void getGridFromInput(std::vector<std::vector<int>> &grid, std::ifstream &ifile) {
  std::string row;
  while(std::getline(ifile, row)) {
    std::stringstream ss(row);
    std::vector<int> temp;
    while(!ss.eof()) {
      temp.push_back(ss.peek()-'0');
      ss.ignore();
    }
    grid.push_back(temp);
  }
}

std::vector<std::pair<int,int>> getNeighbors(
    std::vector<std::vector<int>> &grid,
    unsigned int i, unsigned int j) {
  std::vector<std::pair<int, int>> neighbors;
  if(i > 0) {
    neighbors.push_back(std::pair<int, int>(i-1, j));
  }
  if(j > 0) {
    neighbors.push_back(std::pair<int, int>(i, j-1));
  }
  if(i < grid.size() - 1) {
    neighbors.push_back(std::pair<int, int>(i+1, j));
  }
  if(j < grid[i].size() - 1) {
    neighbors.push_back(std::pair<int, int>(i, j+1));
  }

  return neighbors;
}

std::vector<std::pair<int, int>> getLowPoints(
    std::vector<std::vector<int>> &grid) {
  std::vector<std::pair<int, int>> lowPoints;
  for(unsigned int i = 0; i < grid.size(); i++) {
    for(unsigned int j = 0; j < grid[i].size(); j++) {
      std::vector<std::pair<int, int>> neighbors = getNeighbors(grid, i, j);
      if(std::all_of(neighbors.begin(), neighbors.end(), 
          [i, j, &grid](std::pair<int, int> neighbor) {
            return grid[i][j] < grid[neighbor.first][neighbor.second]; })) {
        lowPoints.push_back(std::pair<int, int>(i, j));
      }
    }
  }
  
  return lowPoints;
}

int d9p1(std::ifstream &ifile) {
  std::vector<std::vector<int>> grid;
  getGridFromInput(grid, ifile);
  std::vector<std::pair<int, int>> lowPoints = getLowPoints(grid);
  int risk = 0;
  for(std::pair<int ,int> lowPoint : lowPoints) {
    std::cout << lowPoint.first << "," << lowPoint.second << std::endl;
    risk += grid[lowPoint.first][lowPoint.second] + 1;
  }
  return risk;
}

int d9p2(std::ifstream &ifile) {
  return 0;
}
