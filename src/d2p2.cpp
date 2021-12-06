#include <fstream>
#include <string>

int d2p2(std::ifstream &ifile) {
  int depth = 0;
  int position = 0;
  int aim = 0;

  while (!ifile.eof()) {
    std::string command;
    int x;

    ifile >> command;
    ifile >> x;

    if (command == "forward") {
      position += x;
      depth += aim * x;
    }
    if (command == "up") {
      aim -= x;
    }
    if (command == "down") {
      aim += x;
    }
  }

  return depth * position;
}
