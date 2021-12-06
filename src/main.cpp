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

  }
}
