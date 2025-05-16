#include "testlib.h"
#include <set>
#include <cctype>

using namespace std;

const int max_testcases = 100;
const int min_coord = -1000;
const int max_coord = 1000;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int numtests = inf.readInt(1, max_testcases, "num-tests");
    inf.readEoln();

    for (int i = 1; i <= numtests; i++) {
        setTestCase(i);

        int a, b, c, d;
        a = inf.readInt(min_coord, max_coord, "a");
        inf.readSpace();
        b = inf.readInt(min_coord, max_coord, "b");
        inf.readSpace();
        c = inf.readInt(min_coord, max_coord, "c");
        inf.readSpace();
        d = inf.readInt(min_coord, max_coord, "d");
        inf.readEoln();
    }

    inf.readEof();
    return 0;
}