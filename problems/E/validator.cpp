#include "testlib.h"
#include <set>
#include <cctype>

using namespace std;

const int max_testcases = 1'000'000;
int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int numtests = inf.readInt(1, max_testcases, "num-tests");
    inf.readEoln();

    for (int i = 1; i <= numtests; i++) {
        setTestCase(i);

        string num = inf.readWord();
        inf.readEoln();

        ensuref(num.length() <= 8, "number should be less than 8 chars long");

        for (char ch : num) {
            if (!isalnum(ch) || (ch < '0' || (ch > '9' && ch < 'A') || ch > 'F')) {
                ensuref(false, "number contains invalid chars"); // Character is not a valid hex character
            }
        }
    }

    inf.readEof();
    return 0;
}