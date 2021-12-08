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

void testRunnerSize_t(int day,
    int part,
    bool test,
    size_t (*run)(std::ifstream&),
    size_t exp) {
  std::string fileName = getDataFile(day, part, test);
  std::ifstream ifile(fileName);

  size_t result = run(ifile);
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

TEST(d2p1, test) {
  bool test = true;
  int day = 2;
  int part = 1;
  testRunner(day, part, test, d2p1, 150);
}

TEST(d2p1, solve) {
  bool test = false;
  int day = 2;
  int part = 1;
  testRunner(day, part, test, d2p1, 1868935);
}

TEST(d2p2, test) {
  bool test = true;
  int day = 2;
  int part = 2;
  testRunner(day, part, test, d2p2, 900);
}

TEST(d2p2, solve) {
  bool test = false;
  int day = 2;
  int part = 2;
  testRunner(day, part, test, d2p2, 1965970888);
}


TEST(d3p1, test) {
  bool test = true;
  int day = 3;
  int part = 1;
  testRunner(day, part, test, d3p1, 198);
}

TEST(d3p1, solve) {
  bool test = false;
  int day = 3;
  int part = 1;
  testRunner(day, part, test, d3p1, 3923414);
}

TEST(d3p2, test) {
  bool test = true;
  int day = 3;
  int part = 2;
  testRunner(day, part, test, d3p2, 230);
}

TEST(d3p2, solve) {
  bool test = false;
  int day = 3;
  int part = 2;
  testRunner(day, part, test, d3p2, 5852595);
}

TEST(d4p1, test) {
  bool test = true;
  int day = 4;
  int part = 1;
  testRunner(day, part, test, d4p1, 4512);
}

TEST(d4p1, solve) {
  bool test = false;
  int day = 4;
  int part = 1;
  testRunner(day, part, test, d4p1, 58412);
}

TEST(d4p2, test) {
  bool test = true;
  int day = 4;
  int part = 2;
  testRunner(day, part, test, d4p2, 1924);
}

TEST(d4p2, solve) {
  bool test = false;
  int day = 4;
  int part = 2;
  testRunner(day, part, test, d4p2, 10030);
}

TEST(d5p1, test) {
  bool test = true;
  int day = 5;
  int part = 1;
  testRunner(day, part, test, d5p1, 5);
}

TEST(d5p1, solve) {
  bool test = false;
  int day = 5;
  int part = 1;
  testRunner(day, part, test, d5p1, 6311);
}

TEST(d5p2, test) {
  bool test = true;
  int day = 5;
  int part = 2;
  testRunner(day, part, test, d5p2, 12);
}

TEST(d5p2, solve) {
  bool test = false;
  int day = 5;
  int part = 2;
  testRunner(day, part, test, d5p2, 19929);
}

TEST(d6p1, test) {
  bool test = true;
  int day = 6;
  int part = 1;
  testRunner(day, part, test, d6p1, 5934);
}

TEST(d6p1, solve) {
  bool test = false;
  int day = 6;
  int part = 1;
  testRunner(day, part, test, d6p1, 351092);
}

TEST(d6p2, test) {
  bool test = true;
  int day = 6;
  int part = 2;
  testRunnerSize_t(day, part, test, d6p2, 26984457539);
}

TEST(d6p2, solve) {
  bool test = false;
  int day = 6;
  int part = 2;
  testRunnerSize_t(day, part, test, d6p2, 1595330616005);
}

TEST(d7p1, test) {
  bool test = true;
  int day = 7;
  int part = 1;
  testRunner(day, part, test, d7p1, 37);
}

TEST(d7p1, solve) {
  bool test = false;
  int day = 7;
  int part = 1;
  testRunner(day, part, test, d7p1, 337488);
}

TEST(d7p2, test) {
  bool test = true;
  int day = 7;
  int part = 1;
  testRunner(day, part, test, d7p2, 168);
}

TEST(d7p2, solve) {
  bool test = false;
  int day = 7;
  int part = 1;
  testRunner(day, part, test, d7p2, 89647695);
}
