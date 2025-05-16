#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    string cmd = inf.readLine("echo [^ ]+", "command");

    setTestCase(1);
    ensuref(cmd.length() >= 6, "command should be at least 6 chars long");

    inf.readEof();
    return 0;
}