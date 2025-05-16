#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    
    // getting the options 
    int n = opt<int>("n");
    int slen = opt<int>("slen");
    
    cout << n << endl;

    for (int i = 0; i < n; i++) {
        int a, b;
        if (i == 0) {
            a = 0;
            b = slen - 1;
        } else if (i == 1) {
            a = slen - 1;
            b = 0;
        } else {
            a = rnd.next(1, slen - 2);
            b = slen - a - 1;
        }

        cout << a << " " << b << endl;

        for (int j = 0; j < slen; j++) {
            cout << rnd.next(0, 1);
        }
        cout << endl;
    }
    
    return 0;
}