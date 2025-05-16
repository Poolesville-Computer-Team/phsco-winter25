#include "testlib.h"
using namespace std;

const int max_assignments = 100'000;
const long long max_score = 1'000'000'000;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    setTestCase(1);
    
    int numasn = inf.readInt(1, max_assignments, "num-assignments");
    inf.readSpace();
    long long finalscore = inf.readLong(1, max_score, "final-score");
    long long totalscore = finalscore;
    inf.readEoln();

    for (int i = 0; i < numasn; i++) {
        long long a, b;
        a = inf.readLong(0, max_score, "a");
        inf.readSpace();
        b = inf.readLong(1, max_score, "b");
        ensuref(a <= b, "a should be <= b");

        totalscore += b;
        inf.readEoln();
    }

    ensuref(totalscore <= max_score, "max score should be below 10^9");

    inf.readEof();
    return 0;
}