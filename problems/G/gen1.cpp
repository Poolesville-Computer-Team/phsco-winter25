#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    // getting the options 
    int t = opt<int>("t");

    cout << t << "\n";
    
    for (int i = 1; i <= t; i++) {
        cout << i << endl;
    }
    
    return 0;
}