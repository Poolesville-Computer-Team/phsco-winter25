#include "testlib.h"
using namespace std;

const int max_hp = 15'400;
const int max_dmg = 10'000;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int a = inf.readInt(1, max_hp, "a");
    inf.readEoln();
    int b = inf.readInt(1, max_dmg, "b");
    inf.readEoln();
    int c = inf.readInt(1, max_hp, "c");
    inf.readEoln();
    int d = inf.readInt(1, max_dmg, "d");
    inf.readEoln();

    inf.readEof();
    return 0;
}