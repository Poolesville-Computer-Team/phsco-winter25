#include "testlib.h"
using namespace std;

const int max_testcases = 1'000;
const int max_n = 1'000'000;
const int max_q = 100;
const int max_faces = 100;
const int max_queryval = 1'000'000'000;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int numtests = inf.readInt(1, max_testcases, "num-tests");
    inf.readEoln();

    int sum_n = 0;

    for (int i = 1; i <= numtests; i++) {
        setTestCase(i);

        int n = inf.readInt(1, max_n, "max-n");
        inf.readSpace();
        int q = inf.readInt(1, max_q, "max-q");
        inf.readEoln();
        sum_n += n;

        inf.readInts(n, 1, max_faces, "a");
        inf.readEoln();

        for (int j = 0; j < q; j++) {
            int s = inf.readInt(1, max_queryval, "s");
            inf.readEoln();
        }
    }

    ensuref(sum_n <= max_n, "sum of n must not exceed max_n");

    inf.readEof();
    return 0;
}