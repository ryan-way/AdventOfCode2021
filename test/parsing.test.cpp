#include <gtest/gtest.h>
#include "parsing.h"

struct testcase {
  int argc;
  const char* argv[];
};

struct testcase test {
  5,
  {"-p", "4", "-d", "3", "-t"}
};

struct testcase solve {
  0,
  {}
};

using namespace Parsing;
TEST(Parsing, getOptionIndexFound) {
  std::string option = "-d";

  int index = getOptionIndex(test.argc, test.argv, option);

  EXPECT_EQ(index, 2);
}

TEST(Parsing, getOptionIndexNotFound) {
  std::string option = "-t";

  int index = getOptionIndex(solve.argc, solve.argv, option);

  EXPECT_EQ(index, -1);
}

TEST(Parsing, getCommandLineOptionIntFound) {
  std::string option = "-d";
  int value = getCommandLineOption(test.argc, test.argv, option, 5);

  EXPECT_EQ(value, 3);
}

TEST(Parsing, getCommandLineOptionIntNotFound) {
  std::string option = "-d";
  int value = getCommandLineOption(test.argc, test.argv, option, 3);

  EXPECT_EQ(value, 3);
}

TEST(Parsing, getCommandLineOptionBoolFound) {
  std::string option = "-t";
  bool value = getCommandLineOption(test.argc, test.argv, option, false);

  EXPECT_TRUE(value);
}

TEST(Parsing, getCommandLineOptionBoolNotFound) {
  std::string option = "-t";
  bool value = getCommandLineOption(solve.argc, solve.argv, option, false);

  EXPECT_FALSE(value);
}
