#include <vector>
#include <iostream>
#include <string>
#include <exception>
#include "parsing.h"

using namespace Parsing;
int main(int argc, const char *argv[]) {
  int day  = getCommandLineOption(argc, argv, "-d", 1);
  int part = getCommandLineOption(argc, argv, "-p", 1);
  bool test = getCommandLineOption(argc, argv, "-t", true);

  std::cout << "Day: " << day << ", ";
  std::cout << "Part: " << part << ", ";
  std::cout << "Test: " << test << std::endl;
}
