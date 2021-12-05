#include <iostream>
#include <string>

int main() {
  int depth = 0;
  int position = 0;

  while (!std::cin.eof()) {
    std::string command;
    int x;

    std::cin >> command;
    std::cin >> x;

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

  std::cout << depth * position << std::endl;
}
