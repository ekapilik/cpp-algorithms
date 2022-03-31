/**
 * @file run_all_tests.cpp
 * @author Eric Kapilik (erickapilik@gmail.com)
 * @brief Automatically find all registed Google tests and run them.
 * @version 0.1
 * @date 2022-03-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "gtest/gtest.h"

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

