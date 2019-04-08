#include "pch.h"
#include "../try_linking/doubleNum.cpp"

TEST(DoubleNumTest, PositiveValues) 
{
	ASSERT_EQ(12, doubleNum(6));
	ASSERT_EQ(4, doubleNum(2));
	ASSERT_EQ(40, doubleNum(20));
}

TEST(DoubleNumTest, NegativeValues)
{
	ASSERT_EQ(-12, doubleNum(-6));
	ASSERT_EQ(-4, doubleNum(-2));
	ASSERT_EQ(-40, doubleNum(-20));
}

TEST(TestCaseName, TestName) 
{
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}