#include "gmock/gmock.h"
#include "similarity-checker.cpp"


TEST(SimilarityCheckerTest, TC1)
{
    SimlilarityChecker checker;
    EXPECT_EQ(1, 1);
}
int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}