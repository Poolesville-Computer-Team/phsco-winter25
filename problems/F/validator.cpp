#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int max_testcases = 1'000;

void verify(int n) {
    vector<bool> x(n);
    vector<bool> y(n);

    for (int i = 0; i < n; i++) {
        string s = inf.readString();
        ensuref(s.length() == n, "length of row is not n");
        
        int numX = 0;
        int numY = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == 'X') {
                numX++;
                ensuref(!x[i], "no duplicates per column");
                x[i] = true;
            } else if (ch == 'Y') {
                numY++;
                ensuref(!y[i], "no duplicates per column");
                y[i] = true;
            } 
        }

        ensuref(numX <= 1, "at most one X per row");
        ensuref(numY <= 1, "at most one Y per row");
    }

    int numX = 0;
    int numY = 0;

    for (int i = 0; i < n; i++) {
        if (!x[i]) numX++;
        if (!y[i]) numY++;
    }

    ensuref((numX == 1 && numY == 2) || (numX == 2 && numY == 1) || (numX == 2 && numY == 2), "impossible to determine");
}

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int numtests = inf.readInt(1, max_testcases, "num-tests");
    inf.readEoln();

    for (int i = 1; i <= numtests; i++) {
        setTestCase(i);
        int n = inf.readInt(2, 100, "a");        
        inf.readEoln();

        verify(n);
    }

    inf.readEof();
    return 0;
}   