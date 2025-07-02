#include <string>
#include <vector>
#include <set>
using std::string;
using std::vector;
using std::set;

class SimlilarityChecker {
public:
    int getResult(const string& string1, const string& string2) {
        if (isSameText(string1, string2)) return PERFECT_SCORE;
        return getLengthScore(string1, string2) + getSameCharScore(string1, string2);
    }

    bool isSameText(const std::string& string1, const std::string& string2)
    {
        return string1 == string2;
    }

    double getLengthScore(const string& string1, const string& string2)
    {
        if (isSameLength(string1, string2)) return MAX_SAME_LENGTH_SCORE;
        const double longLength = std::max(string1.length(), string2.length());
        const double shortLength = std::min(string1.length(), string2.length());

        if (shortLength * 2 <= longLength) return 0;
        double rate = 1 - (longLength - shortLength) / shortLength;
        return rate * MAX_SAME_LENGTH_SCORE;
    }
    bool isSameLength(const std::string& string1, const std::string& string2)
    {
        return string1.length() == string2.length();
    }
    double getSameCharScore(const string& string1, const string& string2)
    {
        // 1. 대문자 예외처리 필요
        int totalCnt = getTotalAlphaCnt(string1, string2);
        int sameCnt = getSameAlphaCnt(string1, string2);
        auto rate = static_cast<double>(sameCnt / totalCnt);
        return rate * MAX_SAME_CHAR_SCORE;
    }

    int getSameAlphaCnt(const std::string& string1,  const std::string& string2)
    {
        std::set<char> sameAlpha;
        for (auto c : string1) {
            if (string2.find(c) == string::npos) continue;
            sameAlpha.insert(c);
        }
        return sameAlpha.size();
    }
    int getTotalAlphaCnt(const std::string& string1, const std::string& string2 )
    {
        std::set<char> totalAlapha;
        for (auto ch : string1) {
            totalAlapha.insert(ch);
        }
        for (auto ch : string2) {
            totalAlapha.insert(ch);
        }
        return totalAlapha.size();
    }
  
    static constexpr int MAX_SAME_LENGTH_SCORE = 60;
    static constexpr int MAX_SAME_CHAR_SCORE = 40;
    static constexpr int PERFECT_SCORE = MAX_SAME_CHAR_SCORE + MAX_SAME_LENGTH_SCORE;
};