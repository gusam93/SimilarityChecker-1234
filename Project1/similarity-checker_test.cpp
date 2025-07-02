#include "gmock/gmock.h"
#include "similarity-checker.cpp"


TEST(SimilarityCheckerTest, SameWord)
{
    SimlilarityChecker checker;
    EXPECT_EQ(100, checker.getResult("ABC", "ABC"));
}
TEST(SimilarityCheckerTest, SameLengthWithDifferentWords)
{
    SimlilarityChecker checker;
    EXPECT_EQ(60, checker.getResult("ABC", "DEF"));
}
TEST(SimilarityCheckerTest, LengthIsLessEqualWTwice)
{
    SimlilarityChecker checker;
    EXPECT_EQ(20, checker.getResult("ABC", "DEFGE"));
}

TEST(SimilarityCheckerTest, LengthIsGreaterThanTwice)
{
    SimlilarityChecker checker;
    EXPECT_EQ(0, checker.getResult("ABC", "DDDXFFFF"));
}

TEST(SimilarityCheckerTest, SameCharUsed)
{
    SimlilarityChecker checker;
    EXPECT_EQ(100, checker.getResult("ASD", "DSA"));
    EXPECT_EQ(0, checker.getResult("A", "BB"));
    EXPECT_EQ(40, checker.getResult("AAABB", "BA"));
    EXPECT_EQ(30, checker.getResult("AA", "AAE"));
}


int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}