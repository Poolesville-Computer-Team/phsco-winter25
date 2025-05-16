#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int max_testcases = 1'000'000;
const long long max_n = 1'000'000'000'000'000'000;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int numtests = inf.readInt(1, max_testcases, "num-tests");
    inf.readEoln();

    for (int i = 1; i <= numtests; i++) {
        setTestCase(i);
        long n = inf.readLong(1, max_n, "n");        
        inf.readEoln();
    }

    inf.readEof();
    return 0;
}   