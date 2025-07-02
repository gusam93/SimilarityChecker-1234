#include <string>
#include <vector>
#include <set>
using std::string;
using std::vector;
using std::set;

class SimlilarityChecker {
public:
    int getResult(const string& string1, const string& string2) {
        if (string1 == string2) return 100;
        double lengthScore = getLengthScore(string1.size(), string2.size());
        double sameCharScore = getSameCharScore(string1, string2);
        return lengthScore + sameCharScore;
    }

    double getLengthScore(int string1Length, int string2Length)
    {
        if (string1Length == string2Length) return 60;
        const double longLength = std::max(string1Length, string2Length);
        const double shortLength = std::min(string1Length, string2Length);

        if (shortLength * 2 <= longLength) return 0;
        return (1 - (longLength - shortLength) / shortLength) * 60;
    }
    double getSameCharScore(const string& string1, const string& string2)
    {
        // 1. 대문자 예외처리 필요
        std::set<char> totalAlapha;
        std::set<char> sameAlpha;

        for (auto ch : string1) {
            totalAlapha.insert(ch);
        }
        for (auto ch : string2) {
            totalAlapha.insert(ch);
        }
        for (auto c : string1) {
            if (string2.find(c) == string::npos) continue;
            sameAlpha.insert(c);
        }

        if (sameAlpha.size() == 0)return 0;

        return static_cast<double>(sameAlpha.size() / totalAlapha.size()) * 40;
    }
};