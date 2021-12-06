#include "data.h"

std::string getDataFile(int day, int part, bool test) {
  std::string file = "data/";
  file += (test? "test" : "solve");
  file += "/d" + std::to_string(day) + ".txt";
  return file;
}
