#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

int d3p1(std::ifstream &ifile) {
  int count = 0;
  std::string input;
  std::vector<int> totals{};

  while (ifile >> input) {
    count += 1;
    int value = std::stoi(input, 0, 2);

    int i = 0;
    while (value) {
      if (totals.size() == i) totals.push_back(0);
      totals[i++] += value & 1;
      value >>= 1;
    }
  }

  std::reverse(totals.begin(), totals.end());

  int gamma = 0;
  int mask = 0;
  for (int i = 0; i < totals.size(); i++) {
    gamma *= 2;
    gamma += totals[i] > count / 2;
    mask *= 2;
    mask += 1;
  }

  return gamma * (gamma ^ mask);
}
