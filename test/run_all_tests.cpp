#include "gtest/gtest.h"

TEST(HelloTest, BasicAssertions)
{
  //EXPECT_STR_EQ("hello", "world");
  EXPECT_EQ(7 * 6, 42);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

