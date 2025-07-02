#include "gmock/gmock.h"
#include "similarity-checker.cpp"

class SimilarityCheckerFixture : public testing::Test {
public:
    void CheckScore(double expected, const string& input1, const string& input2) {
        EXPECT_EQ(expected, checker.getResult(input1, input2));
    }
    SimlilarityChecker checker;
};

TEST_F(SimilarityCheckerFixture, SameWord)
{
    CheckScore(100, "ABC", "ABC");
}
TEST_F(SimilarityCheckerFixture, SameLengthWithDifferentWords)
{
    CheckScore(60, "ABC", "DEF");
    EXPECT_EQ(60, checker.getResult("ABC", "DEF"));
}
TEST_F(SimilarityCheckerFixture, LengthIsLessEqualWTwice)
{
    CheckScore(20, "ABC", "DEFGE");
    EXPECT_EQ(20, checker.getResult("ABC", "DEFGE"));
}

TEST_F(SimilarityCheckerFixture, LengthIsGreaterThanTwice)
{
    CheckScore(0, "ABC", "DDDXFFFF");
    EXPECT_EQ(0, checker.getResult("ABC", "DDDXFFFF"));
}

TEST_F(SimilarityCheckerFixture, SameCharUsed)
{
    CheckScore(100, "ASD", "DSA");
    CheckScore(0, "A", "BB");
    CheckScore(40, "AAABB", "BA");
    CheckScore(30, "AA", "AAE");
}

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}