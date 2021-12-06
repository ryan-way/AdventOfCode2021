#include "d4.h"

int d4p2(std::ifstream &ifile) {
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
    for (auto it = boards.begin(); it != boards.end();) {
      removeValueFromBoard(*it, num);
      if (checkBoardWon(*it)) {
        if (boards.size() == 1) {
          return boardSum(*it) * num;
        }
        boards.erase(it);
        continue;
      }
      it++;
    }
  }
  return 0;
}
