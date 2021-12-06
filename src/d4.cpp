#include "d4.h"

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
std::vector<std::vector<int>> getBoard(std::ifstream &ifile) {
  std::vector<std::vector<int>> board;
  for (int i = 0; i < 5; i++) {
    std::vector<int> row;
    for (int i = 0; i < 5; i++) {
      int input;
      ifile >> input;
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
