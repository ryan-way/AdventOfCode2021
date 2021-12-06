#include <fstream>

int d1p1(std::ifstream &ifile) {
  int increases = 0;
  int input;
  int previous;
  ifile >> input;
  previous = input;
  while (ifile >> input) {
    increases += input > previous;
    previous = input;
  }

  return increases;
}
