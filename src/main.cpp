#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include "parsing.h"
#include "days.h"
#include "data.h"

using namespace Parsing;
int main(int argc, const char *argv[]) {
  int day  = getCommandLineOption(argc, argv, "-d", 1);
  int part = getCommandLineOption(argc, argv, "-p", 1);
  bool test = getCommandLineOption(argc, argv, "-t", false);

  std::string fileName = getDataFile(day, part, test);
  std::ifstream ifile(fileName);

  switch(day) {
    case 1:
      std::cout << (part == 1 ? d1p1(ifile) : d1p2(ifile)) << std::endl;
      break;
    case 2:
      std::cout << (part == 1 ? d2p1(ifile) : d2p2(ifile)) << std::endl;
      break;
    case 3:
      std::cout << (part == 1 ? d3p1(ifile) : d3p2(ifile)) << std::endl;
      break;
    case 4:
      std::cout << (part == 1 ? d4p1(ifile) : d4p2(ifile)) << std::endl;
      break;
    case 5:
      std::cout << (part == 1 ? d5p1(ifile) : d5p2(ifile)) << std::endl;
      break;

  }
}
