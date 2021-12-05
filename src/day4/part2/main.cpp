#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

void printVector(const std::vector<int>& v, std::string label);
void print2dVector(const std::vector<std::vector<int>>& v2, std::string label);
void printBanner(std::string message);

/// Take string delimited string and converts to vector
std::vector<int> createDrawList(std::string draw) {
  std::stringstream ss(draw);
  std::vector<int> drawList;

  for (int num; ss >> num;) {
    drawList.push_back(num);
    if (ss.peek() == ',') {
      ss.ignore();
    }
  }

  return drawList;
}

/// Gets a 5x5 board from stdin
std::vector<std::vector<int>> getBoard() {
  std::vector<std::vector<int>> board;
  for (int i = 0; i < 5; i++) {
    std::vector<int> row;
    for (int i = 0; i < 5; i++) {
      int input;
      std::cin >> input;
      row.push_back(input);
    }
    board.push_back(row);
  }

  return board;
}

// removes value from board by changing to "-1"
void removeValueFromBoard(std::vector<std::vector<int>>& board, int value) {
  for (std::vector<int>& v : board) {
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == value) {
        v[i] = -1;
      }
    }
  }
}

// check if board has won
bool checkBoardWon(std::vector<std::vector<int>>& board) {
  // check rows
  if (std::any_of(board.begin(), board.end(), [](std::vector<int>& v) {
        return std::all_of(v.begin(), v.end(),
                           [](const int i) { return i == -1; });
      })) {
    return true;
  }

  // check columns
  for (unsigned int i = 0; i < board[0].size(); i++) {
    if (std::all_of(board.begin(), board.end(),
                    [i](const std::vector<int> v) { return v[i] == -1; })) {
      return true;
    }
  }

  return false;
}

/// caculates the sum of a board
int boardSum(std::vector<std::vector<int>>& board) {
  return std::accumulate(board.cbegin(), board.cend(), 0,
                         [](const int acc, const std::vector<int>& v) {
                           return acc + std::accumulate(
                                            v.cbegin(), v.cend(), 0,
                                            [](const int acc, const int i) {
                                              return acc + (i == -1 ? 0 : i);
                                            });
                         });
}

int main() {
  printBanner("Parsing Input");
  std::string draw;
  getline(std::cin, draw);

  std::vector<int> drawList = createDrawList(draw);
  std::vector<std::vector<std::vector<int>>> boards;
  std::string dumb;
  while (1) {
    std::vector<std::vector<int>> board = getBoard();
    if (std::cin.eof()) break;
    boards.push_back(board);
  }

  printVector(drawList, "Draw List");
  int count = 0;
  for (std::vector<std::vector<int>> board : boards) {
    print2dVector(board, std::to_string(count++));
  }

  printBanner("Processing Draw List");
  for (const int num : drawList) {
    for (auto it = boards.begin(); it != boards.end();) {
      removeValueFromBoard(*it, num);
      if (checkBoardWon(*it)) {
        if (boards.size() == 1) {
          print2dVector(*it, "Last Winning Board");
          std::cout << boardSum(*it) * num << std::endl;
        }
        boards.erase(it);
        continue;
      }
      it++;
    }
  }
  return 0;
}

void printBanner(std::string message) {
  int width = 50;
  char fill = '-';
  std::cout << std::setfill(fill) << std::setw(width) << " " << std::endl;
  std::cout << std::setfill(fill) << std::setw((width - message.size()) / 2)
            << " ";
  std::cout << message << ((message.size() % 2 == 1) ? " " : "");
  std::cout << std::setfill(fill) << std::setw((width - message.size()) / 2)
            << " ";
  std::cout << std::endl;
  std::cout << std::setfill(fill) << std::setw(width) << " " << std::endl;
}

void printVector(const std::vector<int>& v, std::string label) {
  std::cout << label << ": ";
  for (int num : v) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

void print2dVector(const std::vector<std::vector<int>>& v2, std::string label) {
  int count = 0;
  std::cout << label << ":" << std::endl;
  for (const std::vector<int> v : v2) {
    printVector(v, std::to_string(count++));
  }
  std::cout << std::endl;
}
