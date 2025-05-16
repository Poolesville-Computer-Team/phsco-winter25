#include "testlib.h"
#include <iostream>

using namespace std;

void writeTest(int test, int n) {
    startTest(test);
    cout << rnd.next(1, n) << endl;
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int numTests = atoi(argv[1]);
    int maxNum = atoi(argv[2]);
    for (int i = 1; i <= numTests; i++) writeTest(i, maxNum);
}