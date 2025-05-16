#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int a = inf.readInt(1, 100, "x");
    inf.readEoln();
    inf.readEof();
    return 0;
}