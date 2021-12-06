#include <fstream>
#include <string>

int d2p1(std::ifstream &ifile) {
  int depth = 0;
  int position = 0;

  while (!ifile.eof()) {
    std::string command;
    int x;

    ifile >> command;
    ifile >> x;

    if (command == "forward") {
      position += x;
    }
    if (command == "up") {
      depth -= x;
    }
    if (command == "down") {
      depth += x;
    }
  }

  return depth * position;
}
