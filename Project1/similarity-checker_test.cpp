#include "gmock/gmock.h"
#include "similarity-checker.cpp"


TEST(SimilarityCheckerTest, SameWord)
{
    SimlilarityChecker checker;
    EXPECT_EQ(100, checker.getResult("ABC", "ABC"));
}

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}