#include <gtest/gtest.h>
#include "d5.h"

TEST(getInputNumber, smallNumbers) {
  std::string str = "0,9 -> 5,9";
  std::stringstream ss(str);

  ASSERT_EQ(getInputNumber(ss), 0);
  EXPECT_EQ(getInputNumber(ss), 9);
  EXPECT_EQ(getInputNumber(ss), 5);
  EXPECT_EQ(getInputNumber(ss), 9);
}

TEST(getInputNumber, bigNumbers) {
  std::string str = "957,596 -> 957,182";
  std::stringstream ss(str);

  EXPECT_EQ(getInputNumber(ss), 957);
  EXPECT_EQ(getInputNumber(ss), 596);
  EXPECT_EQ(getInputNumber(ss), 957);
  EXPECT_EQ(getInputNumber(ss), 182);
}
