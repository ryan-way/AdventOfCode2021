#include "fstream"

int d1p2(std::ifstream &ifile) {
  int first = -1, second = -1, third = -1, fourth = -1;
  int count = 0;

  while (ifile >> first) {
    if (fourth != -1) {
      count += first > fourth;
    }

    fourth = third;
    third = second;
    second = first;
  }

  return count;
}
