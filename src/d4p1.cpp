#include "d4.h"

int d4p1(std::ifstream &ifile) {
  std::string draw;
  getline(ifile, draw);

  std::vector<int> drawList = Parsing::csvLineToVector(draw);
  std::vector<std::vector<std::vector<int>>> boards;
  std::string dumb;
  while (1) {
    std::vector<std::vector<int>> board = getBoard(ifile);
    if (ifile.eof()) break;
    boards.push_back(board);
  }

  for (const int num : drawList) {
    for (std::vector<std::vector<int>>& board : boards) {
      removeValueFromBoard(board, num);
      if (checkBoardWon(board)) {
        return boardSum(board) * num;
      }
    }
  }
  return -1;
}

