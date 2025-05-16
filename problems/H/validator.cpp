#include "testlib.h"

using namespace std;

const int max_testcases = 1'000;
const int max_ab = 1'000'000;
const int max_sum_slen = 1'000'001;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int numtests = inf.readInt(1, max_testcases, "num-tests");
    inf.readEoln();
    int sum_slen = 0;

    for (int i = 1; i <= numtests; i++) {
        setTestCase(i);
        int a = inf.readInt(0, max_ab, "a");
        inf.readSpace();
        int b = inf.readInt(0, max_ab, "b");
        inf.readEoln();

        string s = inf.readString("[0-1]+", "s");
        sum_slen += s.length();

        ensuref(s.length() == a + b + 1, "bitstring length should be a + b + 1");

        for (char ch : s) {
            if (!(ch == '0' || ch == '1')) {
                ensuref(false, "number contains invalid chars"); // Character is not a valid hex character
            }
        }
    }

    inf.readEof();

    ensuref(sum_slen <= max_sum_slen, "sum of slens should not exceed 10^6 + 1");

    return 0;
}   