#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include "parsing.h"
#include "days.h"

using namespace Parsing;
int main(int argc, const char *argv[]) {
  int day  = getCommandLineOption(argc, argv, "-d", 1);
  int part = getCommandLineOption(argc, argv, "-p", 1);
  bool test = getCommandLineOption(argc, argv, "-t", true);

  std::stringstream file;
  file << "/data/" << (test? "test" : "solve") << "/"
    << "d" << std::to_string(day) << "p" << std::to_string(part) << ".txt";

  std::ifstream ifile(file.str());

  switch(day) {
    case 1:
      std::cout << d1p1(ifile) << std::endl;
      break;
  }
}
