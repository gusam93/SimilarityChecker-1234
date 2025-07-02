#include <string>
#include <vector>
using std::string;
using std::vector;

class SimlilarityChecker {
public:
    int getResult(const string& string1, const string& string2) {
        if (string1 == string2) return 100;
        int lengthScore = getLengthScore(string1.size(), string2.size());
    }

    int getLengthScore(int string1Length, int string2Length)
    {
        if (string1Length == string2Length) return 60;
        const double longLength = std::max(string1Length, string2Length);
        const double shortLength = std::min(string1Length, string2Length);

        if ((longLength / shortLength) >= 2) return 0;
        return (1 - ((longLength - shortLength) / shortLength)) * 60;
    }
};