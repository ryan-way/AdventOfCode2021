#include <gtest/gtest.h>
#include <fstream>
#include "days.h"
#include "data.h"

void testRunner(int day, int part, bool test, int (*run)(std::ifstream&), int exp) {
  std::string fileName = getDataFile(day, part, test);
  std::ifstream ifile(fileName);

  int result = run(ifile);
  EXPECT_EQ(result, exp);
}

TEST(d1p1, test) {
  bool test = true;
  int day = 1;
  int part = 1;
  testRunner(day, part, test, d1p1, 7);
}

TEST(d1p1, solve) {
  bool test = false;
  int day = 1;
  int part = 1;
  testRunner(day, part, test, d1p1, 1390);
}

TEST(d1p2, test) {
  bool test = true;
  int day = 1;
  int part = 2;
  testRunner(day, part, test, d1p2, 5);
}

TEST(d1p2, solve) {
  bool test = false;
  int day = 1;
  int part = 2;
  testRunner(day, part, test, d1p2, 1457);
}
