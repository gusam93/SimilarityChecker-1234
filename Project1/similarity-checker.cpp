#include <string>
#include <vector>
using std::string;
using std::vector;

class SimlilarityChecker {
public:
    int getResult(const string& string1, const string& string2) {
        if (string1 == string2) return 100;
        return 0;
    }
};