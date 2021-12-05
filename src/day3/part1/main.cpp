#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int count = 0;
  std::string input;
  std::vector<int> totals{};

  while (std::cin >> input) {
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

  std::cout << "count: " << count << std::endl;
  ;
  std::cout << "result: ";
  for (int i = 0; i < totals.size(); i++) {
    std::cout << totals[i] << " ";
  }
  std::cout << std::endl;

  int gamma = 0;
  int mask = 0;
  for (int i = 0; i < totals.size(); i++) {
    gamma *= 2;
    gamma += totals[i] > count / 2;
    mask *= 2;
    mask += 1;
  }

  std::cout << gamma << std::endl;
  std::cout << gamma * (gamma ^ mask) << std::endl;
}
