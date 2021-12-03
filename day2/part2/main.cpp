#include <iostream>
#include <string>

int main() {
  int depth = 0;
  int position = 0;
  int aim = 0;

  while(!std::cin.eof()) {
    std::string command;
    int x;

    std::cin >> command;
    std::cin >> x;

    if(command == "forward") {
      position += x;
      depth += aim*x;
    }
    if(command == "up") {
      aim -= x;
    }
    if(command == "down") {
      aim += x;
    }
  }

  std::cout << depth*position << std::endl;
}
