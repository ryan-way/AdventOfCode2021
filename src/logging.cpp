#include "logging.h"

void printBanner(std::string message) {
  int width = 50;
  char fill = '-';
  std::cout << std::setfill(fill) << std::setw(width) << " " << std::endl;
  std::cout << std::setfill(fill) << std::setw((width - message.size()) / 2)
            << " ";
  std::cout << message << ((message.size() % 2 == 1) ? " " : "");
  std::cout << std::setfill(fill) << std::setw((width - message.size()) / 2)
            << " ";
  std::cout << std::endl;
  std::cout << std::setfill(fill) << std::setw(width) << " " << std::endl;
}

void printVector(const std::vector<int>& v, std::string label) {
  std::cout << label << ": ";
  for (int num : v) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

void print2dVector(const std::vector<std::vector<int>>& v2, std::string label) {
  int count = 0;
  std::cout << label << ":" << std::endl;
  for (const std::vector<int> v : v2) {
    printVector(v, std::to_string(count++));
  }
  std::cout << std::endl;
}
