#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    // getting the options 
    int n = opt<int>("n");
    int maxabcd = opt<int>("maxabcd");
    
    cout << n << endl;

    for (int i = 0; i < n; i++) {
        int a = rnd.next(-1 * maxabcd, 1 * maxabcd);
        int b = rnd.next(-1 * maxabcd, 1 * maxabcd);
        int c = rnd.next(-1 * maxabcd, 1 * maxabcd);
        int d = rnd.next(-1 * maxabcd, 1 * maxabcd);
        cout << a << " " << b << " " << c << " " << d << endl;
    }
    
    return 0;
}