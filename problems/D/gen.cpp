#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    // getting the options 
    int ac = opt<int>("max_hp");
    int bd = opt<int>("max_dmg");

    cout << rnd.next(1, ac) << endl;
    cout << rnd.next(1, bd) << endl;
    cout << rnd.next(1, ac) << endl;
    cout << rnd.next(1, bd) << endl;
    
    return 0;
}