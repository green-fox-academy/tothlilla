//
// Created by Lilla on 2019. 02. 07..
//
#include "gtest/gtest.h"
#include "apples.h"

TEST(apple_check, test_apple){
  EXPECT_EQ(getApple(), "lapple");
}

