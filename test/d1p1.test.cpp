#include <gtest/gtest.h>
#include <fstream>
#include "days.h"

TEST(d1p1, test) {
  bool test = true;
  int day = 1;
  int part = 1;
  std::stringstream file;
  file << "data/" << (test? "test" : "solve") << "/"
    << "d" << std::to_string(day) << "p" << std::to_string(part) << ".txt";

  std::ifstream ifile;
  ifile.open(file.str());

  int result = d1p1(ifile);

  EXPECT_EQ(result, 7);
}
