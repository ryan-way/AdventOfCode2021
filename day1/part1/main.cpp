#include <iostream>

int main() {

  int increases = 0;
  int input;
  int previous;
  std::cin >> input;

  previous = input;
  while(std::cin >> input) {
    increases += input > previous;
    previous = input;
  }

  std::cout << increases << std::endl;
  return 0;
}
